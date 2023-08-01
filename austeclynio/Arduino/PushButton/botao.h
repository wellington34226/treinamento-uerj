#ifndef BOTAO_h
#define BOTAO_h

#include "Arduino.h"
#define DEBOUNCE 10

class Botao {
  private:
	  unsigned long m_debouncing;
    unsigned long m_tempoDebounce;
	  unsigned long m_tempoInicio;
    unsigned long m_tempoPressionado;

    uint8_t m_pino;
    uint8_t m_estados; // | | pressionado e solto | atual | anterior | pullup
  public:
    Botao(bool pullup = true,unsigned long tempoDebounce = DEBOUNCE);
    void init(uint8_t pino);
    uint8_t estado(void);
    int tempoPressionado(void);
};

#endif /* BOTAO_H */