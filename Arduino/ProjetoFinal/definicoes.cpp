#include "definicoes.h"
float digitalToVolts(uint16_t digital){
  return (5*float(digital))/1023;
};
uint16_t voltsToDigital(float volts){
  return uint16_t((1023*volts)/5);
};

/*
** Tipos: número real, númerro inteiro ou caracter
** Inteiro com ou sem sinal
** Real float ou double
** 2 bits para tipo
** Tipo 0 caracter e tamanho define a quantidade de caracteres
** Tipo 1 real e tamanho define a precisão
** Tipo 2 inteiro sem sinal e tamanho define precisão 
** Tipo 3 inteiro com sinal e tamanho define 
** 6 bits para tamanho max de 63 bytes

** Algoritmo para dados genéricos
posicao = 0;
while(posicao < tamanho){
  tamanho_corrente = dados[posicao]  >> 2; // 6 bits para tamanho
  switch(dados[posicao] & 0b00000011){
    case 0b00000001:// número real
      if(tamanho_corrente == sizeof(double)){
        // é um double
        double valor = 0.0;
        for(uint8_t indice = 0;indice < sizeof(double);indice++){
          valor = (valor << (8*indice)) | dados[posicao];
          posicao++
        }
      }else if(tamanho_corrente == sizeof(float)){
        // é um float
        float valor = 0.0;
        for(uint8_t indice = 0;indice < sizeof(double_bytes);indice++){
          valor = (valor << (8*indice)) | dados[posicao];
          posicao++;
        }
      }else{
        // se tamanho incompatível com double ou float trata como caracteres
        char valor[tamanho_corrente];
        for(uint8_t indice = 0;indice < tamanho_correntr;indice++){
          valor[início] = dados[posicao];
          posicao++;
         }
      }
    break;
    case 0b00000010:// inteiro sem sinal

      break;
    case 0b00000011:// inteiro com sinal

      break;
    default:
     char valor[tamanho_corrente];
      for(uint8_t indice = 0;indice < tamanho_correntr;indice++){
         valor[início] = dados[posicao];
         posicao++;
      }
  };
}
*/