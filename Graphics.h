#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class Graphics {
  public:
    Graphics(byte screenWidth, byte screenHeight);
    void drawPixel(byte x, byte y);
    void drawRect(byte x, byte y, byte width, byte height);
    void drawLine(byte x1, byte y1, byte x2, byte y2);
    void drawStr(byte x, byte y, const char *text);
    //void clear();
    //void terminalPrint(String texto);
    void firstPage(); // Necesario para u8g2
    bool nextPage(); // Necesario para u8g2
    void setFont(const uint8_t *font);
    void setCursor(byte x, byte y);
    U8G2 getU8g2();
    
  private:
    U8G2 _u8g2;
    byte _screenWidth, _screenHeight;

};


#endif
