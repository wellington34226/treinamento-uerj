// Definir o pinos do receptor e transmissor e velocidade de comunicação
#ifndef DEFINICOES_H
#define DEFINICOES_H

#define PINO_RECEPTOR 11
#define PINO_TRNASMISSOR 12
#define VELOCIDADE_WIFI 4000
#define MENSAGEM 10 // tamanho das mensagens em bytes
#define TRANSMISSOR /*RECEPTOR*/

#include <Arduino.h>

float digitalToVolts(uint16_t digital);
uint16_t voltsToDigital(float volts);

#endif /* DEFINICOES_H */