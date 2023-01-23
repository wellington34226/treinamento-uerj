#include <Servo.h>

Servo servo01;
int pos = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("B4H - Servicos em Computacao - Servo-Motor");  
  servo01.attach(5);       // Controle no pino D5   
}
void loop() {
  
   delay(200);
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    servo01.write(pos);              
    delay(30);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo01.write(pos);              
    delay(30);                       
  }

}
