/*******************************************************************
    A telegram bot for your ESP8266 that controls the 
    onboard LED. The LED in this example is active low.
    Parts:
    D1 Mini ESP8266 * - http://s.click.aliexpress.com/e/uzFUnIe
    (or any ESP8266 board)
      = Affilate
    If you find what I do useful and would like to support me,
    please consider becoming a sponsor on Github
    https://github.com/sponsors/witnessmenow/
    Written by Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Tindie: https://www.tindie.com/stores/brianlough/
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wifi network station credentials
const char* ssid = "ssssssssssssssssssssssss";
const char* password = "pppppppppppppppppppppppp";

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "xxxxxxxxxxxxxx:yyyyyyyyyyyyyyyyyyyyyyyyyyyy"
#define CHAT_ID "zzzzzzzzzzzzzzzz"
const unsigned long BOT_MTBS = 1000; // mean time between scan messages

//X509List cert(TELEGRAM_CERTIFICATE_ROOT); //Para o ESP8266
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN,secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

const int ledPin = 21;
int ledStatus = 0;

void handleNewMessages(int numNewMessages)
{
  Serial.print("Mensagens Capturadas: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
    Serial.print("chat_id ");
    Serial.println(chat_id);  

    String from_name = bot.messages[i].from_name;

    Serial.println(from_name);
    if (from_name == "")
      from_name = "Guest";

    if (text == "/ledon")
    {
      digitalWrite(ledPin,HIGH); // 
      ledStatus = 1;
      bot.sendMessage(chat_id, "Led is ON", "");
    }

    if (text == "/ledoff")
    {
      ledStatus = 0;
      digitalWrite(ledPin, LOW); 
      bot.sendMessage(chat_id, "Led is OFF", "");
    }

    if (text == "/status")
    {
      if (ledStatus)
      {
        bot.sendMessage(chat_id, "Led is ON", "");
      }
      else
      {
        bot.sendMessage(chat_id, "Led is OFF", "");
      }
    }

    if (text == "/start")
    {
      String welcome = "Welcome to Universal Arduino Telegram Bot library, " + from_name + ".\n";
      welcome += "This is Flash Led Bot example.\n\n";
      welcome += "/ledon : to switch the Led ON\n";
      welcome += "/ledoff : to switch the Led OFF\n";
      welcome += "/status : Returns current status of LED\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println();

  pinMode(ledPin, OUTPUT); // initialize digital ledPin as an output.
  delay(10);
  digitalWrite(ledPin, LOW); // initialize pin as off (active LOW)

  // attempt to connect to Wifi network:
 // configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
 // secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(ssid);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  
}

void loop()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("Capturei!!!");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}
