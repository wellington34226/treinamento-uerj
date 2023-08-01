short int buzzerPino = 11;

void setup() {
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
}

void loop() {
 for(int corrente = 0; corrente<10;corrente++){
  Serial.print("LED : ");
  if(corrente>0){
    Serial.println(intensidades[corrente]);
  }else{
    Serial.println("APAGADO");
  }
  analogWrite(ledPino,intensidades[corrente]);
  delay(1000);
 }
}
