#include "transmissor.h"

#ifdef TRANSMISSOR
// Inicialização dos atributos estáticos
RH_ASK Transmissor::m_trasmissor(VELOCIDADE_WIFI,PINO_RECEPTOR,PINO_TRNASMISSOR);
uint8_t Transmissor::Transmissor::m_estados = 0;
uint8_t Transmissor::m_dados[MENSAGEM];// buffer com o tamanho máximo permitido para envio
uint8_t Transmissor::m_tamanho = 0;
const uint8_t Transmissor::m_pwmOutPino = 3;
const uint8_t Transmissor::m_tripotPino = A0;
const uint8_t Transmissor::m_ldrPino    = A1;
const uint8_t Transmissor::m_pwmInPino  = A2;
uint16_t Transmissor::m_entradas[] = {0,0,0}; // inicia 3 entradas analógicas a serem monitoradas

uint8_t pwm = 0; // valor do dutycycle para o pulso PWM
unsigned long stampPwm = 0;

Transmissor::Transmissor(){};
Transmissor::~Transmissor(){};
void Transmissor::init(void){
  if((Transmissor::m_estados & 0b00000001) == 0){
    for(int indice=0;indice<MENSAGEM;indice++){
      Transmissor::m_dados[indice] = 0x00;
    }
    if(Transmissor::m_trasmissor.init()){
      Transmissor::m_estados |= 0b00000001;// ativa flag indicando que o transmissor foi iniciado
      Serial.print(F("Transmissor iniciado com velocidade de "));
      Serial.print(Transmissor::m_trasmissor.speed(),DEC);
      Serial.println(F("bps"));
    }else{
      Serial.println(F("Não foi possivel iniciar o transmissor"));
      Serial.println(F("Por favor reinicie e tente novamente"));
    }
  }
  if((Transmissor::m_estados & 0b00000010) == 0){
    pinMode(Transmissor::m_pwmOutPino,OUTPUT);
    Transmissor::m_estados |= 0b00000010;// ativa flag indicando que o pino de saída PWM foi configurado
  }
  if((Transmissor::m_estados & 0b00000100) == 0){
    pinMode(Transmissor::m_tripotPino,INPUT);
    Transmissor::m_estados |= 0b00000100;// ativa flag indicando que o pino do tripot (entrada analógica) foi configurado
  }
  if((Transmissor::m_estados & 0b00001000) == 0){
    pinMode(Transmissor::m_ldrPino,INPUT);
    Transmissor::m_estados |= 0b00001000;// ativa flag indicando que o pino do LDR (entrada analógica) foi configurado
  }
  if((Transmissor::m_estados & 0b00010000) == 0){
    pinMode(Transmissor::m_pwmInPino,INPUT);
    Transmissor::m_estados |= 0b00010000;// ativa flag indicando que o pino de entrada do sinal PWM (entrada analógica) foi configurado
  }
  analogWrite(Transmissor::m_pwmOutPino,map(pwm,0,100,0,255));
  stampPwm = millis();
};
void Transmissor::loop(void){
  Transmissor::enviarDados();
  if((millis()-stampPwm) >= INTERVALO*1000){
    if((Transmissor::m_estados & 0b00000010) == 0){
      pinMode(Transmissor::m_pwmOutPino,OUTPUT);
      Transmissor::m_estados |= 0b00000010;// ativa flag indicando que o pino de saída PWM foi configurado
    }else{
      pwm = (pwm+1) % 100;
    }
    analogWrite(Transmissor::m_pwmOutPino,map(pwm,0,100,0,255));
    stampPwm = millis();
  }
};
void Transmissor::atualizarDados(void){
 if((Transmissor::m_estados & 0b00000100) == 0){
    pinMode(Transmissor::m_tripotPino,INPUT);
    Transmissor::m_estados |= 0b00000100;// ativa flag indicando que o pino do tripot (entrada analógica) foi configurado
  }
  if((Transmissor::m_estados & 0b00001000) == 0){
    pinMode(Transmissor::m_ldrPino,INPUT);
    Transmissor::m_estados |= 0b00001000;// ativa flag indicando que o pino do LDR (entrada analógica) foi configurado
  }
  if((Transmissor::m_estados & 0b00010000) == 0){
    pinMode(Transmissor::m_pwmInPino,INPUT);
    Transmissor::m_estados |= 0b00010000;// ativa flag indicando que o pino de entrada do sinal PWM (entrada analógica) foi configurado
  }
  Transmissor::m_entradas[0] = analogRead(Transmissor::m_tripotPino);
  Transmissor::m_entradas[1] = analogRead(Transmissor::m_ldrPino);
  Transmissor::m_entradas[2] = analogRead(Transmissor::m_pwmInPino);
  Transmissor::m_tamanho = 0;
  // canal analágico A0
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[0] >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[0];
  Transmissor::m_tamanho++;
  // canal analágico A1
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[1] >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[1] ;
  Transmissor::m_tamanho++;
  // canal analágico A2
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[2] >> 8;
  Transmissor::m_tamanho++;
  Transmissor::m_dados[Transmissor::m_tamanho] = Transmissor::m_entradas[2] ;
  Transmissor::m_tamanho++;
};
void Transmissor::enviarDados(void){
  Transmissor::atualizarDados();
  if(Transmissor::m_tamanho > 0){
    if((Transmissor::m_estados & 0b00000001) == 0){
      if(Transmissor::m_trasmissor.init()){
        Transmissor::m_estados |= 0b00000001;// ativa flag indicando que o transmissor foi iniciado
        Serial.println(F("Transmissor iniciado com sucesso"));
        if(Transmissor::m_trasmissor.send(Transmissor::m_dados,Transmissor::m_tamanho)){
          if(!Transmissor::m_trasmissor.waitPacketSent()){
            Transmissor::m_tamanho = 0;
          }
        }
      }else{
        Serial.println(F("Não foi possivel iniciar o transmissor"));
        Serial.println(F("Por favor reinicie e tente novamente"));
      }
    }else{
      if(Transmissor::m_trasmissor.send(Transmissor::m_dados,Transmissor::m_tamanho)){
        if(!Transmissor::m_trasmissor.waitPacketSent()){
          Transmissor::m_tamanho = 0;
        }
      }
    }
  }
  Transmissor::imprimirMensagem();
};
void Transmissor::imprimirMensagem(void){
  Serial.print(F("{"));
  Serial.print(F("\"A0\":"));
  Serial.print(Transmissor::m_entradas[0],DEC);
  Serial.print(F(",\"A1\":"));
  Serial.print(Transmissor::m_entradas[1],DEC);
  Serial.print(F(",\"A2\":"));
  Serial.print(Transmissor::m_entradas[2],DEC);
  Serial.print(F(",\"PWM\":"));
  Serial.print(pwm,DEC);
  Serial.print(F(",\"enviados\":["));
  if(Transmissor::m_tamanho>0){
    Serial.print(F("0x"));
    if(Transmissor::m_dados[0] < 16){
      Serial.print(F("0"));
    }
    Serial.print(Transmissor::m_dados[0],HEX);
    for(int indice=1;indice < Transmissor::m_tamanho;indice++){
      Serial.print(F(",0x"));
      if(Transmissor::m_dados[indice] < 16){
        Serial.print(F("0"));
      }
      Serial.print(Transmissor::m_dados[indice],HEX);
    }
  }else{
    Serial.print(F(" "));
  }
  Serial.println(F("]}"));
};
#endif