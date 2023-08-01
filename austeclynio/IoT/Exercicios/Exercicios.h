#define HOME
#define ESP_32
#define SERIAL_RATE 115200 // velocidade da serial

float digitalToVolts(uint16_t digital){
  return (3.3*float(digital))/1023;
};
uint16_t voltsToDigital(float volts){
  return uint16_t((1023*volts)/3.3);
};

String GetExecutionTime(uint32_t time_s,uint32_t time_ns){
  String time_converted = "";
  uint32_t meses = 0;
  uint32_t semanas = 0;
  uint32_t dias = 0;
  uint32_t horas = 0;
  uint32_t minutos = 0;
  uint32_t segundos = time_s;
  uint32_t milissegundos = 0;
  uint32_t microssegundos = 0;
  uint32_t nanossegundos = time_ns;
  if(nanossegundos>=1e3){
    microssegundos = uint32_t(nanossegundos/1e3);
    nanossegundos -= uint32_t(microssegundos*1e3);
    if(microssegundos>=1e3){
      milissegundos  = uint32_t(microssegundos/1e3);
      microssegundos -= uint32_t(milissegundos*1e3);
      if(milissegundos>=1e3){
        segundos  += uint32_t(milissegundos/1e3);
        milissegundos -= uint32_t(segundos*1e3);
      }
    }
  }
  if(segundos >= 60){
    minutos = uint32_t(segundos/60);
    segundos -= uint32_t(minutos*60);
    if(minutos >= 60){
      horas = uint32_t(minutos/60);
      minutos -= uint32_t(horas*60);
      if(horas >= 24){
        dias = uint32_t(horas/24);
        horas -= uint32_t(dias*24);
        if(dias >= 30){
          meses = uint32_t(dias/30);
          dias -= uint32_t(meses*30);
        }
        if(dias >= 7){
          semanas = uint32_t(dias/7);
          dias -= uint32_t(semanas*7);
        }
      }
    }
  }
  if(meses>0){
    time_converted += String(meses) + " mes";
    if(meses>1){
      time_converted += "es";
    }
    if(semanas>0){
      time_converted += ", " + String(semanas) + " semana";
      if(semanas>1){
        time_converted += "s";
      }
    }
    if(dias>0){
      time_converted += ", " + String(dias) + " dia";
      if(dias>1){
        time_converted += "s";
      }
    }
    if(horas>0){
      time_converted += ", " + String(horas) +"h";
    }
    if(minutos>0){
      time_converted += ", " + String(minutos) +"min";
    }
    /*
    if(segundos>0){
      time_converted += ", " + String(segundos) +"s";
    }
    if(milissegundos>0){
      time_converted += ", " + String(milissegundos) + "ms";
    }
    if(microssegundos>0){
      time_converted += ", "  + String(microssegundos) + "us";
    }
    */
  }else{
    if(semanas>0){
      time_converted += String(semanas) + " semana";
      if(semanas>1){
        time_converted += "s";
      }
      if(dias>0){
        time_converted += ", " + String(dias) + " dia";
        if(dias>1){
          time_converted += "s";
        }
      }
      if(horas>0){
        time_converted += ", " + String(horas) + "h";
      }
      if(minutos>0){
        time_converted += ", " + String(minutos) + "min";
      }
      if(segundos>0){
        time_converted += ", " + String(segundos) + "s";
      }
      /*
      if(milissegundos>0){
        time_converted += ", " + String(milissegundos) + "ms";
      }
      if(microssegundos>0){
        time_converted += ", " + String(microssegundos) + "us";
      }
      */
    }else{
      if(dias>0){
        time_converted += String(dias) + " dia";
        if(dias>1){
          time_converted += "s";
        }
        if(horas>0){
          time_converted += ", " + String(horas) + "h";
        }
        if(minutos>0){
          time_converted += ", " + String(minutos) + "min";
        }
        if(segundos>0){
          time_converted += ", " + String(segundos) + "s";
        }
        /*
        if(milissegundos>0){
          time_converted += ", " + String(milissegundos) + "ms";
        }
        if(microssegundos>0){
          time_converted += ", " + String(microssegundos) + "us";
        }
        */
      }else{
        if(horas>0){
          time_converted += String(horas) + "h";
          if(minutos>0){
            time_converted += ", " + String(minutos) + "min";
          }
          if(segundos>0){
            time_converted += ", " + String(segundos) + "s";
          }
          /*
          if(milissegundos>0){
            time_converted += ", " + String(milissegundos) + "ms";
          }
          if(microssegundos>0){
            time_converted += ", " + String(microssegundos) + "us";
          }
          */
        }else{
          if(minutos>0){
            time_converted += String(minutos) + "min";
            if(segundos>0){
              time_converted += ", " + String(segundos) + "s";
            }
            if(milissegundos>0){
              time_converted += ", " + String(milissegundos) + "ms";
            }
            if(microssegundos>0){
              time_converted += ", " + String(microssegundos) + "us";
            }
          }else{
            if(segundos>0){
              time_converted += String(segundos) + "s";
              if(milissegundos>0){
                time_converted += ", " + String(milissegundos) + "ms";
              }
              if(microssegundos>0){
                time_converted += ", " + String(microssegundos) + "us";
              }
            }else{
              if(milissegundos>0){
                time_converted += String(milissegundos) + "ms";
                if(microssegundos>0){
                  time_converted += ", " + String(microssegundos) + "us";
                }
              }else{
                if(microssegundos>0){
                  time_converted += String(microssegundos) + "us";
                }
              }
            }
          }
        }
      }
    }
  }
  return time_converted;
};
#ifdef ESP_32
  uint32_t testFillScreen() {
    uint32_t start = micros();
    tela.fillScreen(ILI9341_BLACK);
    yield();
    tela.fillScreen(ILI9341_RED);
    yield();
    tela.fillScreen(ILI9341_GREEN);
    yield();
    tela.fillScreen(ILI9341_BLUE);
    yield();
    tela.fillScreen(ILI9341_BLACK);
    yield();
    return micros() - start;
  }

  uint32_t testText() {
    uint32_t start = micros();
    tela.fillScreen(ILI9341_BLACK);
    tela.setCursor(0, 0);
    tela.setTextColor(ILI9341_WHITE); tela.setTextSize(1);tela.println("Hello World!");
    tela.setTextColor(ILI9341_YELLOW);tela.setTextSize(2);tela.println(1234.56);
    tela.setTextColor(ILI9341_RED);   tela.setTextSize(3);tela.println("OutrO TexTO");
    tela.setTextColor(ILI9341_BLUE);  tela.setTextSize(4);tela.print("0x");tela.println(0xDEADBEEF, HEX);
    tela.setTextColor(ILI9341_GREEN);
    tela.setTextSize(5);
    tela.println();
    tela.println("Groop");
    tela.setTextSize(1);
    tela.println(F("I implore thee,"));
    tela.println(F("my foonting turlingdromes."));
    tela.println(F("And hooptiously drangle me"));
    tela.println(F("with crinkly bindlewurdles,"));
    tela.println(F("Or I will rend thee"));
    tela.println(F("in the gobberwarts"));
    tela.println(F("with my blurglecruncheon,"));
    tela.println(F("see if I don't!"));
    return micros() - start;
  }

  uint32_t testLines(uint16_t color) {
    uint32_t start = micros();
    int           x1, y1, x2, y2,
                  w = tela.width(),
                  h = tela.height();

    tela.fillScreen(ILI9341_BLACK);
    yield();
    
    x1 = y1 = 0;
    y2    = h - 1;
    for(x2=0; x2<w; x2+=6) tela.drawLine(x1, y1, x2, y2, color);
    x2    = w - 1;
    for(y2=0; y2<h; y2+=6) tela.drawLine(x1, y1, x2, y2, color);

    yield();
    tela.fillScreen(ILI9341_BLACK);
    yield();

    x1    = w - 1;
    y1    = 0;
    y2    = h - 1;
    for(x2=0; x2<w; x2+=6) tela.drawLine(x1, y1, x2, y2, color);
    x2    = 0;
    for(y2=0; y2<h; y2+=6) tela.drawLine(x1, y1, x2, y2, color);

    yield();
    tela.fillScreen(ILI9341_BLACK);
    yield();

    x1    = 0;
    y1    = h - 1;
    y2    = 0;
    for(x2=0; x2<w; x2+=6) tela.drawLine(x1, y1, x2, y2, color);
    x2    = w - 1;
    for(y2=0; y2<h; y2+=6) tela.drawLine(x1, y1, x2, y2, color);

    yield();
    tela.fillScreen(ILI9341_BLACK);
    yield();

    x1    = w - 1;
    y1    = h - 1;
    y2    = 0;
    for(x2=0; x2<w; x2+=6) tela.drawLine(x1, y1, x2, y2, color);
    x2    = 0;
    for(y2=0; y2<h; y2+=6) tela.drawLine(x1, y1, x2, y2, color);

    yield();
    return micros() - start;
  }

  uint32_t testFastLines(uint16_t color1, uint16_t color2) {
    uint32_t start = micros();
    int           x, y, w = tela.width(), h = tela.height();

    tela.fillScreen(ILI9341_BLACK);
    for(y=0; y<h; y+=5) tela.drawFastHLine(0, y, w, color1);
    for(x=0; x<w; x+=5) tela.drawFastVLine(x, 0, h, color2);

    return micros() - start;
  }

  uint32_t testRects(uint16_t color) {
    uint32_t start = micros();
    int           n, i, i2,
                  cx = tela.width()  / 2,
                  cy = tela.height() / 2;

    tela.fillScreen(ILI9341_BLACK);
    n     = min(tela.width(), tela.height());
    for(i=2; i<n; i+=6) {
      i2 = i / 2;
      tela.drawRect(cx-i2, cy-i2, i, i, color);
    }

    return micros() - start;
  }

  uint32_t testFilledRects(uint16_t color1, uint16_t color2) {
    uint32_t start = micros();
    int           n, i, i2,
                  cx = tela.width()  / 2 - 1,
                  cy = tela.height() / 2 - 1;

    tela.fillScreen(ILI9341_BLACK);
    n = min(tela.width(), tela.height());
    for(i=n; i>0; i-=6) {
      i2    = i / 2;
      tela.fillRect(cx-i2, cy-i2, i, i, color1);
      // Outlines are not included in timing results
      tela.drawRect(cx-i2, cy-i2, i, i, color2);
      yield();
    }

    return micros() - start;
  }

  uint32_t testFilledCircles(uint8_t radius, uint16_t color) {
    uint32_t start = micros();
    int x, y, w = tela.width(), h = tela.height(), r2 = radius * 2;

    tela.fillScreen(ILI9341_BLACK);
    for(x=radius; x<w; x+=r2) {
      for(y=radius; y<h; y+=r2) {
        tela.fillCircle(x, y, radius, color);
      }
    }

    return micros() - start;
  }

  uint32_t testCircles(uint8_t radius, uint16_t color) {
    uint32_t start = micros();
    int           x, y, r2 = radius * 2,
                  w = tela.width()  + radius,
                  h = tela.height() + radius;

    // Screen is not cleared for this one -- this is
    // intentional and does not affect the reported time.
    for(x=0; x<w; x+=r2) {
      for(y=0; y<h; y+=r2) {
        tela.drawCircle(x, y, radius, color);
      }
    }

    return micros() - start;
  }

  uint32_t testTriangles() {
    uint32_t start = micros();
    int           n, i, cx = tela.width()  / 2 - 1,
                        cy = tela.height() / 2 - 1;

    tela.fillScreen(ILI9341_BLACK);
    n     = min(cx, cy);
    for(i=0; i<n; i+=5) {
      tela.drawTriangle(
        cx    , cy - i, // peak
        cx - i, cy + i, // bottom left
        cx + i, cy + i, // bottom right
        tela.color565(i, i, i));
    }

    return micros() - start;
  }

  uint32_t testFilledTriangles() {
    uint32_t start = micros();
    int           i, cx = tela.width()  / 2 - 1,
                    cy = tela.height() / 2 - 1;

    tela.fillScreen(ILI9341_BLACK);
    for(i=min(cx,cy); i>10; i-=5) {
      tela.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
        tela.color565(0, i*10, i*10));
      tela.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
        tela.color565(i*10, i*10, 0));
      yield();
    }

    return micros() - start;
  }

  uint32_t testRoundRects() {
    uint32_t start = micros();
    int           w, i, i2,
                  cx = tela.width()  / 2 - 1,
                  cy = tela.height() / 2 - 1;

    tela.fillScreen(ILI9341_BLACK);
    w     = min(tela.width(), tela.height());
    for(i=0; i<w; i+=6) {
      i2 = i / 2;
      tela.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tela.color565(i, 0, 0));
    }

    return micros() - start;
  }

  uint32_t testFilledRoundRects() {
    uint32_t start = micros();
    int           i, i2,
                  cx = tela.width()  / 2 - 1,
                  cy = tela.height() / 2 - 1;

    tela.fillScreen(ILI9341_BLACK);
    for(i=min(tela.width(), tela.height()); i>20; i-=6) {
      i2 = i / 2;
      tela.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tela.color565(0, i, 0));
      yield();
    }

    return micros() - start;
  }
