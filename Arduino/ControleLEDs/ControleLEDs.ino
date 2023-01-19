
int ledVerdePino = 2;
int ledVermelhoPino = 3;
int ledAmareloPino = 4;
int ledVerdeEstado = 0;
int ledVermelhoEstado = 0;
int ledAmareloEstado = 0;
int tempoBase = 200;
int ledVerdeTempo = 10;
int ledVermelhoTempo = 5;
int ledAmareloTempo = 1;
long int ledVerdeStamp = 0;
long int ledVermelhoStamp = 0;
long int ledAmareloStamp = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial){}
  pinMode(ledVerdePino, OUTPUT);
  pinMode(ledVermelhoPino, OUTPUT);
  pinMode(ledAmareloPino, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  long int currentStamp = millis();
  if((currentStamp-ledVerdeStamp)>(tempoBase*ledVerdeTempo)){
    if(ledVerdeEstado){
      ledVerdeEstado = 0;
    }else{
      ledVerdeEstado = 1;
    }
    ledVerdeStamp = currentStamp;
    digitalWrite(ledVerdePino,ledVerdeEstado);
  }
  if((currentStamp-ledVermelhoStamp)>(tempoBase*ledVermelhoTempo)){
    if(ledVermelhoEstado){
      ledVermelhoEstado = 0;
    }else{
      ledVermelhoEstado = 1;
    }
    ledVermelhoStamp = currentStamp;
    digitalWrite(ledVermelhoPino,ledVermelhoEstado);
  }
  if((currentStamp-ledAmareloStamp)>(tempoBase*ledAmareloTempo)){
    if(ledAmareloEstado){
      ledAmareloEstado = 0;
    }else{
      ledAmareloEstado = 1;
    }
    ledAmareloStamp = currentStamp;
    digitalWrite(ledAmareloPino,ledAmareloEstado);
  }
}
