#ifdef RECEPTOR
#ifndef RECEPTOR_H
#define RECEPTOR_H

#include "includes.h"
#include <DNSServer.h>

#ifdef ESP32
  #include <AsyncTCP.h>
#elif defined(ESP8266)
  #include <ESPAsyncTCP.h>
#endif

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>
#include <ESPAsyncWebServer.h>
#include <AsyncMqttClient.h>

#define DISPLAY_RST 2
#define DISPLAY_CS 32
#define DISPLAY_DC 33
#define DISPLAY_MISO 12
#define DISPLAY_MOSI 13
#define DISPLAY_CLK 14
#define DISPLAY_SDCARD_CS 25
#define DISPLAY_TOUCH_CS 26
#define DISPLAY_TOUCH_IRQ  27
#define DISPLAY_ON  0x07E0
#define DISPLAY_OFF 0xF800
#define DISPLAY_WHITE  0xFFFF
#define DISPLAY_YELLOW 0xFFE0
#define DISPLAY_RED    0xF800
#define DISPLAY_BLUE   0x001F
#define DISPLAY_BLACK  0x0000
#define DISPLAY_TOUCH_MINX 150
#define DISPLAY_TOUCH_MINY 130
#define DISPLAY_TOUCH_MAXX 3800
#define DISPLAY_TOUCH_MAXY 4000
#define TIC_MAX_SIZE 5
#define TIC_MIN_SIZE 2
#define TIC_MAX_GAP 10
#define TIC_MIN_GAP 2

class Receptor: public DeviceSystem {
  public:
    Receptor();
    virtual ~Receptor();
    virtual void init(void) override;
    virtual void loop(void) override;
  private:
    Adafruit_ILI9341 display;
    Adafruit_STMPE610 touchScreen;
    String webPath;
    uint8_t pinLed1;
    uint8_t pinLed2;
    AsyncMqttClient mqttClient;
    AsyncWebServer webServer;
    #ifdef ESP32
      TimerHandle_t mqttReconnectTimer;
      TimerHandle_t wifiReconnectTimer;
    #elif defined(ESP8266)
      Tiker mqttReconnectTimer;
      Tiker wifiReconnectTimer;
    #endif

    void getWifiConfig(String& ssid,String& pass);
};

#endif
#endif