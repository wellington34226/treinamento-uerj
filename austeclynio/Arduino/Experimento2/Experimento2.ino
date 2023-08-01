/* Experimento 2
Implementar um sinal luminoso, com botão, para travessia de pedestres.
Regras:
  A luz verde fica normalmente acesa;
  Quando o botão é pressionado, 20 seg depois a luz amarela acende, concomitante à luz
verde. Ficarão acesas durante 10s;
  A luz vermelha acende, permanecendo assim por 20s;
  A luz verde volta a acender;
  A luz amarela só acende se a luz verde já estiver acesa;
Componentes utilizados;
  Placa Arduino UNO;
  Uma micro-chave mecânica;
  LEDs vermelho, amarelo e verde;
  Jumpers e protoboard;
Finalizado
*/
// Pinos de controle
short int ledVerdePino    = 2;
short int ledVermelhoPino = 3;
short int ledAmareloPino  = 4;
short int botaoPino       = 7;
short int rgbVermelhoPino = 9;
short int rgbVerdePino    = 10;
short int rgbAzulPino     = 11;
//Estados (Acesso ou Apagado)
short int ledVerdeEstado    = HIGH;
short int ledAmareloEstado  = LOW;
short int ledVermelhoEstado = LOW;
// Estados do botão
short int botaoEstadoCorrente = HIGH;
short int botaoEstadoAnterior = HIGH;
//Temporiazadores para mudança de estado
long int tempoBase        = 1000;//para controlar o multiplicador dos temporizadores (em segundos)
long int ledVerdeTempo    = 20*tempoBase;
long int ledAmareloTempo  = 10*tempoBase;
long int ledVermelhoTempo = 20*tempoBase;
long int botaoTempo       = 10;//10 milissegundos de debounce
//Carimbos de tempo data e hora da ultima modificação de estado
long int ledVerdeStamp    = 0;
long int ledAmareloStamp  = 0;
long int ledVermelhoStamp = 0;
long int botaoStamp       = 0;

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
  pinMode(botaoPino      ,INPUT_PULLUP);
  /* Inicia com todos os LEDs apagados e o LED Verde aceso */
  digitalWrite(ledVerdePino    ,ledVerdeEstado);
  digitalWrite(rgbVerdePino    ,ledVerdeEstado);
  digitalWrite(rgbAzulPino     ,ledAmareloEstado);
  digitalWrite(ledAmareloPino  ,ledAmareloEstado);
  digitalWrite(ledVermelhoPino ,ledVermelhoEstado);
  digitalWrite(rgbVermelhoPino ,ledVermelhoEstado);
  /* Inicia o estado do botão */
  botaoEstadoCorrente = digitalRead(botaoPino);
  botaoEstadoAnterior = botaoEstadoCorrente;
}
/* Função de execução */
void loop() {
  long int correnteStamp = millis();
  short int botao = digitalRead(botaoPino);
  if(botao != botaoEstadoAnterior){
    botaoEstadoAnterior = botao;
    botaoStamp = correnteStamp;
  }else if(botaoEstadoAnterior != botaoEstadoCorrente){
    if((correnteStamp-botaoStamp)>=botaoTempo){
      botaoEstadoCorrente = botao;
    }
  }
  if(ledVermelhoEstado == HIGH){
    if((correnteStamp-ledVermelhoStamp)>=ledVermelhoTempo){
      ledVerdeEstado    = HIGH;
      ledVermelhoEstado = LOW;
      digitalWrite(ledVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVermelhoPino,ledVermelhoEstado);
      digitalWrite(ledVermelhoPino,ledVermelhoEstado);
      ledVermelhoStamp = 0;
      estadosSerial();
    }
  }else if(ledAmareloEstado == HIGH){
    if((correnteStamp-ledAmareloStamp)>=ledAmareloTempo){
      ledVerdeEstado    = LOW;
      ledAmareloEstado  = LOW;
      ledVermelhoEstado = HIGH;
      digitalWrite(ledVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbVerdePino   ,ledVerdeEstado);
      digitalWrite(rgbAzulPino    ,ledAmareloEstado);
      digitalWrite(ledAmareloPino ,ledAmareloEstado);
      digitalWrite(ledVermelhoPino,ledVermelhoEstado);
      digitalWrite(rgbVermelhoPino,ledVermelhoEstado);
      ledVerdeStamp    = 0;
      ledAmareloStamp  = 0;
      ledVermelhoStamp = correnteStamp;
      estadosSerial();
    }
  }else if(ledVerdeEstado == HIGH){
    if(ledVerdeStamp==0){
      if(botaoEstadoCorrente == LOW){
        ledVerdeStamp = correnteStamp;
        estadosSerial();
      }
    }else if((correnteStamp-ledVerdeStamp)>=(ledVerdeTempo-ledAmareloTempo)){
      ledAmareloEstado = HIGH;
      digitalWrite(rgbAzulPino   ,ledAmareloEstado);
      digitalWrite(ledAmareloPino,ledAmareloEstado);
      ledAmareloStamp = correnteStamp;
      estadosSerial();
    }
  }
}
void estadosSerial(void){
  Serial.print("BOTÃO ANTERIOR: ");
  Serial.print(botaoEstadoAnterior?"NORMAL":"PRESSIONADO");
  Serial.print(" | BOTÃO CORRENTE: ");
  Serial.print(botaoEstadoCorrente?"NORMAL":"PRESSIONADO");
  Serial.print(" | LED VERDE: ");
  Serial.print(ledVerdeEstado?"ACESO":"APAGADO");
  Serial.print(" | LED VERMELHO: ");
  Serial.print(ledVermelhoEstado?"ACESO":"APAGADO");
  Serial.print(" | LED AMARELO:");
  Serial.println(ledAmareloEstado?"ACESO":"APAGADO");
};