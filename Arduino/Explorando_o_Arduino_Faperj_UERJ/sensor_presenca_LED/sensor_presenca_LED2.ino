const byte pinoPIR = 8;
const byte ledAzul = 11;
const byte relePino = 5;

void setup(){
  Serial.begin(115200);
  pinMode(ledAzul,OUTPUT);
  pinMode(relePino,OUTPUT);
  delay(1000);
  digitalWrite(ledAzul, LOW);
}
 
void loop(){ 
  if (digitalRead(pinoPIR) == HIGH){
    Serial.println("Entrou!");
    digitalWrite(ledAzul, HIGH);
    digitalWrite(relePino, HIGH);
    delay(15000);
  }else{
    Serial.println("Saiu!");
    digitalWrite(ledAzul, LOW);
    digitalWrite(relePino, LOW);
    delay(1000);
  }
}
