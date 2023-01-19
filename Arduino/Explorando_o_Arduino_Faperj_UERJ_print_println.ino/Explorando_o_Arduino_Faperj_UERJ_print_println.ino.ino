
void setup(void){
  Serial.begin(115200);   //ATENÇÃO
  Serial.println("UER-FAPERJ - Exemplo print() println()");
  Serial.println("FEITAS AS HONRAS DA CASA");
}

void loop(void){
  int valor = 1809;
  Serial.println("Testando a saida serial!");
  Serial.println(valor);
  Serial.println(valor,DEC);
  Serial.println(valor,OCT);
  Serial.println(valor,HEX);
  Serial.println(valor,BIN);
  delay(5000);
   
}
