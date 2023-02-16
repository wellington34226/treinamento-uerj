// utilizar #define com o modo de operação desejado (TRANSAMISSOR ou RECEPTOR) no arquivo definicoes.h
#include "definicoes.h"

#ifdef TRANSMISSOR
  #include "transmissor.h"
#elif defined(RECEPTOR)
  #include "receptor.h"
#endif
void setup(){
  Serial.begin(500000);
  while(!Serial){delay(1000);}
  Serial.println("Dispositivo iniciado!");
  
  #ifdef TRANSMISSOR
    Transmissor::init();
  #elif defined(RECEPTOR)
    Receptor::init();
  #endif
};

void loop(){
  #ifdef TRANSMISSOR
    Transmissor::loop();
  #elif defined(RECEPTOR)
    Receptor::loop();
  #endif
};