const int ledPin = 13; 
int dado; //variável que receberá os dados da porta serial

void setup(){
  Serial.begin(115200);//frequência da porta serial
  pinMode(ledPin,OUTPUT); //define o pino o ledPin como saída
}

void loop(){
  if(Serial.available() > 0){ //verifica se existe comunicação com a porta serial
    
      dado = Serial.parseInt();//lê os dados da porta serial
      Serial.println(dado);
      switch(dado){
        case 1:
           digitalWrite(ledPin,HIGH); //liga o pino ledPin           
        break;
        case 2:
           digitalWrite(ledPin,LOW); //desliga o pino ledPin          
         break;
    }
  }
}
