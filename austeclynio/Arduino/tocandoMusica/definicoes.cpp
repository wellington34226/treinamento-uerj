#include "definicoes.h"
#include "notas.h"
#include "tempos.h"
#include <String.h>

const unsigned int Nota::m_notasDO[]  = {NOTE_C1,NOTE_CS1,NOTE_C2,NOTE_CS2,NOTE_C3,NOTE_CS3,NOTE_C4,NOTE_CS4,NOTE_C5,NOTE_CS5,NOTE_C6,NOTE_CS6,NOTE_C7,NOTE_CS7,NOTE_C8,NOTE_CS8};
const unsigned int Nota::m_notasRE[]  = {NOTE_D1,NOTE_DS1,NOTE_D2,NOTE_DS2,NOTE_D3,NOTE_DS3,NOTE_D4,NOTE_DS4,NOTE_D5,NOTE_DS5,NOTE_D6,NOTE_DS6,NOTE_D7,NOTE_DS7,NOTE_D8,NOTE_DS8};
const unsigned int Nota::m_notasMI[]  = {NOTE_E1,NOTE_E2,NOTE_E3,NOTE_E4,NOTE_E5,NOTE_E6,NOTE_E7};
const unsigned int Nota::m_notasFA[]  = {NOTE_F1,NOTE_FS1,NOTE_F2,NOTE_FS2,NOTE_F3,NOTE_FS3,NOTE_F4,NOTE_FS4,NOTE_F5,NOTE_FS5,NOTE_F6,NOTE_FS6,NOTE_F7,NOTE_FS7};
const unsigned int Nota::m_notasSOL[] = {NOTE_G1,NOTE_GS1,NOTE_G2,NOTE_GS2,NOTE_G3,NOTE_GS3,NOTE_G4,NOTE_GS4,NOTE_G5,NOTE_GS5,NOTE_G6,NOTE_GS6,NOTE_G7,NOTE_GS7};
const unsigned int Nota::m_notasLA[]  = {NOTE_A1,NOTE_AS1,NOTE_A2,NOTE_AS2,NOTE_A3,NOTE_AS3,NOTE_A4,NOTE_AS4,NOTE_A5,NOTE_AS5,NOTE_A6,NOTE_AS6,NOTE_A7,NOTE_AS7};
const unsigned int Nota::m_notasSI[]  = {NOTE_B0,NOTE_B1,NOTE_B2,NOTE_B3,NOTE_B4,NOTE_B5,NOTE_B6,NOTE_B7};
const unsigned int Nota::m_tempos[]   = {SEMIBREVE,MINIMA,SEMIMINIMA,COLCHEIA,SEMICOLCHEIA,FUSA,SEMIFUSA};
unsigned int Nota::m_pinoBuzzer = 0;
unsigned int Nota::m_compasso = 1000;

