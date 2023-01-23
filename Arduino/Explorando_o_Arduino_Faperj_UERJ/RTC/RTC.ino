#include <RtcDS3231.h>
#include <Wire.h> 

RtcDS3231<TwoWire> Rtc(Wire);
RtcDateTime   dataHora;
String horaAgora;

// Conectar no SDA e SCL do Arduino

void setup(){
  Serial.begin(115200);
  Rtc.Begin();
  Rtc.SetDateTime(RtcDateTime(2022,12,13,15,37,00)); // Acertando data e hora

  
  if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    
}


void loop(){
  horaAgora="";
  RtcTemperature temp = Rtc.GetTemperature();
  dataHora = Rtc.GetDateTime();  
  Serial.println(temp.AsFloatDegC());  
  delay(3000);
  Serial.println();
  horaAgora.concat(dataHora.Hour());
  horaAgora.concat(":");  
  horaAgora.concat(dataHora.Minute());
  Serial.println(horaAgora);
  delay(27000);
}
