#include <Arduino.h>

int tripotPino = A0;
int ldrPino    = A1;

int ledVerdePino    = 2;
int ledVermelhoPino = 3;
int ledAmareloPino  = 4;
int botaoPino       = 7;
int relePino        = 8;
int rgbVermelhoPino = 9;
int rgbVerdePino    = 10;
int rgbAzulPino     = 11;

int ledVerdeEstado    = 0;
int ledVermelhoEstado = 0;
int ledAmareloEstado  = 0;
int rgbVermelhoEstado = 0;
int rgbVerdeEstado    = 0;
int rgbAzulEstado     = 0;

int tempoBase = 10;

int ledVerdeTempo    = 100;
int ledVermelhoTempo = 50;
int ledAmareloTempo  = 10;
int rgbVermelhoTempo = 10;
int rgbVerdeTempo    = 50;
int rgbAzulTempo     = 100;
int tripotTempo      = 25;
int ldrTempo         = 25;

long int ledVerdeStamp    = 0;
long int ledVermelhoStamp = 0;
long int ledAmareloStamp  = 0;
long int rgbVermelhoStamp = 0;
long int rgbVerdeStamp    = 0;
long int rgbAzulStamp     = 0;
long int tripotStamp      = 0;
long int ldrStamp         = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial){}
  pinMode(ledVerdePino,   OUTPUT);
  pinMode(ledVermelhoPino,OUTPUT);
  pinMode(ledAmareloPino, OUTPUT);
  pinMode(rgbVermelhoPino,OUTPUT);
  pinMode(rgbVerdePino,   OUTPUT);
  pinMode(rgbAzulPino,    OUTPUT);
  pinMode(relePino,       OUTPUT);
  pinMode(tripotPino,     INPUT);
  pinMode(ldrPino,        INPUT);
  pinMode(botaoPino,      INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  long int currentStamp = millis();
  int valor;
  if((currentStamp-ledVerdeStamp)>(tempoBase*ledVerdeTempo)){
    if(ledVerdeEstado){
      ledVerdeEstado = LOW;
    }else{
      ledVerdeEstado = HIGH;
    }
    ledVerdeStamp = currentStamp;
    digitalWrite(ledVerdePino,ledVerdeEstado);
  }
  if((currentStamp-ledVermelhoStamp)>(tempoBase*ledVermelhoTempo)){
    if(ledVermelhoEstado){
      ledVermelhoEstado = LOW;
    }else{
      ledVermelhoEstado = HIGH;
    }
    ledVermelhoStamp = currentStamp;
    digitalWrite(ledVermelhoPino,ledVermelhoEstado);
  }
  if((currentStamp-ledAmareloStamp)>(tempoBase*ledAmareloTempo)){
    if(ledAmareloEstado){
      ledAmareloEstado = LOW;
    }else{
      ledAmareloEstado = HIGH;
    }
    ledAmareloStamp = currentStamp;
    digitalWrite(ledAmareloPino,ledAmareloEstado);
  }
  if((currentStamp-tripotStamp)>(tempoBase*tripotTempo)){
    tripotStamp = currentStamp;
    valor = analogRead(tripotPino);
    valor = map(valor,0,1023,0,255);
    Serial.print("Tripot: ");
    Serial.println(valor);
    if((currentStamp-rgbVermelhoStamp)>(tempoBase*rgbVermelhoTempo)){
      rgbVermelhoStamp = currentStamp;
      analogWrite(rgbVermelhoPino,valor);
    }
    if((currentStamp-rgbVerdeStamp)>(tempoBase*rgbVerdeTempo)){
      rgbVerdeStamp = currentStamp;
      analogWrite(rgbVerdePino,valor);
    }
    if((currentStamp-rgbAzulStamp)>(tempoBase*rgbAzulTempo)){
      rgbAzulStamp = currentStamp;
      analogWrite(rgbAzulPino,valor);
    }
  }
  if((currentStamp-ldrStamp)>(tempoBase*ldrTempo)){
    ldrStamp = currentStamp;
    valor = analogRead(ldrPino);
    if(valor>800){
      digitalWrite(relePino,HIGH);
    }else if(valor<500){
      digitalWrite(relePino,LOW);
    }
    Serial.print("LDR: ");
    Serial.println(valor);
  }
}