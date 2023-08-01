#include "definicoes.h"
#include <String.h>

void setup(void){
  byte tentativas = 0;
  Serial.begin(115200);  
  while(!Serial && tentativas < 10){
    delay(5000);//aguarda 5 segundos para tentar iniciar a Serial novamente
    tentativas++;
  };
  if(!Serial){
    
  }
  Nota::init(3);
};

void loop(void){
  Nota::testarBuzzer();
  delay(60000);
};