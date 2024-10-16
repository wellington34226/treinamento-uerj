#include "Exercicios.h"

#ifdef ESP_32
// #include "esp32-hal-gpio.h"
#include <WiFiClient.h>
#include <HTTPClient.h>
#elif defined(ESP_8266)
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#else
#error "PLACA NÃO DEFINIDA, USE: ESP_32 OU ESP_8266"
#endif

uint32_t last = 0;
uint32_t wait = 5000; // 5 segundos

WiFiClient client;
HTTPClient http;

uint8_t led1 = 0; // estado do LED1
uint8_t led2 = 0; // estado do LED2

void setup()
{
  Serial.begin(SERIAL_RATE);
  pinMode(pinLed1, OUTPUT);
  digitalWrite(pinLed1, LOW);
  pinMode(pinLed2, OUTPUT);
  digitalWrite(pinLed2, LOW);

  uint32_t time_past = 0;
  uint32_t time_s = 0;
  uint32_t time_ns = 0;
  String msg;
  uint8_t contaFalhas = 0;
  while (!(Serial && LittleFS.begin()))
  {
    delay(1000);
    contaFalhas++;
    if (contaFalhas > 10)
    {
      if (Serial)
      {
        Serial.println(F("Não foi possível iniciar o sistema de arquivos"));
      }
      ESP.restart();
    }
  }
  // carrega as configurações iniciais da rede sem fio
  File file2load = LittleFS.open(config_path, "r");
  StaticJsonDocument<1024> config;
  DeserializationError error;
  if (file2load)
  {
    msg = file2load.readString();
    file2load.close();
    error = deserializeJson(config, msg);
    if (!error)
    {
      if (!config["w"]["s"].isNull())
      {
        if (config["w"]["s"].as<const char *>() != NULL)
        {
          msg = config["w"]["s"].as<const char *>();
          if (msg.length() > 0)
          {
            if (!msg.equalsIgnoreCase("null"))
            {
              ssid = msg;
            }
          }
        }
      }
      if (!config["w"]["p"].isNull())
      {
        if (config["w"]["p"].as<const char *>() != NULL)
        {
          msg = config["w"]["p"].as<const char *>();
          if (!msg.equalsIgnoreCase("null"))
          {
            pass = msg;
          }
        }
      }
      if (ssid.length() == 0)
      {
        if (!config["s"].isNull())
        {
          if (!config["s"]["0"].isNull())
          {
            if (!config["s"]["0"]["s"].isNull())
            {
              if (config["s"]["0"]["s"].as<const char *>() != NULL)
              {
                msg = config["s"]["0"]["s"].as<const char *>();
                if (msg.length() > 0)
                {
                  if (!msg.equalsIgnoreCase("null"))
                  {
                    ssid = msg;
                  }
                }
              }
            }
            if (!config["s"]["0"]["p"].isNull())
            {
              if (config["s"]["0"]["p"].as<const char *>() != NULL)
              {
                msg = config["s"]["0"]["p"].as<const char *>();
                if (!msg.equalsIgnoreCase("null"))
                {
                  pass = msg;
                }
              }
            }
          }
        }
      }
      Serial.println(F("Configurações iniciais carregadas!"));
    }
  }
  else
  {
    Serial.println(F("Não foi possível abrir o arquivo de configuração!"));
  }
#ifdef ESP_32
  tela.begin(80000000);
  Serial.println("ILI9341 Test!");
  // read diagnostics (optional but can help debug problems)
  uint8_t x;
  x = tela.readcommand8(ILI9341_RDDID);
  msg = String(F("Display identification information: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDDST);
  msg = String(F("Display Status: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDMODE);
  msg = String(F("Display Power Mode: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDMADCTL);
  msg = String(F("MADCTL Mode: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDPIXFMT);
  msg = String(F("Pixel Format: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDIMGFMT);
  msg = String(F("Image Format: 0x")) + String(x, HEX);
  Serial.println(msg);
  x = tela.readcommand8(ILI9341_RDSELFDIAG);
  msg = String(F("Self Diagnostic: 0x")) + String(x, HEX);
  Serial.println(msg);
  delay(100);

  Serial.println(F("Benchmark                Time"));
  time_past = testFillScreen();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Screen fill              ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testText();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Text                     ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(3000);

  time_past = testLines(ILI9341_CYAN);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Lines                    ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testFastLines(ILI9341_RED, ILI9341_BLUE);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Horiz/Vert Lines         ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testRects(ILI9341_GREEN);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Rectangles (outline)     ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Rectangles (filled)      ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testFilledCircles(10, ILI9341_MAGENTA);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Circles (filled)         ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);

  time_past = testCircles(10, ILI9341_WHITE);
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Circles (outline)        ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testTriangles();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Triangles (outline)      ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testFilledTriangles();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Triangles (filled)       ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testRoundRects();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Rounded rects (outline)  ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testFilledRoundRects();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = String(F("Rounded rects (filled)   ")) + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  Serial.println(F("Done!"));
#elif defined(ESP_8266)
  pinMode(pinLed3, OUTPUT);
  digitalWrite(pinLed3, LOW);
  pinMode(pinECGs, INPUT);
  pinMode(pinECGS, INPUT);
  pinMode(pinECGo, INPUT);

  while (!tela.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.print(".");
    delay(10000);
    contaFalhas++;
    if (contaFalhas > 10)
    {
      Serial.println(F("Não foi possível iniciar tela OLED --> Mais de 10 falhas consecutivas!\n"));
      contaFalhas = 0;
      ESP.restart();
      while (1)
        ;
    }
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  tela.display();
  delay(500);

  Serial.println(F("SSD1306 Test!"));
  Serial.println(F("Benchmark                Time"));
  time_past = testdrawline();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw line                ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawrect();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Rect                ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testfillrect();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Fill Rect           ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawcircle();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Circle              ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testfillcircle();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Fill Circle         ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawroundrect();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Round Rect          ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testfillroundrect();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Fill Round Rect     ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawtriangle();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Triangle            ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testfilltriangle();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Fill Triangle       ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawchar();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Char                ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testdrawstyles();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Styles              ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  time_past = testscrolltext();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Scroll Text              ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);

  // Invert and restore display, pausing in-between
  tela.invertDisplay(true);
  delay(500);
  tela.invertDisplay(false);
  delay(500);

  time_past = testdrawbitmap();
  time_s = time_past / 1e6;
  time_ns = (time_past - (time_s * 1e6)) * 1e3;
  msg = F("Draw Bitmap              ") + GetExecutionTime(time_s, time_ns);
  Serial.println(msg);
  delay(500);
  // Initialize 'snowflake' positions
  for (f = 0; f < NUMFLAKES; f++)
  {
    icons[f][XPOS] = random(1 - LOGO_WIDTH, tela.width());
    icons[f][YPOS] = -LOGO_HEIGHT;
    icons[f][DELTAY] = random(1, 6);
  }
#endif
}
void loop()
{
  String msg;
  if ((millis() - last) >= wait)
  {
    if (SetWifi())
    {
      uint32_t start = micros();
      http.begin(client, F("http://152.92.181.90:8080/CadastroPrimario/EstadosLeds"));
      http.addHeader(F("Content-Type"), F("application/x-www-form-urlencoded"));
      int httpResponseCode = http.GET();
      String httpResponse = http.getString();
      msg = String(F("Response código: ")) + String(httpResponseCode) + String(F(" mensagem: ")) + httpResponse;
      Serial.println(msg);

      if (httpResponseCode == 200)
      {
        StaticJsonDocument<64> doc_json;
        DeserializationError error = deserializeJson(doc_json, httpResponse);
        if (error)
        {
          Serial.println(F("Falha ao ler dados JSON!"));
        }
        else
        {
          led1 = doc_json["led01"];
          led2 = doc_json["led02"];
          digitalWrite(pinLed1, led1 ? HIGH : LOW);
          digitalWrite(pinLed2, led2 ? HIGH : LOW);
#ifdef ESP_8266
          digitalWrite(pinLed3, (led1 + led2) ? LOW : HIGH);
#endif
          msg = String(F("Documento JSON capacidade da memória: ")) + String(doc_json.capacity()) + String(F(" memória utilizada: ")) + String(doc_json.memoryUsage());
          Serial.println(msg);
        }
      }
      http.end();
      uint32_t time_past = micros() - start;
      uint32_t time_s = time_past / 1e6;
      uint32_t time_ns = (time_past - (time_s * 1e6)) * 1e3;
      msg = String(F("Tempo total de ")) + GetExecutionTime(time_s, time_ns);
      Serial.println(msg);
    }
    last = millis();
  }
  msg = "LED1:O" + String(led1 ? "N" : "FF") + "  LED2:O" + String(led2 ? "N" : "FF");
#ifdef ESP_32
  // a point object holds x y and z coordinates
  // TSPoint p = ts.getPoint();
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  // if (p.z > ts.pressureThreshhold) {
  //   Serial.print("X = "); Serial.print(p.x);
  //   Serial.print("\tY = "); Serial.print(p.y);
  // }else{
  //   Serial.print("\tPressure = "); Serial.println(p.z);
  // }
  tela.setRotation(rotation);
  testText();
  rotation++;
  if (rotation > 3)
  {
    rotation = 0;
  }
  tela.setTextColor(ILI9341_BLUE);
  tela.setTextSize(2);
  tela.println(msg);
#elif defined(ESP_8266)
  tela.clearDisplay(); // Clear the display buffer
  // Draw text
  tela.setTextSize(1);
  tela.setTextColor(SSD1306_WHITE);
  tela.setCursor(0, 0);
  tela.println(msg);
  if ((digitalRead(pinECGs) == 0) && (digitalRead(pinECGS) == 0))
  {
    ecg_value = analogRead(pinECGo);
  }
  msg = F("ECG: ") + String(ecg_value);
  tela.println(msg);
  // // Draw each snowflake:
  // for(f=0; f< NUMFLAKES; f++) {
  //   tela.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
  // }
  // tela.display(); // Show the display buffer on the screen
  // // Then update coordinates of each flake...
  // for(f=0; f< NUMFLAKES; f++) {
  //   icons[f][YPOS] += icons[f][DELTAY];
  //   // If snowflake is off the bottom of the screen...
  //   if (icons[f][YPOS] >= tela.height()) {
  //     // Reinitialize to a random position, just off the top
  //     icons[f][XPOS]   = random(1 - LOGO_WIDTH, tela.width());
  //     icons[f][YPOS]   = -LOGO_HEIGHT;
  //     icons[f][DELTAY] = random(1, 6);
  //   }
  // }
#endif
  delay(1000);
}