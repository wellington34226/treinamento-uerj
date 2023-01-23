const byte ledVermelho = 4;
const byte ledVerde = 5;
const byte ledAmarelo = 6;


void setup() {
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);

}

void loop() {
  digitalWrite(ledVermelho,LOW);
  digitalWrite(ledVerde,HIGH);
  delay(50000);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledAmarelo,HIGH);
  delay(10000);
  digitalWrite(ledVermelho,HIGH);
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVerde,LOW); 
   delay(30000); 
}
