#include "transmissor.h"

#ifdef TRANSMISSOR
// Inicialização dos atributos estáticos
RH_ASK Transmissor::m_trasmissor(VELOCIDADE_WIFI,PINO_RECEPTOR,PINO_TRNASMISSOR);
uint8_t Transmissor::m_estados = 0;
uint8_t Transmissor::m_dados[RH_ASK_MAX_MESSAGE_LEN];// buffer com o tamanho máximo permitido para envio
uint8_t Transmissor::m_tamanho = 0;
const uint8_t Transmissor::m_pwmOutPino = 3;
const uint8_t Transmissor::m_tripotPino = A0;
const uint8_t Transmissor::m_ldrPino    = A1;
const uint8_t Transmissor::m_pwmInPino  = A2;

Transmissor::Transmissor(){};
Transmissor::~Transmissor(){};
void Transmissor::init(void){
  if((m_estados & 0b00000001) == 0){
    for(int indice=0;indice<RH_ASK_MAX_MESSAGE_LEN;indice++){
      Transmissor::m_dados[indice] = 0x00;
    }
    if(Transmissor::m_trasmissor.init()){
      m_estados |= 0b00000001;// ativa flag indicando que o transmissor foi iniciado
      Serial.print("Transmissor iniciado com velocidade de ");
      Serial.print(Transmissor::m_trasmissor.speed(),DEC);
      Serial.println("bps");
    }else{
      Serial.println("Não foi possivel iniciar o transmissor");
      Serial.println("Por favor reinicie e tente novamente");
    }
  }
  if((m_estados & 0b00000010) == 0){
    pinMode(Transmissor::m_pwmOutPino,OUTPUT);
    m_estados |= 0b00000010;// ativa flag indicando que o pino de saída PWM foi configurado
  }
  if((m_estados & 0b00000100) == 0){
    pinMode(Transmissor::m_tripotPino,INPUT);
    m_estados |= 0b00000100;// ativa flag indicando que o pino do tripot (entrada analógica) foi configurado
  }
  if((m_estados & 0b00001000) == 0){
    pinMode(Transmissor::m_ldrPino,INPUT);
    m_estados |= 0b00001000;// ativa flag indicando que o pino do LDR (entrada analógica) foi configurado
  }
  if((m_estados & 0b00010000) == 0){
    pinMode(Transmissor::m_ldrPino,INPUT);
    m_estados |= 0b00010000;// ativa flag indicando que o pino do LDR (entrada analógica) foi configurado
  }
  if((m_estados & 0b00100000) == 0){
    pinMode(Transmissor::m_pwmInPino,INPUT);
    m_estados |= 0b00100000;// ativa flag indicando que o pino de entrada do sinal PWM (entrada analógica) foi configurado
  }
};
void Transmissor::loop(void){
  Transmissor::atualizarDados();
  Transmissor::enviarDados();
};
void Transmissor::atualizarDados(void){
  if((Transmissor::m_estados & 0b00111110) != 0x3E){
    if((m_estados & 0b00000010) == 0){
      pinMode(Transmissor::m_pwmOutPino,OUTPUT);
      m_estados |= 0b00000010;
    }
    if((m_estados & 0b00000100) == 0){
      pinMode(Transmissor::m_tripotPino,INPUT);
      m_estados |= 0b00000100;
    }
    if((m_estados & 0b00001000) == 0){
      pinMode(Transmissor::m_ldrPino,INPUT);
      m_estados |= 0b00001000;
    }
    if((m_estados & 0b00010000) == 0){
      pinMode(Transmissor::m_ldrPino,INPUT);
      m_estados |= 0b00010000;
    }
    if((m_estados & 0b00100000) == 0){
      pinMode(Transmissor::m_pwmInPino,INPUT);
      m_estados |= 0b00100000;
    }
  }
  int tripot = analogRead(Transmissor::m_tripotPino);
  int ldr = analogRead(Transmissor::m_ldrPino);
  analogWrite(Transmissor::m_pwmOutPino,map(ldr+tripot,0,1023*2,0,255));
  int pwm = analogRead(Transmissor::m_pwmInPino);
  Transmissor::m_tamanho = 0;
  // canal analágico A0
  Transmissor::m_dados[Transmissor::m_tamanho] = tripot >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = tripot;
  Transmissor::m_tamanho++;
  // canal analágico A1
  Transmissor::m_dados[Transmissor::m_tamanho] = ldr >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = ldr ;
  Transmissor::m_tamanho++;
  // canal analágico A2
  Transmissor::m_dados[Transmissor::m_tamanho] = pwm >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = pwm ;
  Transmissor::m_tamanho++;
  Serial.print("A0:");  
  Serial.print(tripot);
  Serial.print(" A1:");
  Serial.print(ldr);
  Serial.print(" A2:");
  Serial.println(pwm);
};
void Transmissor::enviarDados(void){
  if(Transmissor::m_tamanho > 0){
    if((m_estados & 0b00000001) == 0){
      if(Transmissor::m_trasmissor.init()){
        m_estados |= 0b00000001;// ativa flag indicando que o transmissor foi iniciado
        Serial.println("Transmissor iniciado com sucesso");
        if(Transmissor::m_trasmissor.send(Transmissor::m_dados,Transmissor::m_tamanho)){
          if(Transmissor::m_trasmissor.waitPacketSent()){
            imprimirMensagem();
          }
        }
      }else{
        Serial.println("Não foi possivel iniciar o transmissor");
        Serial.println("Por favor reinicie e tente novamente");
      }
    }else{
      if(Transmissor::m_trasmissor.send(Transmissor::m_dados,Transmissor::m_tamanho)){
        if(Transmissor::m_trasmissor.waitPacketSent()){
          imprimirMensagem();
        }
      }
    }
  }
};
void Transmissor::imprimirMensagem(void){
  Serial.print("Enviados:");
  for(int indice=0;indice < Transmissor::m_tamanho;indice++){
    Serial.print(" 0x");
    if(Transmissor::m_dados[indice] < 16){
      Serial.print("0");
    }
    Serial.print(Transmissor::m_dados[indice],HEX);
  }
  Serial.println("");
};
#endif