#elif defined(ESP_8266)
  uint32_t testdrawline() {
    uint32_t start = micros();
    int16_t i;

    tela.clearDisplay(); // Clear display buffer

    for(i=0; i<tela.width(); i+=4) {
      tela.drawLine(0, 0, i, tela.height()-1, SSD1306_WHITE);
      tela.display(); // Update screen with each newly-drawn line
      delay(1);
    }
    for(i=0; i<tela.height(); i+=4) {
      tela.drawLine(0, 0, tela.width()-1, i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    delay(250);

    tela.clearDisplay();

    for(i=0; i<tela.width(); i+=4) {
      tela.drawLine(0, tela.height()-1, i, 0, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    for(i=tela.height()-1; i>=0; i-=4) {
      tela.drawLine(0, tela.height()-1, tela.width()-1, i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    delay(250);

    tela.clearDisplay();

    for(i=tela.width()-1; i>=0; i-=4) {
      tela.drawLine(tela.width()-1, tela.height()-1, i, 0, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    for(i=tela.height()-1; i>=0; i-=4) {
      tela.drawLine(tela.width()-1, tela.height()-1, 0, i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    delay(250);

    tela.clearDisplay();

    for(i=0; i<tela.height(); i+=4) {
      tela.drawLine(tela.width()-1, 0, 0, i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    for(i=0; i<tela.width(); i+=4) {
      tela.drawLine(tela.width()-1, 0, i, tela.height()-1, SSD1306_WHITE);
      tela.display();
      delay(1);
    }

    return micros() - start;
  }

  uint32_t testdrawrect(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<tela.height()/2; i+=2) {
      tela.drawRect(i, i, tela.width()-2*i, tela.height()-2*i, SSD1306_WHITE);
      tela.display(); // Update screen with each newly-drawn rectangle
      delay(1);
    }

    return micros() - start;
  }

  uint32_t testfillrect(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<tela.height()/2; i+=3) {
      // The INVERSE color is used so rectangles alternate white/black
      tela.fillRect(i, i, tela.width()-i*2, tela.height()-i*2, SSD1306_INVERSE);
      tela.display(); // Update screen with each newly-drawn rectangle
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testdrawcircle(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<max(tela.width(),tela.height())/2; i+=2) {
      tela.drawCircle(tela.width()/2, tela.height()/2, i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testfillcircle(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=max(tela.width(),tela.height())/2; i>0; i-=3) {
      // The INVERSE color is used so circles alternate white/black
      tela.fillCircle(tela.width() / 2, tela.height() / 2, i, SSD1306_INVERSE);
      tela.display(); // Update screen with each newly-drawn circle
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testdrawroundrect(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<tela.height()/2-2; i+=2) {
      tela.drawRoundRect(i, i, tela.width()-2*i, tela.height()-2*i,
        tela.height()/4, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testfillroundrect(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<tela.height()/2-2; i+=2) {
      // The INVERSE color is used so round-rects alternate white/black
      tela.fillRoundRect(i, i, tela.width()-2*i, tela.height()-2*i,
        tela.height()/4, SSD1306_INVERSE);
      tela.display();
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testdrawtriangle(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=0; i<max(tela.width(),tela.height())/2; i+=5) {
      tela.drawTriangle(
        tela.width()/2  , tela.height()/2-i,
        tela.width()/2-i, tela.height()/2+i,
        tela.width()/2+i, tela.height()/2+i, SSD1306_WHITE);
      tela.display();
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testfilltriangle(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    for(int16_t i=max(tela.width(),tela.height())/2; i>0; i-=5) {
      // The INVERSE color is used so triangles alternate white/black
      tela.fillTriangle(
        tela.width()/2  , tela.height()/2-i,
        tela.width()/2-i, tela.height()/2+i,
        tela.width()/2+i, tela.height()/2+i, SSD1306_INVERSE);
      tela.display();
      delay(1);
    }
    return micros() - start;
  }

  uint32_t testdrawchar(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    tela.setTextSize(1);      // Normal 1:1 pixel scale
    tela.setTextColor(SSD1306_WHITE); // Draw white text
    tela.setCursor(0, 0);     // Start at top-left corner
    tela.cp437(true);         // Use full 256 char 'Code Page 437' font

    // Not all the characters will fit on the tela. This is normal.
    // Library will draw what it can and the rest will be clipped.
    for(int16_t i=0; i<256; i++) {
      if(i == '\n') tela.write(' ');
      else          tela.write(i);
    }

    tela.display();
    return micros() - start;
  }

  uint32_t testdrawstyles(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    tela.setTextSize(1);             // Normal 1:1 pixel scale
    tela.setTextColor(SSD1306_WHITE);        // Draw white text
    tela.setCursor(0,0);             // Start at top-left corner
    tela.println(F("Hello, world!"));

    tela.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
    tela.println(3.141592);

    tela.setTextSize(2);             // Draw 2X-scale text
    tela.setTextColor(SSD1306_WHITE);
    tela.print(F("0x")); tela.println(0xDEADBEEF, HEX);

    tela.display();
    return micros() - start;
  }

  uint32_t testscrolltext(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    tela.setTextSize(2); // Draw 2X-scale text
    tela.setTextColor(SSD1306_WHITE);
    tela.setCursor(10, 0);
    tela.println(F("scroll"));
    tela.display();      // Show initial text
    delay(100);

    // Scroll in various directions, pausing in-between:
    tela.startscrollright(0x00, 0x0F);
    tela.stopscroll();
    delay(1000);
    tela.startscrollleft(0x00, 0x0F);
    tela.stopscroll();
    delay(1000);
    tela.startscrolldiagright(0x00, 0x07);
    tela.startscrolldiagleft(0x00, 0x07);
    tela.stopscroll();
    return micros() - start;
  }

  uint32_t testdrawbitmap(void) {
    uint32_t start = micros();
    tela.clearDisplay();

    tela.drawBitmap(
      (tela.width()  - LOGO_WIDTH ) / 2,
      (tela.height() - LOGO_HEIGHT) / 2,
      logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
    tela.display();
    return micros() - start;
  }
#endif