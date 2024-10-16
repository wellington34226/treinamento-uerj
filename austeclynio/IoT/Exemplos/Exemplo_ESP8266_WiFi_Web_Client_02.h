#include <ESP8266WiFi.h>        // Incluindo a Biblioteca
//#include <WiFi.h>        // Incluindo a Biblioteca
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>
//#include <HTTPClient.h>

#include "Exemplos.h"

WiFiClient client;
HTTPClient http;
int contaFalhas=0;
const char* host = "http://152.92.181.90:8080//CadastroPrimario/CadastroInicial";   // Endereço do servidor e caminho, pode ser ipaddress 

void setup() {
  Serial.begin(SERIAL_RATE);
  Serial.print("Conectando a ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {    
    Serial.print(".");
    delay(1000);
    contaFalhas++;
    if (contaFalhas>5){
          Serial.println("--> Mais de 5 falhas consecutivas!\n");
          contaFalhas=0;
          ESP.restart();
          while(1);
     }

  }
  
  Serial.print("Conectado á rede WiFi network com IP Address: ");
  Serial.println(WiFi.localIP());
}
void loop(){
  if(WiFi.status()== WL_CONNECTED){
        
      http.begin(client,host); 

      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = "nome=Maria&cpf=1234&senha=12&confirmaSenha=1234";
      int httpResponseCode = http.POST(httpRequestData);

      Serial.print("Response Code: ");
      Serial.print(httpResponseCode);
      Serial.print(" Dados:");
      Serial.println(http.getString());

      http.end();
}

delay(10000);
}
