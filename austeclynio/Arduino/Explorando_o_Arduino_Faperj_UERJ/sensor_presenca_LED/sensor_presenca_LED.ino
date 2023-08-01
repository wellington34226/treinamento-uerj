
const byte ledVermelho = 11;
const byte pinoPIR = 8; 



void setup(){
 Serial.begin(115200);
 pinMode(ledVermelho,OUTPUT);
 delay(1000);
 digitalWrite(ledVermelho, LOW);
}

void loop(){ 
 if (digitalRead(pinoPIR) == HIGH){
   Serial.println("Entrou!");
   digitalWrite(ledVermelho, HIGH);
   delay(15000);
 }else{
   Serial.println("Saiu!");
   digitalWrite(ledVermelho, LOW);
   delay(1000);
 }
}
