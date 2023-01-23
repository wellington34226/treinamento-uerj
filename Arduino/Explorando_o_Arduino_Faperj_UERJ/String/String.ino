String nome="Maria";
String sobreNome ="Jose";


void setup(){
    Serial.begin(115200);   //frequência da porta serial  
    Serial.println(nome);
    Serial.println(nome.length());
    nome.concat(sobreNome);
    Serial.println(nome);
    Serial.println(nome.length());
    Serial.println(nome.indexOf("J"));
    
    char mensagem[nome.length()];
    
    nome.toCharArray(mensagem,nome.length()+1);

    for (int i=0; i<=sizeof(mensagem); i++){
      Serial.print(mensagem[i]);
    }
}

void loop(){
  
}
