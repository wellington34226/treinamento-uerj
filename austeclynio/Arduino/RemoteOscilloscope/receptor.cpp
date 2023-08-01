#include "Arduino.h"
#include "receptor.h"

#ifdef RECEPTOR

#include <Wire.h>

// Inicialização dos atributos estáticos
RH_ASK Receptor::m_receptor(VELOCIDADE_WIFI,PINO_RECEPTOR,PINO_TRNASMISSOR);//objeto para comunicação sem fio
Adafruit_SSD1306 Receptor::m_tela(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, OLED_RESET);// objeto para utilização da tela
uint8_t Receptor::Receptor::m_estados = 0;
uint8_t Receptor::m_dados[MENSAGEM];
uint8_t Receptor::m_tamanho = 0;
uint16_t Receptor::m_entradas[GRAFICOS];
uint8_t Receptor::m_graficos[GRAFICOS][GLARGURA];

// espaçamento horizontal do eixo vertical | largura do TIC do eixo vertical | espaçamento vertical do eixo vertical | largura da área do gráfico em pixels | altura da área do gráfico em pixels
static const uint8_t PROGMEM parametros[] = {VLARGURA,TLARGURA,VALTURA,GLARGURA,SCREEN_HEIGHT-VALTURA-1};// parâmetros dos gráficos
uint8_t eixoxi = 0, eixoxf = 0; //posições inicial e final do eixo X
uint8_t largura_grafico = 0;    // largura atual do gráfico
unsigned int milissegundos = 0; // temporizador em milissegundos
unsigned int segundos      = 0; // temporizador em segundos

