#include "receptor.h"

#ifdef RECEPTOR
Receptor::Receptor():
  display(DISPLAY_CS, DISPLAY_DC, DISPLAY_MOSI, DISPLAY_CLK, DISPLAY_RST, DISPLAY_MISO),
  touchScreen(DISPLAY_TOUCH_CS,DISPLAY_MOSI,DISPLAY_MISO,DISPLAY_CLK),
  webPath("/web"),
  pinLed1(4),//LED 1 portas GPIO4
  pinLed2(25),//LED 2 portas D5 GPIO25
  mqttClient(),
  webServer(80)
{
  
};
Receptor::~Receptor(){

};
void Receptor::init(void){
  pinMode(pinLed1,OUTPUT);
  digitalWrite(pinLed1,LOW);
  pinMode(pinLed2,OUTPUT);
  digitalWrite(pinLed2,LOW);
  display.begin(80000000);
  Serial.println("Teste de tela!");
  Serial.print(F("Identificação: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDDID),HEX);
  Serial.print(F("Estado: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDDST),HEX);
  Serial.print(F("Modo: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDMODE),HEX);
  Serial.print(F("Modo AD CTL: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDMADCTL),HEX);
  Serial.print(F("Formato de pixel: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDPIXFMT),HEX);
  Serial.print(F("Formato de imagem: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDIMGFMT),HEX);
  Serial.print(F("Auto diagnóstico: 0x"));
  Serial.println(display.readcommand8(ILI9341_RDSELFDIAG),HEX);
  delay(1000);
};
void Receptor::loop(void){

};

void Receptor::getWifiConfig(String& ssid,String& pass){
  File file2load = LittleFS.open(confPath,"r");
  String msg;
  StaticJsonDocument<1024> config;
  DeserializationError error;
  if(file2load){
    String msg = file2load.readString();
    file2load.close();
    error = deserializeJson(config,msg);
    if(!error) {
      if(!config["wifi"]["ssid"].isNull()){
        if(config["wifi"]["ssid"].as<const char *>() != NULL){
          msg = config["wifi"]["ssid"].as<const char *>();
          if(msg.length()>0){
            if(!msg.equalsIgnoreCase("null")){
              ssid = msg;
            }
          }
        }
      }
      if(!config["wifi"]["pass"].isNull()){
        if(config["wifi"]["pass"].as<const char *>() != NULL){
          msg = config["w"]["pass"].as<const char *>();
          if(!msg.equalsIgnoreCase("null")){
            pass = msg;
          }
        }
      }
    }
  }
};

DeviceSystem * deviceSystem = &Receptor();

#endif