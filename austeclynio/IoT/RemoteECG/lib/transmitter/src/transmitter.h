#ifdef TRANSMITTER
#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "includes.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DISPLAY_ADDRESS 0x3C
#define DISPLAY_RESET -1
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32

class Transmitter: public DeviceSystem{
  public:
    Transmitter();
    virtual ~Transmitter();
    virtual void init(void)override;
    virtual void loop(void)override;
  private:
    Adafruit_SSD1306 display;
    uint8_t pinLed1;
    uint8_t pinLed2;
    uint8_t pinLed3;
    uint8_t pinEcgLoNegative;
    uint8_t pinEcgLoPositive;
    uint8_t pinEcgOutput;
};

#endif
#endif