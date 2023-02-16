/* Lendo dados da seriais */

#include <Arduino.h>
// Pinos de controle
short int ledVerdePino    = 2;
short int ledVermelhoPino = 3;
short int ledAmareloPino  = 4;
short int rgbVermelhoPino = 9;
short int rgbVerdePino    = 10;
short int rgbAzulPino     = 11;
//Estados (Acesso ou Apagado)
short int ledVerdeEstado    = HIGH;
short int ledAmareloEstado  = LOW;
short int ledVermelhoEstado = LOW;
//Temporiazadores para mudança de estado
long int tempoBase        = 1000;//para controlar o multiplicador dos temporizadores (em segundos)
long int ledVerdeTempo    = 60*tempoBase;
long int ledAmareloTempo  = 10*tempoBase;
long int ledVermelhoTempo = 30*tempoBase;
//Carimbos de tempo data e hora da ultima modificação de estado
long int ledVerdeStamp    = 0;
long int ledAmareloStamp  = 0;
long int ledVermelhoStamp = 0;
void estadosSerial(void);
char dadoLido;
void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0){
    dadoLido = Serial.read();
    Serial.print(dadoLido);
  }
}
