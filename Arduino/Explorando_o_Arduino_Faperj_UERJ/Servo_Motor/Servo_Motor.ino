#include <Servo.h>

Servo servo01;
int pos = 0;
bool subindo = true;

void setup() {
  Serial.begin(115200);
  Serial.println("B4H - Servicos em Computacao - Servo-Motor");  
  servo01.attach(5);       // Controle no pino D5   
}
void loop() {
  Serial.print("Posicao:");
  Serial.println(pos);
  servo01.write(pos);
  delay(100);
  if(subindo){
    if(pos==180){
      subindo = false;
      pos--;
    }else{
      pos++;
    }
  }else{
    if(pos==0){
      subindo = true;
      pos++;
    }else{
      pos--;
    }
  }
}