Nota::Nota(unsigned int pino,nota nota,oitava oitava,bool sustenido,bool bmol,tempo duracao,tempo pausa):duracao(duracao),pausa(pausa){
  setPino(pino);
  setNota(nota,oitava,sustenido,bmol);
};
Nota::Nota(Nota &proxima,unsigned int pino,nota nota,oitava oitava,bool sustenido,bool bmol,tempo duracao,tempo pausa):duracao(duracao),pausa(pausa){
  setPino(pino);
  setNota(nota,oitava,sustenido,bmol);
  m_proxima = proxima;
};
Nota::~Nota(){
  if(m_proxima!=0){
    m_proxima->~Nota();
    delete m_proxima;
    m_proxima = 0;
  }
};
void Nota::init(unsigned int pino){
  if(pino > 0){
    Nota::m_pinoBuzzer = pino;
    pinMode(Nota::m_pinoBuzzer,OUTPUT);
    noTone(Nota::m_pinoBuzzer);
  }
};
void Nota::setCompasso(unsigned int compasso){
  if(compasso > 0){
    Nota::m_compasso = compasso;
  }
};
void Nota::init(void){
  if(m_pino > 0 && m_pino != Nota::m_pinoBuzzer){
    pinMode(m_pino,OUTPUT);
    noTone(m_pino);
  }
};
void Nota::setPino(unsigned int pino){
  if(pino > 0){
    m_pino = pino;
  }else{
    m_pino = Nota::m_pinoBuzzer;//se o valor for zero utiliza o pino padrão
  }
};
void Nota::setNota(nota nota,oitava oitava,bool sustenido,bool bmol){
  short unsigned int frequencia;
  switch(nota){
    case SI:
      if(variacao < sizeof(Nota::m_notasSI)/sizeof(Nota::m_notasSI[0])){
        m_frequencia = Nota::m_notasSI[variacao];
      }else{
        m_frequencia = Nota::m_notasSI[0];
      }
      break;
    case DO:
      if(variacao < sizeof(Nota::m_notasDO)/sizeof(Nota::m_notasDO[0])){
        m_frequencia = Nota::m_notasDO[variacao];
      }else{
        m_frequencia = Nota::m_notasDO[0];
      }
      break;
    case RE:
      if(variacao < sizeof(Nota::m_notasRE)/sizeof(Nota::m_notasRE[0])){
        m_frequencia = Nota::m_notasRE[variacao];
      }else{
        m_frequencia = Nota::m_notasRE[0];
      }
      break;
    case MI:
      if(variacao < sizeof(Nota::m_notasMI)/sizeof(Nota::m_notasMI[0])){
        m_frequencia = Nota::m_notasMI[variacao];
      }else{
        m_frequencia = Nota::m_notasMI[0];
      }
      break;
    case FA:
      if(variacao < sizeof(Nota::m_notasFA)/sizeof(Nota::m_notasFA[0])){
        m_frequencia = Nota::m_notasFA[variacao];
      }else{
        m_frequencia = Nota::m_notasFA[0];
      }
      break;
    case SOL:
      if(variacao < sizeof(Nota::m_notasSOL)/sizeof(Nota::m_notasSOL[0])){
        m_frequencia = Nota::m_notasSOL[variacao];
      }else{
        m_frequencia = Nota::m_notasSOL[0];
      }
      break;
    case LA:
      if(variacao < sizeof(Nota::m_notasLA)/sizeof(Nota::m_notasLA[0])){
        m_frequencia = Nota::m_notasLA[variacao];
      }else{
        m_frequencia = Nota::m_notasLA[0];
      }
      break;
    default:
      frequencia = 0;
  }
  m_frequencia = frequencia;
};
void Nota::setDuracao(tempo duracao){
  m_duracao = Nota::m_compasso/duracao;
};
void Nota::setDuracoes(tempo duracao){
  setDuracao(duracao);
  if(m_proxima!=0){
    m_proxima->setDuracoes(duracao);
  }
};
void Nota::setPausa(tempo pausa){
  m_pausa = Nota::m_compasso/pausa;
};
void Nota::setPausas(tempo pausa){
  setPausa(pausa);
  if(m_proxima!=0){
    m_proxima->setPausas(pausa);
  }
};
void Nota::setProxima(Nota &proxima){
  m_proxima = &proxima;
};
void Nota::tocarNota(void){
  if(m_frequencia>30){
    if(m_pino > 0){
      tone(m_pino,m_frequencia,m_duracao);
    }else{
      tone(Nota::m_pinoBuzzer,m_frequencia,m_duracao);
    }
    delay(m_duracao);
  }
};
void Nota::tocarMusica(void){
  tocarNota();
  if(m_proxima!=0){
    if(m_pino > 0){
      noTone(m_pino);
    }else{
      noTone(Nota::m_pinoBuzzer);
    }
    delay(m_pausa);
    m_proxima->tocarMusica();
  }
};
void Nota::testarBuzzer(){
  tone(Nota::m_pinoBuzzer,Nota::m_notasDO[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasRE[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasMI[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasFA[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasSOL[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasLA[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
  tone(Nota::m_pinoBuzzer,Nota::m_notasSI[0],Nota::m_compasso);
  delay(Nota::m_compasso);
  noTone(Nota::m_pinoBuzzer);
  delay(Nota::compasso*0.2);
};