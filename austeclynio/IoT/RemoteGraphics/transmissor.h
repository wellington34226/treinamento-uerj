#ifndef TRANSMISSOR_H
#define TRANSMISSOR_H

#include "definicoes.h"

#ifdef TRANSMISSOR

#ifdef ARDUINO
  #include <RH_ASK.h>//https://github.com/PaulStoffregen/RadioHead
#endif

#define INTERVALO 1 // intervalo em segundos para alterar a saída PWM

class Transmissor {
  private:
    // Atributos de classe
    
    static RH_ASK m_trasmissor;//objeto para comunicação sem fio

    static uint8_t m_estados;// array de bool para indicação dos estados da execução 0 | 0 | 0 | ENTRADA A2 | ENTRADA A1 | ENTRADA A0 | SAIDA | TRANSMISSOR
    static uint8_t m_dados[];// Buffer para armazenar a mensagem a ser enviada
    static uint8_t m_tamanho;// tamanho dos dados a serem enviados
    static const uint8_t m_pwmOutPino;// pino de saída PWM
    
    static const uint8_t m_tripotPino;// pino do tripot
    static const uint8_t m_ldrPino;// pino do LDR
    static const uint8_t m_pwmInPino;// pino de entrada do sinal PWM
    static uint16_t m_entradas[];// entradas analógicas a serem monitoradas 
    // Métodos privados estáticos
    static void atualizarDados(void);
    static void enviarDados(void);
    static void imprimirMensagem(void);
  public:
    Transmissor();//Construtyor padrão
    virtual ~Transmissor();//destrutor
    // Métodos estáticos públicos
    static void init(void);
    static void loop(void);
};
#endif /* TRAMISSOR */
#endif /* TRANSMISSOR_H */