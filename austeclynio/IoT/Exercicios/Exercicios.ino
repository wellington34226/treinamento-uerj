#include "Exercicios.h"

#ifdef ESP_32
  //#include "esp32-hal-gpio.h"
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>
#elif defined(ESP_8266)
  #include <ESP8266WiFi.h>
  #include <WiFiClient.h>
  #include <ESP8266HTTPClient.h>
#else
  #error "PLACA NÃO DEFINIDA, USE: ESP_32 OU ESP_8266"
#endif

#include <ArduinoJson.h>

#ifdef LCC
  #define WIFISSID "LCC-Laboratorio"
  #define PASSWORD "L@b0r@t0r10"
#elif defined(HOME)
  #define WIFISSID "Jade-2.4G"
  #define PASSWORD "27151211freitascosta"
#elif defined(INOV1)
  #define WIFISSID "INOVUERJ_LACIPI"
  #define PASSWORD "feudodoinov"
#elif defined(INOV2)
  #define WIFISSID "InovUerj_Guest"
  #define PASSWORD "feudodathay"
#else
  #define WIFISSID "JadeCel"
  #define PASSWORD "jademucura1203"
#endif

uint32_t last = 0;
uint32_t wait = 5000;//5 segundos

WiFiClient client;
HTTPClient http;
uint8_t contaFalhas=0;
const char* host = "http://152.92.181.90:8080/CadastroPrimario/EstadosLeds";   // Endereço do servidor e caminho, pode ser ipaddress 

StaticJsonDocument<1024> doc;

#ifdef ESP_32
  #include <SPI.h>
  #include <TouchScreen.h>
  #include <Adafruit_ILI9341.h>
  // DEFINIÇÕES DOS PINOS
  #define TFT_CS 32
  #define TFT_RST 2
  #define TFT_DC 33
  #define TFT_MOSI 13
  #define TFT_CLK 14
  #define TFT_MISO 12
  #define TFT_TCS 26
  #define TFT_TIRQ  27
  // DEFINIÇÕES DO TOUCH
  #define XMAX A0
  #define YMAX A3
  #define XMIN 4
  #define YMIN 5
  #define RESISTENCIA 300
  // DEFINIÇÕES DE CORES
  #define WHITE          0xFFFF
  #define YELLOW         0xFFE0
  #define RED            0xF800
  #define BLUE           0x001F
  #define BLACK          0x0000
  // DEFINIÇÕES DOS ESTADOS
  #define LIGADO         0x07E0
  #define DESLIGADO      0xF800

  Adafruit_ILI9341 tela = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
  //TouchScreen ts = TouchScreen(XMAX,YMAX,XMIN,YMIN,RESISTENCIA);
  uint8_t rotation = 0;
  uint8_t pinLed1 = 4;//LED 1 portas GPIO4
  uint8_t pinLed2 = 25;//LED 2 portas D5 GPIO25
