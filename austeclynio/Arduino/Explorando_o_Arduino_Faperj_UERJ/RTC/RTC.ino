#include <Wire.h> 
#include <RtcDS3231.h>

RtcDS3231<TwoWire> Rtc(Wire);
RtcDateTime        dataHora;
RtcTemperature     temp;
String             horaTemp;

// Conectar no SDA e SCL do Arduino

void setup(){
  Serial.begin(115200);
  Rtc.Begin();
  Rtc.SetDateTime(RtcDateTime(2023,02,02,10,21,00)); // Acertando data e hora
  while (!Rtc.GetIsRunning()){
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }
}


void loop(){
  temp  = Rtc.GetTemperature();
  dataHora = Rtc.GetDateTime();
  horaTemp="";
  horaTemp.concat(dataHora.Hour());
  horaTemp.concat(":");
  horaTemp.concat(dataHora.Minute());
  horaTemp.concat(" ");
  horaTemp.concat(temp.AsFloatDegC());
  horaTemp.concat("ºC");
  Serial.println(horaTemp);
  delay(30000);
}
