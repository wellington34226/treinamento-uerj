/** Experimento 1
Projetar um sinal luminoso de trânsito com as seguintes
regras;
– A luz verde deve ficar acesa por 60s;
– A luz amarela deve ficar acesa por 10s, concomitante aos
últimos 10s da luz verde;
– A luz vermelha deve ficar acesa por 30s;
– O ciclo se repete indefinidamente;
Componentes utilizados;
– Placa Arduino UNO;
– LEDs vermelho, amarelo e verde;
– Jumpers e protoboard;
*/

// Pinos de controle
short int ledVerdePino    = 2;
short int ledVermelhoPino = 3;
short int ledAmareloPino  = 4;
short int rgbVermelhoPino = 9;
short int rgbVerdePino    = 10;
short int rgbAzulPino     = 11;
//Estados (Acesso ou Apagado)
short int ledVerdeEstado    = HIGH;
short int ledAmareloEstado  = LOW;
short int ledVermelhoEstado = LOW;
//Temporiazadores para mudança de estado
long int tempoBase        = 1000;//para controlar o multiplicador dos temporizadores (em segundos)
long int ledVerdeTempo    = 60*tempoBase;
long int ledAmareloTempo  = 10*tempoBase;
long int ledVermelhoTempo = 30*tempoBase;
//Carimbos de tempo data e hora da ultima modificação de estado
long int ledVerdeStamp    = 0;
long int ledAmareloStamp  = 0;
long int ledVermelhoStamp = 0;

void estadosSerial(void);

/* Funcção de configuração */
void setup() {
  Serial.begin(115200);
  while(!Serial){}
  pinMode(rgbAzulPino    ,OUTPUT);
  pinMode(ledVerdePino   ,OUTPUT);
  pinMode(rgbVerdePino   ,OUTPUT);
  pinMode(ledAmareloPino ,OUTPUT);
  pinMode(ledVermelhoPino,OUTPUT);
  pinMode(rgbVermelhoPino,OUTPUT);
  /* Inicia com todos os LEDs apagados e o LED Verde aceso */
  digitalWrite(ledVerdePino    ,ledVerdeEstado);
  digitalWrite(rgbVerdePino    ,ledVerdeEstado);
  digitalWrite(rgbAzulPino     ,ledAmareloEstado);
  digitalWrite(ledAmareloPino  ,ledAmareloEstado);
  digitalWrite(ledVermelhoPino ,ledVermelhoEstado);
  digitalWrite(rgbVermelhoPino ,ledVermelhoEstado);
  ledVerdeStamp = millis();
}
/* Função de execução */
void loop() {
  long int currentStamp = millis();
  if(ledVermelhoEstado == HIGH){
    if((currentStamp-ledVermelhoStamp)>=ledVermelhoTempo){
      ledVerdeEstado    = HIGH;
      ledVermelhoEstado = LOW;
      digitalWrite(ledVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVermelhoPino,ledVermelhoEstado);
      digitalWrite(ledVermelhoPino,ledVermelhoEstado);
      ledVerdeStamp    = currentStamp;
      ledVermelhoStamp = currentStamp;
      estadosSerial();
    }
  }else if(ledAmareloEstado == HIGH){
    if((currentStamp-ledAmareloStamp)>=ledAmareloTempo){
      ledVerdeEstado    = LOW;
      ledAmareloEstado  = LOW;
      ledVermelhoEstado = HIGH;
      digitalWrite(ledVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbAzulPino    ,ledAmareloEstado);
      digitalWrite(ledAmareloPino ,ledAmareloEstado);
      digitalWrite(ledVermelhoPino,ledVermelhoEstado);
      digitalWrite(rgbVermelhoPino,ledVermelhoEstado);
      ledVerdeStamp    = currentStamp;
      ledAmareloStamp  = currentStamp;
      ledVermelhoStamp = currentStamp;
      estadosSerial();
    }
  }else if(ledVerdeEstado == HIGH){
    if((currentStamp-ledVerdeStamp)>=(ledVerdeTempo-ledAmareloTempo)){
      ledAmareloEstado = HIGH;
      digitalWrite(rgbAzulPino   ,ledAmareloEstado);
      digitalWrite(ledAmareloPino,ledAmareloEstado);
      ledAmareloStamp = currentStamp;
      estadosSerial();
    }
  }else{
    ledVerdeEstado = HIGH;
    digitalWrite(ledVerdePino,ledVerdeEstado);
    digitalWrite(rgbVerdePino,ledVerdeEstado);
    ledVerdeStamp = currentStamp;
    estadosSerial();
  }
}
void estadosSerial(void){
  Serial.print("LED VERDE: ");
  Serial.print(ledVerdeEstado?"ACESO":"APAGADO");
  Serial.print(" LED AMARELO:");
  Serial.print(ledAmareloEstado?"ACESO":"APAGADO");
  Serial.print(" LED VERMELHO: ");
  Serial.println(ledVermelhoEstado?"ACESO":"APAGADO");
};