#elif defined(ESP_8266)
  #include <Wire.h>
  #include <Adafruit_SSD1306.h>//baixar do gerenciador de bibliotecas e confirmar a instalação das demais dependências
  // DEFINIÇÕES
  #define SSD1306_NO_SPLASH // desativa SPLASH
  #define SSD1306_128_32 // tamanho do display
  #define SCREEN_ADDRESS 0x3C// endereço I2C do display
  #define OLED_RESET -1  // pino para reinicialização # (-1 para compartilhar o pino de reset do Arduino)
  #define SCREEN_WIDTH 128// Definir largura da tela em pixels
  #define SCREEN_HEIGHT 32// Definir altura da tela em pixels
  #define SCREEN_ADDRESS 0x3C// endereço I2C do display
  #define OLED_RESET -1  // pino para reinicialização # (-1 para compartilhar o pino de reset do Arduino)
  #define GRAFICOS 3  // Definir quantidade de gráficos a serem plotados (máximo de 16 saídas)
  #define VLARGURA 30 // espaçamento horizontal do eixo vertical 
  #define VALTURA 8   // largura do TIC do eixo vertical
  #define TLARGURA 5  // espaçamento vertical do eixo vertical
  #define GAPGRAFICO 2   // espaçamento horizontal entre o eixo vertical e o gráfico
  #define GLARGURA (SCREEN_WIDTH-VLARGURA-GAPGRAFICO) // largura da área do gráfico (cada ponto do gráfico utiliza 3 pixels, foi necessário devido ao uso de memória)
  #define NUMFLAKES     10 // Number of snowflakes in the animation example
  #define LOGO_HEIGHT   16
  #define LOGO_WIDTH    16
  static const unsigned char PROGMEM logo_bmp[] =
  { 0b00000000, 0b11000000,
    0b00000001, 0b11000000,
    0b00000001, 0b11000000,
    0b00000011, 0b11100000,
    0b11110011, 0b11100000,
    0b11111110, 0b11111000,
    0b01111110, 0b11111111,
    0b00110011, 0b10011111,
    0b00011111, 0b11111100,
    0b00001101, 0b01110000,
    0b00011011, 0b10100000,
    0b00111111, 0b11100000,
    0b00111111, 0b11110000,
    0b01111100, 0b11110000,
    0b01110000, 0b01110000,
    0b00000000, 0b00110000
  };
  Adafruit_SSD1306 tela(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  int8_t f, icons[NUMFLAKES][3];
  uint8_t pinLed1 = 16;//LED 1 porta D0 GPIO16
  uint8_t pinLed2 = 14;//LED 2 porta D5 GPIO14
  uint8_t pinLed3 = 12;//LED 2 porta D6 GPIO12
  uint8_t pinECGs = 0;//ECG LO- porta D3 GPIO0
  uint8_t pinECGS = 2;//ECG LO+ porta D4 GPIO2
  uint8_t pinECGo = A0;//ECG OUTPUT porta A0
  int ecg_value = 0;//valor lido ECG
#else
  #error "PLACA NÃO DEFINIDA, USE: ESP_32 OU ESP_8266"
#endif
#include <Adafruit_GFX.h>

int led1  = 0;//estado do LED1
int led2  = 0;//estado do LED2

void setup() {
  Serial.begin(SERIAL_RATE);
  Serial.print("\nConectando a ");
  Serial.println(WIFISSID);
  WiFi.begin(WIFISSID, PASSWORD);

  pinMode(pinLed1,OUTPUT);
  digitalWrite(pinLed1,LOW);
  pinMode(pinLed2,OUTPUT);
  digitalWrite(pinLed2,LOW);
  delay(1000);

  uint32_t time_past = 0;
  uint32_t time_s = 0;
  uint32_t time_ns = 0;
  String msg;
  #ifdef ESP_32
    tela.begin();

    Serial.println("ILI9341 Test!"); 
    // read diagnostics (optional but can help debug problems)
    uint8_t x = tela.readcommand8(ILI9341_RDMODE);
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
    
    Serial.println(F("Benchmark                Time"));
    delay(100);
    time_past = testFillScreen();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Screen fill              ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testText();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Text                     ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(3000);

    time_past = testLines(ILI9341_CYAN);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Lines                    ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testFastLines(ILI9341_RED, ILI9341_BLUE);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Horiz/Vert Lines         ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testRects(ILI9341_GREEN);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Rectangles (outline)     ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Rectangles (filled)      ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testFilledCircles(10, ILI9341_MAGENTA);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Circles (filled)         ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);

    time_past = testCircles(10, ILI9341_WHITE);
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Circles (outline)        ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testTriangles();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Triangles (outline)      ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testFilledTriangles();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Triangles (filled)       ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testRoundRects();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Rounded rects (outline)  ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testFilledRoundRects();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = String(F("Rounded rects (filled)   ")) + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    Serial.println(F("Done!"));
  #elif defined(ESP_8266)
    #define XPOS   0 // Indexes into the 'icons' array in function below
    #define YPOS   1
    #define DELTAY 2
    pinMode(pinLed3,OUTPUT);
    digitalWrite(pinLed3,LOW);
    pinMode(pinECGs,INPUT);
    pinMode(pinECGS,INPUT);
    pinMode(pinECGo,INPUT);
    //analogRead(pinECGo);

    contaFalhas = 0;
    while(!tela.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.print(".");
      delay(10000);
      contaFalhas++;
      if (contaFalhas>10){
        Serial.println(F("Não foi possível iniciar tela OLED --> Mais de 10 falhas consecutivas!\n"));
        contaFalhas=0;
        ESP.restart();
        while(1);
      }
    }
    Serial.println("SSD1306 Test!"); 
    Serial.println(F("Benchmark                Time"));
    delay(100);
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    tela.display();
    delay(500);

    time_past = testdrawline();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw line                ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawrect();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Rect                ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testfillrect();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Fill Rect           ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawcircle();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Circle              ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testfillcircle();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Fill Circle         ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawroundrect();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Round Rect          ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testfillroundrect();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Fill Round Rect     ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawtriangle();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Triangle            ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testfilltriangle();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Fill Triangle       ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawchar();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Char                ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testdrawstyles();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Styles              ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    time_past = testscrolltext();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Scroll Text              ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);

    // Invert and restore display, pausing in-between
    tela.invertDisplay(true);
    delay(500);
    tela.invertDisplay(false);
    delay(500);

    time_past = testdrawbitmap();
    time_s = time_past/1e6;
    time_ns = (time_past-(time_s*1e6))*1e3;
    msg = F("Draw Bitmap              ") + GetExecutionTime(time_s,time_ns);
    Serial.println(msg);
    delay(500);
     // Initialize 'snowflake' positions
    for(f=0; f< NUMFLAKES; f++) {
      icons[f][XPOS]   = random(1 - LOGO_WIDTH, tela.width());
      icons[f][YPOS]   = -LOGO_HEIGHT;
      icons[f][DELTAY] = random(1, 6);
    }
  #endif
  contaFalhas = 0;
  while (WiFi.status() != WL_CONNECTED) {    
    Serial.print(".");
    delay(10000);
    contaFalhas++;
    if (contaFalhas>10){
      Serial.println(F("Não foi possível conectar a Wifi--> Mais de 10 falhas consecutivas!\n"));
      contaFalhas=0;
      ESP.restart();
      while(1);
     }
  }
  
  Serial.print(F("Conectado a rede WiFi network com IP Address: "));
  Serial.println(WiFi.localIP());
}
void loop(){
  String msg;
  if((millis()-last)>=wait){
    if(WiFi.status()== WL_CONNECTED){
      uint32_t start = micros();
      http.begin(client,host); 
      http.addHeader("Content-Type", F("application/x-www-form-urlencoded"));
      int httpResponseCode = http.GET();
      String httpResponse = http.getString();
      msg = String(F("Response Code: ")) + String(httpResponseCode) + String(F("\nResponse: ")) + httpResponse;
      Serial.println(msg);

      if(httpResponseCode==200){
        DeserializationError error = deserializeJson(doc,httpResponse);
        if (error) {
          Serial.println(F("JSON parsing failed!"));
        }else{
          led1 = doc["led01"];
          led2 = doc["led02"];
          digitalWrite(pinLed1,led1?HIGH:LOW);
          digitalWrite(pinLed2,led2?HIGH:LOW);
          #ifdef ESP_8266
            digitalWrite(pinLed3,(led1+led2)?LOW:HIGH);
          #endif
          msg = String(F("Capacidade da Memoria: ")) + String(doc.capacity()) + String(F("\nMemoria utilizada: ")) + String(doc.memoryUsage());
          Serial.println(msg);
        }
      }
      http.end();
      uint32_t time_past = micros()-start;
      uint32_t time_s = time_past/1e6;
      uint32_t time_ns = (time_past-(time_s*1e6))*1e3;
      msg = String(F("Tempo total de ")) + GetExecutionTime(time_s,time_ns);
      Serial.println(msg);
    }
    last = millis();
  }
  msg = "LED1:O" + String(led1?"N":"FF") + "  LED2:O" + String(led2?"N":"FF");
  #ifdef ESP_32
    // a point object holds x y and z coordinates
    //TSPoint p = ts.getPoint();
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
    if(rotation>3){
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
    if((digitalRead(pinECGs)==0) && (digitalRead(pinECGS)==0)){
      ecg_value = analogRead(pinECGo);
    }
    msg = F("ECG: ") + String(ecg_value);
    tela.println(msg);
    // Draw each snowflake:
    for(f=0; f< NUMFLAKES; f++) {
      tela.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
    }
    tela.display(); // Show the display buffer on the screen
    // Then update coordinates of each flake...
    for(f=0; f< NUMFLAKES; f++) {
      icons[f][YPOS] += icons[f][DELTAY];
      // If snowflake is off the bottom of the screen...
      if (icons[f][YPOS] >= tela.height()) {
        // Reinitialize to a random position, just off the top
        icons[f][XPOS]   = random(1 - LOGO_WIDTH, tela.width());
        icons[f][YPOS]   = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
      }
    }
  #endif
  delay(1000);
}
