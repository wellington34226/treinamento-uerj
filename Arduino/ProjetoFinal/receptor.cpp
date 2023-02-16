#include "receptor.h"

#ifdef RECEPTOR

// Inicialização dos atributos estáticos
RH_ASK Receptor::m_receptor(VELOCIDADE_WIFI,PINO_RECEPTOR,PINO_TRNASMISSOR);
uint8_t Receptor::m_estados = 0;
uint8_t Receptor::m_dados[RH_ASK_MAX_MESSAGE_LEN];
uint8_t Receptor::m_tamanho = 0;
Adafruit_SSD1306 Receptor::m_tela(LARGURA,ALTURA, &Wire, REINICIA_TELA);
String Receptor::m_texto = "PROGRAMA INICIADO";
uint8_t Receptor::m_graficos[GRAFICOS][LARGURA];

Receptor::Receptor(){};
Receptor::~Receptor(){};

void Receptor::init(void){
  if((m_estados & 0b00000001) == 0){
    for(int indice=0;indice<RH_ASK_MAX_MESSAGE_LEN;indice++){
      Receptor::m_dados[indice] = 0x00;
    }
    if(Receptor::m_receptor.init()){
      m_estados |= 0b00000001;// ativa a flag indicando que o receptor foi iniciado
      Serial.print("Receptor iniciado com velocidade de ");
      Serial.print(Receptor::m_receptor.speed(),DEC);
      Serial.println("bps");
    }else{
      Serial.println("Não foi possivel iniciar o receptor");
      Serial.println("Por favor reinicie e tente novamente");
    }
  }
  if((m_estados & 0b00000010) == 0){
    for(int linha=0; linha < GRAFICOS;linha++) {
      for(int coluna=0;coluna < LARGURA;coluna++) {
        Receptor::m_graficos[linha][coluna] = 0x00;
      }
    }
    if(ALTURA==32 || ALTURA==64){
      if(Receptor::m_tela.begin(SSD1306_SWITCHCAPVCC,ALTURA==32?0x3C:0x3D)) {
        m_estados |= 0b00000010;// ativa a flag indicando que a tela foi iniciada
        Receptor::m_tela.clearDisplay();
        Receptor::m_tela.setTextSize(1);
        Receptor::m_tela.setCursor(0,0);
        Receptor::m_tela.setTextColor(WHITE);
        Receptor::m_tela.println(Receptor::m_texto);
        Receptor::m_tela.display();
        Serial.println("Display iniciado com sucesso");
      }else{
        Serial.println("Não foi possivel iniciar o display");
        Serial.println("Por favor reinicie e tente novamente");
      }
    }else{
      Serial.println("Altura " + String(ALTURA) + " não suportada");
    }
  }
};
void Receptor::loop(void){
  Receptor::receberDados();
  if(Receptor::m_tamanho>0){
    Receptor::atualizarTela();
  }
};
void Receptor::receberDados(void){
  if((m_estados & 0b00000001) == 0){
    for(int indice=0;indice<RH_ASK_MAX_MESSAGE_LEN;indice++){
      Receptor::m_dados[indice] = 0x00;
    }
    if(Receptor::m_receptor.init()){
      m_estados |= 0b00000001;// ativa a flag indicando que o receptor foi iniciado
      Serial.println("Receptor iniciado com sucesso");
      // se receptor iniciado com suscesso  executa rotina de obtenção dos dados
      // Checa se alguma mensagem chegou
      Receptor::m_tamanho = sizeof(Receptor::m_dados);// tamanho máximo do buffer
      if(Receptor::m_receptor.recv(Receptor::m_dados,&Receptor::m_tamanho)){
        int tripot = 0, ldr = 0, pwm = 0;
        // canal analágico A0
        tripot = Receptor::m_dados[0];
        tripot = tripot << 8;
        tripot |= Receptor::m_dados[1];
        imprimirMensagem();
      }
    }else{
      Serial.println("Não foi possivel iniciar o receptor");
      Serial.println("Por favor reinicie e tente novamente");
    }
  }else{
    Receptor::m_tamanho = sizeof(Receptor::m_dados);// tamanho máximo do buffer
    if(Receptor::m_receptor.recv(Receptor::m_dados,&Receptor::m_tamanho)){
      imprimirMensagem();
    }
  }

};
void Receptor::atualizarTela(void) {
  int tripot = 0, ldr = 0, pwm = 0;
  if((m_estados & 0b00000010) == 0){
    for(int linha=0; linha < GRAFICOS;linha++) {
      for(int coluna=0;coluna < LARGURA;coluna++) {
        Receptor::m_graficos[linha][coluna] = 0x00;
      }
    }
    if(ALTURA==32 || ALTURA==64){
      if(Receptor::m_tela.begin(SSD1306_SWITCHCAPVCC,ALTURA==32?0x3C:0x3D)) {
        // se display iniciado executa rotina de atualização da tela
        m_estados |= 0b00000010;// ativa a flag indicando que a tela foi iniciada
        Receptor::m_tela.clearDisplay();
        Receptor::m_tela.setTextSize(1);
        Receptor::m_tela.setTextColor(WHITE);
        Receptor::m_tela.setCursor(0,0);
        Receptor::m_tela.cp437(true);
        // canal analágico A0
        tripot = Receptor::m_dados[0];
        tripot = tripot << 8;
        tripot |= Receptor::m_dados[1];
      // canal analágico A1
        ldr = Receptor::m_dados[2];
        ldr = ldr << 8;
        ldr |= Receptor::m_dados[3];
      // canal analágico A2
        pwm = Receptor::m_dados[4];
        pwm  = pwm << 8;
        pwm |= Receptor::m_dados[5];
        m_texto = "A0=" + String(tripot,DEC);
        Receptor::m_tela.println(Receptor::m_texto);
        m_texto = "A1=" + String(ldr,DEC);
        Receptor::m_tela.println(Receptor::m_texto);
        m_texto = "A2=" + String(pwm,DEC);
        Receptor::m_tela.println(Receptor::m_texto);
        Receptor::m_tela.display();
      }else{
        Serial.println("Não foi possivel iniciar o display");
        Serial.println("Por favor reinicie e tente novamente");
      }
    }else{
      Serial.println("Altura " + String(ALTURA) + " não suportada");
    }
  }else{
    Receptor::m_tela.clearDisplay();
    Receptor::m_tela.setTextSize(1);
    Receptor::m_tela.setTextColor(WHITE);
    Receptor::m_tela.setCursor(0,0);
    Receptor::m_tela.cp437(true);
    // canal analágico A0
    tripot = Receptor::m_dados[0];
    tripot = tripot << 8;
    tripot |= Receptor::m_dados[1];
  // canal analágico A1
    ldr = Receptor::m_dados[2];
    ldr = ldr << 8;
    ldr |= Receptor::m_dados[3];
  // canal analágico A2
    pwm = Receptor::m_dados[4];
    pwm  = pwm << 8;
    pwm |= Receptor::m_dados[5];
    m_texto = "A0=" + String(tripot,DEC);
    Receptor::m_tela.println(Receptor::m_texto);
    m_texto = "A1=" + String(ldr,DEC);
    Receptor::m_tela.println(Receptor::m_texto);
    m_texto = "A2=" + String(pwm,DEC);
    Receptor::m_tela.println(Receptor::m_texto);
    Receptor::m_tela.display();
  }
};
void Receptor::imprimirMensagem(void){
  Serial.print("Recebidos:");
  for(int indice=0;indice < Receptor::m_tamanho;indice++){
    Serial.print(" 0x");
    if(Receptor::m_dados[indice] < 16){
      Serial.print("0");
    }
    Serial.print(Receptor::m_dados[indice],HEX);
  }
  Serial.println("");
};
#endif