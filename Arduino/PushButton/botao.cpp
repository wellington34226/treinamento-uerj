#include "Arduino.h"
#include "botao.h"

Botao::Botao(bool pullup,unsigned long tempoDebounce):
  m_debouncing(0),
  m_tempoDebounce(tempoDebounce),
  m_tempoInicio(0),
  m_tempoPressionado(0),
  m_pino(0),
  m_estados(0){
    if(pullup){
      m_estados |= 1 << 0; //ativa bit indicando modo pullup
    }
};
void Botao::init(uint8_t pino){
  if(m_pino==0){
    if(pino>0){
      m_pino = pino;
      pinMode(m_pino,m_estados & 0b00000001?INPUT_PULLUP:INPUT);
    }
  }
};
/*
  void Botao::loop(void){
    if(m_pino>0){
      if((millis() - m_debounceBotao) >= m_tempoDebounce ) {
        m_solto = false;
        m_apertado = false;
        m_estadoBotao = digitalRead(m_pino);
        m_debounceBotao = millis();
        if(m_estadoBotao != m_estadoBotaoAnt){
          if(m_pullup){
            if(m_estadoBotao == LOW){
              m_tempoInicio = millis();
              m_tempoPressionado = 0;
              m_apertado = true;
            }else{
              m_tempoPressionado = millis() - m_tempoInicio;
              m_tempoInicio = 0;
              m_solto = true;
            }
          }else{
            if(m_estadoBotao == HIGH){
              m_tempoInicio = millis();
              m_tempoPressionado = 0;
              m_apertado = true;
            }else{
              m_tempoPressionado = millis() - m_tempoInicio;
              m_tempoInicio = 0;
              m_solto = true;
            }
          }
        }else{
          if(m_pullup){
            if(m_estadoBotao == LOW){
              m_apertado = true;
            }
          }else{
            if(m_estadoBotao == HIGH){
              m_apertado = true;
            }
          }
        }
        m_estadoBotaoAnt = m_estadoBotao;
      }
          
    }
  };
*/
uint8_t Botao::estado(void){
  return m_estados >> 2;
};
int Botao::tempoPressionado(void){
  if(m_tempoInicio > 0){
    return millis() - m_tempoInicio;
  }else{
    return m_tempoPressionado;
  }
};