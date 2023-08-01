#include <RH_ASK.h>

// const byte pinRele=7;
// const byte pinBuzzer=10;

RH_ASK driver(3000,11,12);

void setup () {
  Serial.begin(500000);
  // pinMode(pinRele,OUTPUT);
  // pinMode(pinBuzzer,OUTPUT);
  // digitalWrite(pinRele,LOW);
  // noTone(pinBuzzer);
  if (!driver.init()){
    Serial.println("Erro na carga do driver!");
  }else{
    Serial.print("Receptor configurado com velocidade de ");
    Serial.print(driver.speed(),DEC);
    Serial.println("bps");    
  }
}
void loop () {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN]; // Armazena a mensagem recebida
  uint8_t buflen = sizeof(buf); // Armazena o tamanho da mensagem
  if (driver.recv(buf, &buflen)) { // Checa se chegou algo. Recepciona pelo pino 11(válido para o Arduino)
    Serial.print("Dados recebidos:");
    for(int indice=0;indice < buflen;indice++){
      Serial.print(" 0x");
      if(buf[indice] < 16){
        Serial.print("0");
      }
      Serial.print(buf[indice],HEX);
    }
    Serial.println("");
    // if ((char)buf[0]=='I' ){
    //   digitalWrite(pinRele,LOW);
    //   tone(pinBuzzer,3000,500);
    //   delay(500);
    //   noTone(pinBuzzer);
    // }else if ((char)buf[0]=='L' ){
    //   digitalWrite(pinRele,HIGH);
    // }
  }
  //delay(1000);
}