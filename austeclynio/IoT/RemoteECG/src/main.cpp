#include "functions.h"

void setup() {
  Serial.begin(serialRate);
  if(!Serial){
    ESP.restart();
  }
  uint8_t countFails = 0;
  while(!LittleFS.begin()){
    delay(1000);
    countFails++;
    if(countFails>=maxFails){
      Serial.println(F("Não foi possível iniciar o sistema de arquivos, reinicando sistema"));
      ESP.restart();
    }
  }
  File file2load = LittleFS.open(confPath,"r");
  DeserializationError error;
  String msg;
  if(file2load){
    msg = file2load.readString();
    file2load.close();
    DynamicJsonDocument config(getConfigSizeJson());
    error = deserializeJson(config,msg);
    if(error) {
      Serial.println(F("Não foi possível ler o arquivo de configuração, formato JSON não encontrado!"));
    }else{
      Serial.println(F("Arquivo de configuração carregado com sucesso"));
      serializeJsonPretty(config,Serial);
    }
  }else{
    Serial.println(F("Não foi possível abrir o arquivo de configuração!"));
  }
  file2load = LittleFS.open(dataPath,"r");
  if(file2load){
    msg = file2load.readString();
    file2load.close();
    DynamicJsonDocument data(getDataSizeJson());
    error = deserializeJson(data,msg);
    if(error) {
      Serial.println(F("Não foi possível ler o arquivo de dados, formato JSON não encontrado!"));
    }else{
      Serial.println(F("Arquivo de dados carregado com sucesso"));
      serializeJsonPretty(data,Serial);
    }
  }else{
    Serial.println(F("Não foi possível abrir o arquivo de dados!"));
  }
  printHelp();
  deviceSystem->init();
}

void loop() {
  deviceSystem->loop();
}