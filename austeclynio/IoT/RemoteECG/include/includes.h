#ifndef INCLUDES_H
#define INCLUDES_H

#ifdef ESP32
extern "C"
{
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
}
#include <WiFi.h>
#include <AsyncUDP.h>
#elif defined(ESP8266)
#include <Ticker.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncUDP.h>
#else
#error "PLACA NÃO SUPORTADA, USE: ESP32 OU ESP8266"
#endif

#include <float.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <WString.h>
#include <LittleFS.h>
#include <IPAddress.h>
#include <ArduinoJson.h>

uint8_t maxFails = 10;
uint32_t serialRate = 115200;
uint32_t apAddress = 0x0100A8C0;
uint32_t apSubnet = 0x00FFFFFF;
String confPath = "/conf.json";
String dataPath = "/data.json";
String helpPath = "/help.json";

class DeviceSystem
{
public:
  DeviceSystem();
  virtual ~DeviceSystem() = 0;
  virtual void init(void) = 0;
  virtual void loop(void) = 0;
};
DeviceSystem::~DeviceSystem(){};

static DeviceSystem *deviceSystem;
#endif