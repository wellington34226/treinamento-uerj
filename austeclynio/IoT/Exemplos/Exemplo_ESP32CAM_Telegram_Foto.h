/*******************************************************************
   A Telegram bot for taking a photo with an ESP32Cam
   Parts used:
   ESP32-CAM module* - http://s.click.aliexpress.com/e/bnXR1eYs
    = Affiliate Links
   Note:
   - Make sure that you have either selected ESP32 Wrover Module,
           or another board which has PSRAM enabled
   - Choose "Huge App" partion scheme
   Some of the camera code comes from Rui Santos:
   https://randomnerdtutorials.com/esp32-cam-take-photo-save-microsd-card/
   Written by Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Tindie: https://www.tindie.com/stores/brianlough/
    Twitter: https://twitter.com/witnessmenow
*******************************************************************/

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "esp_camera.h"
#include <ArduinoJson.h>

//------- Replace the following! ------

//#define CAMERA_MODEL_WROVER_KIT
//#define CAMERA_MODEL_ESP_EYE
//#define CAMERA_MODEL_M5STACK_PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE
#define CAMERA_MODEL_AI_THINKER

#include "camera_pins.h"
#include "camera_code.h"

// Wifi network station credentials
const char* ssid = "ssssssssssssssssssssssss";
const char* password = "ppppppppppppppppppppppppp";

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "xxxxxxxxxxxxxxxxx:yyyyyyyyyyyyyyyyyyyyyyyyyyyyy"
#define CHAT_ID "zzzzzzzzzzzzzzz"

#define FLASH_LED_PIN 4

const unsigned long BOT_MTBS = 1000; // mean time between scan messages

unsigned long bot_lasttime; // last time messages' scan has been done
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

bool flashState = LOW;

camera_fb_t *fb = NULL;

bool isMoreDataAvailable();
byte *getNextBuffer();
int getNextBufferLen();

bool dataAvailable = false;

void handleNewMessages(int numNewMessages)
{
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    String from_name = bot.messages[i].from_name;
    if (from_name == "")
      from_name = "Guest";

    if (text == "/on")    {
      flashState = !flashState;
      digitalWrite(FLASH_LED_PIN, HIGH);
    }
    else if (text == "/off")    {
      flashState = !flashState;
      digitalWrite(FLASH_LED_PIN, LOW);
    }

    else if (text == "/photo")    {
      fb = NULL;
      // Take Picture with Camera
      fb = esp_camera_fb_get();
      if (!fb)  {
        Serial.println("Camera capture failed");
        bot.sendMessage(chat_id, "Camera capture failed", "");
        return;
      }
      dataAvailable = true;
      Serial.println("Sending");
      bot.sendPhotoByBinary(chat_id, "image/jpeg", fb->len,
                            isMoreDataAvailable, nullptr,
                            getNextBuffer, getNextBufferLen);

      //Serial.println("done!");

      esp_camera_fb_return(fb);
    }

    else if (text == "/start") {     
      String welcome = "ESP32Cam Telegram bot.\n\n";
      welcome += "/photo : Tirar Foto\n";
      welcome += "/on : LED ON!\n";
      welcome += "/off : LED OFF!\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}

bool isMoreDataAvailable(){
  if (dataAvailable)  {
    dataAvailable = false;
    return true;
  }
  else  {
    return false;
  }
}

byte *getNextBuffer(){
  if (fb)  {
    return fb->buf;
  }
  else  {
    return nullptr;
  }
}

int getNextBufferLen(){
  if (fb)  {
    return fb->len;
  }
  else  {
    return 0;
  }
}

void setup(){
  Serial.begin(115200);
  Serial.println();

  pinMode(FLASH_LED_PIN, OUTPUT);
  digitalWrite(FLASH_LED_PIN, flashState); //defaults to low

  if (!setupCamera())  {
    Serial.println("Camera Setup Failed!");
    while (true)    {
      delay(100);
    }
  }

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  

  // Make the bot wait for a new message for up to 60seconds
  bot.longPoll = 60;
}

void loop(){
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("Chegou algo!!!");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}