Receptor::Receptor(){};
Receptor::~Receptor(){};
void Receptor::init(void){
  if((Receptor::m_estados & 0b00000001) == 0){
    for(int indice=0;indice<MENSAGEM;indice++){
      Receptor::m_dados[indice] = 0x00;
    }
    if(Receptor::m_receptor.init()){
      Receptor::m_estados |= 0b00000001;// ativa a flag indicando que o receptor foi iniciado
      Serial.print(F("Receptor iniciado com velocidade de "));
      Serial.print(Receptor::m_receptor.speed(),DEC);
      Serial.println(F("bps"));
    }else{
      Serial.println(F("Não foi possivel iniciar o receptor"));
      Serial.println(F("Por favor reinicie e tente novamente"));
    }
  }
  if((Receptor::m_estados & 0b00000010) == 0){
    for(uint8_t grafico = 0;grafico < GRAFICOS; grafico++){
      for(uint8_t x = 0;x < GLARGURA;x++) {
        Receptor::m_graficos[grafico][x] = 0;
      }
    }
    if(Receptor::m_tela.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS)) {
      //Memória livre mínima 624bytes para criação do buffer
      Receptor::m_estados |= 0b00000010;// ativa a flag indicando que a tela foi iniciada
      Receptor::m_tela.clearDisplay();//limpa display
      Receptor::m_tela.display();//atualiza display
      configurarTimer();
      Serial.println(F("Display iniciado com sucesso"));
    }else{
      Serial.println(F("Não foi possivel iniciar o display"));
      Serial.println(F("Por favor reinicie e tente novamente"));
    }
  }
};
void Receptor::loop(void){
  Receptor::receberDados();
  Receptor::atualizarTela();
};
void Receptor::receberDados(void){
  if((Receptor::m_estados & 0b00000001) == 0){
    for(int indice=0;indice<MENSAGEM;indice++){
      Receptor::m_dados[indice] = 0x00;
    }
    if(Receptor::m_receptor.init()){
      Receptor::m_estados |= 0b00000001;// ativa a flag indicando que o receptor foi iniciado
      Serial.println(F("Receptor iniciado com sucesso"));
      // se receptor iniciado com suscesso  executa rotina de obtenção dos dados
      // Checa se alguma mensagem chegou
      Receptor::m_tamanho = sizeof(Receptor::m_dados);// tamanho máximo do buffer
      if(Receptor::m_receptor.recv(Receptor::m_dados,&Receptor::m_tamanho)){
        atualizarDados();
      }
    }else{
      Serial.println(F("Não foi possivel iniciar o receptor"));
      Serial.println(F("Por favor reinicie e tente novamente"));
    }
  }else{
    Receptor::m_tamanho = sizeof(Receptor::m_dados);// tamanho máximo do buffer
    if(Receptor::m_receptor.recv(Receptor::m_dados,&Receptor::m_tamanho)){
      atualizarDados();
    }
  }
};
void Receptor::atualizarDados(void){
  if(Receptor::m_tamanho>1){
    // canal analágico A0
    Receptor::m_entradas[0] = Receptor::m_dados[0];
    Receptor::m_entradas[0] = Receptor::m_entradas[0] << 8;
    Receptor::m_entradas[0] |= Receptor::m_dados[1];
    Receptor::m_graficos[0][eixoxf] = SCREEN_HEIGHT-1-map(Receptor::m_entradas[0],0,1023,0,parametros[4]);
  }
  if(Receptor::m_tamanho>3){
    // canal analágico A1
    Receptor::m_entradas[1] = Receptor::m_dados[2];
    Receptor::m_entradas[1] = Receptor::m_entradas[1] << 8;
    Receptor::m_entradas[1] |= Receptor::m_dados[3];
    Receptor::m_graficos[1][eixoxf] = SCREEN_HEIGHT-1-map(Receptor::m_entradas[1],0,1023,0,parametros[4]);
  }
  if(Receptor::m_tamanho>5){
    // canal analágico A2
    Receptor::m_entradas[2] = Receptor::m_dados[4];
    Receptor::m_entradas[2] = Receptor::m_entradas[2] << 8;
    Receptor::m_entradas[2] |= Receptor::m_dados[5];
    Receptor::m_graficos[2][eixoxf] = SCREEN_HEIGHT-1-map(Receptor::m_entradas[2],0,1023,0,parametros[4]);
  }
  if(largura_grafico < parametros[3]){
    largura_grafico++;// aumenta a largura utilizada do gráfico
  }else{
    eixoxi = (eixoxi+1) % parametros[3];// desloca o gráfico para a direita
  }
  eixoxf = (eixoxf+1) % parametros[3];
  imprimirMensagem();
};
void Receptor::atualizarTela(void) {
  if((Receptor::m_estados & 0b00000010) && (Receptor::m_estados & 0b00000100)){
    Receptor::desativarAtualizacao();
    Receptor::m_tela.clearDisplay();
    Receptor::m_tela.setTextSize(1);
    Receptor::m_tela.setTextColor(WHITE);
    Receptor::m_tela.setCursor(50,0);
    Receptor::m_tela.cp437(true);
    Receptor::m_tela.print(F("A"));
    Receptor::m_tela.print(Receptor::m_estados >> 4,DEC);
    Receptor::m_tela.print(F(" = "));
    if(Receptor::m_estados & 0b00001000){
      Receptor::m_tela.println(digitalToVolts(Receptor::m_entradas[Receptor::m_estados >> 4]),2);
    }else{
      Receptor::m_tela.println(Receptor::m_entradas[Receptor::m_estados >> 4],DEC);
    }
    Receptor::m_tela.drawFastVLine(parametros[0],parametros[2],parametros[4],WHITE);// deselha linha do eixo vertical
    Receptor::m_tela.drawFastHLine(parametros[0]-parametros[1],parametros[2],parametros[1],WHITE);// desenha linha horizontal do valor máximo
    Receptor::m_tela.drawFastHLine(parametros[0]-parametros[1],(SCREEN_HEIGHT-1+parametros[2])/2,parametros[1],WHITE);// desenha linha horizontal do valor médio
    Receptor::m_tela.drawFastHLine(parametros[0]-parametros[1],SCREEN_HEIGHT-1,parametros[1],WHITE);// desenha linha horizontal do valor mínimo
    uint8_t gap = parametros[4]/10;
    uint8_t ticy = parametros[2];
    // desenha 4 linhas horizontais a partir do valor máximo
    for(uint8_t i = 0;i<5;i++){
      ticy += gap;
      Receptor::m_tela.drawFastHLine(parametros[0]-(parametros[1]/2),ticy,parametros[1]/2,WHITE);
    }
    ticy = (SCREEN_HEIGHT-1+parametros[2])/2;
    // desenha 4 linhas horizontais a partir do valor médio
    for(uint8_t i = 0;i<5;i++){
      ticy += gap;
      Receptor::m_tela.drawFastHLine(parametros[0]-(parametros[1]/2),ticy,parametros[1]/2,WHITE);
    }
    // coloca os textos no eixo Y
    if(Receptor::m_estados & 0b00001000){
      Receptor::m_tela.println(F("5.00"));
      Receptor::m_tela.println(F("2.50"));
      Receptor::m_tela.println(F("0.00"));
    }else{
      Receptor::m_tela.println(F("1023"));
      Receptor::m_tela.println(F(" 512"));
      Receptor::m_tela.println(F("   0"));
    }
    // Desenhando gráfico    
    // percorre a lista de valores do gráfico correspondente
    uint8_t xa = 0,ya = 0;// mantém os valores de x e y anteriores
    for(uint8_t indice = 0 ; indice < largura_grafico; indice++){
      uint8_t x  = indice + parametros[0]+GAPGRAFICO;
      uint8_t y  = Receptor::m_graficos[Receptor::m_estados >> 4][(indice+eixoxi) % parametros[3]];
      if(indice > 0){
        Receptor::m_tela.drawLine(xa,ya,x,y,WHITE);
      }
      xa = x;
      ya = y;
    }
    Receptor::m_tela.display();
  }
};
void Receptor::imprimirMensagem(void){
  Serial.print(F("{"));
  Serial.print(F("\"A0\":"));
  Serial.print(Receptor::m_entradas[0],DEC);
  Serial.print(F(",\"A1\":"));
  Serial.print(Receptor::m_entradas[1],DEC);
  Serial.print(F(",\"A2\":"));
  Serial.print(Receptor::m_entradas[2],DEC);
  Serial.print(F(",\"recebidos\":["));
  if(Receptor::m_tamanho>0){
    Serial.print(F("0x"));
    if(Receptor::m_dados[0] < 16){
      Serial.print(F("0"));
    }
    Serial.print(Receptor::m_dados[0],HEX);
    for(int indice=1;indice < Receptor::m_tamanho;indice++){
      Serial.print(F(",0x"));
      if(Receptor::m_dados[indice] < 16){
        Serial.print(F("0"));
      }
      Serial.print(Receptor::m_dados[indice],HEX);
    }
  }else{
    Serial.print(F(" "));
  }
  Serial.println(F("]}"));
};
void Receptor::ativarAtualizacao(void){
  if((Receptor::m_estados & 0b00000010)){
    Receptor::m_estados |= 0b00000100;//ativa flag indicando que a tela pode ser atualizada
  }
};
void Receptor::desativarAtualizacao(void){
  Receptor::m_estados &= 0b11111011;//desativa flag indicando que tela foi atualizada
};
void Receptor::trocarGrafico(void){
  uint8_t grafico = Receptor::m_estados >> 4;//recupera as flags indicativas das saídas analógicas
  Receptor::m_estados &= 0b00001111;//zera as flags indicativas das saídas analógicas
  grafico++;
  if(grafico < GRAFICOS){
    Receptor::m_estados |= grafico << 4;
  }else{
    Receptor::m_estados ^= 0b00001000;//inverte a flag indicativa do tipo de gráfico
  }
};
void configurarTimer(void){
  //Timer operando em modo CTC e Com saídas OC1A e OC1B desconectadas
  //Compare Output Mode COM1A = 00 e WGM = 12 = 0xC
  //TIMER COUNTER CONTROL REGISTER A >>>  COM2A|COM2A|COM2B|COM2B|     |     |WGM21|WGM20
  TCCR2A  = 0x02;//Modo CTC          >>>    0  |  0  |  0  |  0  |  0  |  0  |  1  |  0
  //TIMER COUNTER CONTROL REGISTER B >>>  FOC2A|FOC2B|     |     |WGM22| CS22| CS21| CS20
  TCCR2B  = 0x05;// Prescaler 128    >>>    0  |  0  |  0  |  0  |  0  |  1  |  0  |  1
  //Definindo valor limite para comparação
  OCR2B  = 0x7D;//contagem -->> (125*128*62,5)/1000000000 = 1ms
  TCNT2  = 0x00;//iniciando contador
  //TIMER INTERRUPTION MASK          >>>       |     |     |     |     |OCIEB|OCIEA| TOIE
  TIMSK2 = 0b00000100;//Habilita interrupção do Comparador da Saída B
};
ISR(TIMER2_COMPB_vect){
  TCNT2 = 0x0000;// Reinicializa o registrador do Timer2
  milissegundos++;
  if(milissegundos >= 1000){
    segundos++;
    milissegundos = 0;
    if(segundos >= INTERVALO){
      segundos = 0;
      if(largura_grafico > 0){
        Receptor::trocarGrafico();// troca de gráfico a cada INTERVALO em segundos
      }
    }
  }
  if(largura_grafico > 0){
    Receptor::ativarAtualizacao();// atualiza a tela a cada milissegundo
  }
}
#endif