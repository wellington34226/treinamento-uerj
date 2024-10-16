#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "ssssssssssssssssssssssss";
const char* password =  "pppppppppppppppppppp";
const char* mqtt_server = "192.168.1.65";      // Endereço do Mosquitto - Broker

char msg1[50];
char msg2[50];
 
WiFiClient espClient;
PubSubClient client(espClient); 

void setup(){  
      Serial.begin(115200);  
      Serial.print("Conectando a Rede WiFi ");   
      Serial.println(ssid); 
      WiFi.begin(ssid, password);  
     
      while (WiFi.status() != WL_CONNECTED) {
         Serial.println(client.state()); 
         delay(500);   
      }
       Serial.println("Conectado ");
       Serial.print("IP Address do ESP8266:  ");
       Serial.println(WiFi.localIP());

       Serial.println("Conectando ao Mosquitto");   
       client.setServer(mqtt_server, 1883);    
} 

void loop(){
    String temperatura =(String) random(10,45);        // Valor arbitrado randomicamente
    temperatura.toCharArray(msg1,temperatura.length()+1);   
    String umidadeSolo =(String) random(80,320);        // Valor arbitrado randomicamente
    umidadeSolo.toCharArray(msg2,umidadeSolo.length()+1);
    publica(msg1,msg2);
    delay(30000);    
}

void publica(char* msg1, char* msg2){  
  if (!client.connected()){    
     conecta();
  }
     client.publish("temperatura_ambiente_01",msg1,true); 
     client.publish("umidade_solo_01",msg2,true); 
     Serial.println("Mensagens publicadas!!!");
     //client.disconnect();   Utilizar quando for um publicação que independe do tempo, ex: invasão de ambiente     
}

void conecta(){  
  while (!client.connected()) {
    if (client.connect("Esp8266 Publicando","","","Controle_Ambiente_01",1,true,"Fora do Ar")){
       Serial.println("Cliente Conectado ao Mosquitto");  
    }
    else{ 
        Serial.println(client.state());     
        delay(2000);
    }
  }
}
