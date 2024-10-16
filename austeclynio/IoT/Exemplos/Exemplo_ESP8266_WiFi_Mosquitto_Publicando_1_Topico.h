#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "sssssssssssssssssssssssss";
const char* password =  "pppppppppppppppppppp";
//const char* mqtt_server = "192.168.1.65";      // Endereço do Mosquitto - Broker
const char* mqtt_server = "test.mosquitto.org";      // Endereço do Mosquitto - Broker
char msg[50];
 
WiFiClient espClient;
PubSubClient client(espClient); 

void setup(){  
      Serial.begin(115200);  
      Serial.print("Conectando a Rede WiFi ");   
      Serial.println(ssid);       
      WiFi.begin(ssid, password); 
      while (WiFi.status() != WL_CONNECTED) { 
		    Serial.print('.'); 
        delay(500);   
      } 
       Serial.println("Conectado ");
       Serial.print("IP Address  ");
       Serial.println(WiFi.localIP());
       Serial.println("Conectando ao Mosquitto");   
       client.setServer(mqtt_server, 1883);    
} 
void loop(){
    String temperatura =(String) random(10,45);
    temperatura.toCharArray(msg,temperatura.length()+1);
    publica(msg);
    delay(10000);
    
}

void publica(char* msg){  
  if (!client.connected()){    
     conecta();
  }
     client.publish("temperatura_ambiente_01",msg,true); 
     Serial.println("Mensagem publicada");
     //client.disconnect();   Utilizar quando for um publicação que independe do tempo, ex: invasão de ambiente
     
}
void conecta(){  
  while (!client.connected()) {
    if (client.connect("Esp8266 Publicando","","","Controle_Comodo_01",1,false,"Fora do Ar")){
       Serial.println("Cliente Conectado ao Mosquitto");  
    }
    else{ 
        Serial.println(client.state());     
        delay(2000);
    }
  }
}
