
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#define VERDE   0x07E0
#define BRANCO  0xFFFF
#define PRETO   0x0000
 
void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID(); 
  Serial.print("Identificador do driver: ");
  Serial.println(ID,HEX);
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(PRETO);
  tft.setCursor(10,100);
  tft.setTextColor(VERDE);
  tft.setTextSize(3);
  tft.print("Meu Driver: ");
  tft.setCursor(220,100);
  tft.print(String(ID,HEX));
}
 
void loop() {
}
