#include "transmitter.h"
#ifdef TRANSMITTER
Transmitter::Transmitter() : display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, DISPLAY_RESET),
                             uint8_t pinLed1(12),         // LED 2 porta D6 GPIO12
                             uint8_t pinLed2(14),         // LED 2 porta D5 GPIO14
                             uint8_t pinLed3(16),         // LED 1 porta D0 GPIO16
                             uint8_t pinEcgLoNegative(0), // ECG LO- porta D3 GPIO0
                             uint8_t pinEcgLoPositive(2), // ECG LO+ porta D4 GPIO2
                             uint8_t pinEcgOutput(A0)     // ECG OUTPUT porta A0
                             {

                             };
Transmitter::~Transmitter(){

};
void Transmitter::init(void)
{
  pinMode(pinLed1, OUTPUT);
  digitalWrite(pinLed1, LOW);
  pinMode(pinLed2, OUTPUT);
  digitalWrite(pinLed2, LOW);
  pinMode(pinLed3, OUTPUT);
  digitalWrite(pinLed3, LOW);
  pinMode(pinEcgLoNegative, INPUT);
  pinMode(pinEcgLoPositive, INPUT);
  pinMode(pinEcgOutput, INPUT);

  uint8_t fails = 0;
  while (!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS))
  {
    Serial.print(".");
    delay(10000);
    fails++;
    if (fails >= maxFails)
    {
      Serial.println(F("Não foi possível iniciar tela OLED !\n"));
      ESP.restart();
      while (1)
        ;
    }
  }
  display.clearDisplay();
  /// carregar as configurações
  StaticJsonDocument configuration;
  WiFi.mode(WIFI_STA_AP);
  WiFi.softAPConfig(configuration["ap_address"], configuration["ap_gateway"], configuration["ap_subnet"]);
  WiFi.softAP(configuration["ap_ssid"], configuration["ap_password"]);
  WiFi.begin(sta_ssid, sta_password);
};
void Transmitter::loop(void){

};

DeviceSystem *deviceSystem = &Transmitter();

#endif