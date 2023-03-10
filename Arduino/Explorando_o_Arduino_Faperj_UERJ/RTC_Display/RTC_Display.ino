#include <Wire.h>
#include <RtcDS3231.h>
#include <TM1637Display.h>

RtcDS3231<TwoWire> Rtc(Wire);
RtcDateTime   dataHora;
RtcTemperature temp;

#define CLK 5
#define DIO 6

TM1637Display tm(CLK, DIO);

// Conectar no SDA e SCL do Arduino

void setup(){
  Serial.begin(115200);
  tm.setBrightness(3);
  tm.clear(); 
  Rtc.Begin();
  Rtc.SetDateTime(RtcDateTime(2023,2,2,11,4,00)); // Acertando data e hora
  
  if (!Rtc.GetIsRunning()){
      Serial.println("RTC was not actively running, starting now");
      Rtc.SetIsRunning(true);
  }
}

void loop(){
  temp = Rtc.GetTemperature();
  dataHora = Rtc.GetDateTime();     
  tm.showNumberDec(temp.AsFloatDegC(),false,2,0);
  
  delay(3000);
  tm.clear();
  tm.showNumberDecEx(dataHora.Hour()*100 + dataHora.Minute(),0b11100000,false,4,0); 
  delay(27000);
}
