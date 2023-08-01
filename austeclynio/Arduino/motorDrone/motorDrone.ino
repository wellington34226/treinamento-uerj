#include <Servo.h>

Servo servoMotor;

int servoPino = 5;
int dronePino = 6;
int tripotPino = A0;

int valorAnterior = 0;
int valorCorrente = 0;
int saida = 0;

void setup() {
  Serial.begin(115200);
  pinMode(dronePino,OUTPUT);
  pinMode(tripotPino,INPUT_PULLUP);
  servoMotor.attach(5);
}

void loop() {
  valorCorrente = analogRead(tripotPino);
  if((valorCorrente-valorAnterior)>100 || (valorAnterior-valorCorrente)>100){
    valorAnterior = valorCorrente;
    saida = map(valorAnterior,0,1023,0,180);
    Serial.print("Posicao ServoMotor:");
    Serial.print(saida);
    servoMotor.write(saida);
    saida = map(valorAnterior,0,1023,0,255);
    analogWrite(dronePino,saida);
    Serial.print(" Posicao DroneMotor:");
    Serial.println(saida);
  }
}
