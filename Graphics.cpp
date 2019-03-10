#include "Graphics.h"


Graphics::Graphics(byte screenWidth, byte screenHeight){
  //U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);
  _screenWidth = screenWidth;
  _screenHeight = screenHeight;
  U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
  _u8g2 = u8g2;
  _u8g2.begin(); 
  _u8g2.setFont(u8g2_font_ncenB10_tr);
}

void Graphics::drawPixel(byte x, byte y){
  if(x >= 0 && x <= _screenWidth && y >= 0 && y <= _screenHeight){
    _u8g2.drawPixel(x, y);
  }
}

void Graphics::drawLine(byte x1, byte y1, byte x2, byte y2){
  _u8g2.drawLine(x1,y1,x2,y2);
}

void Graphics::drawRect(byte x, byte y, byte width, byte height){
}
/*
void Graphics::clear(){
  _u8g2.setFont(u8g2_font_ncenB14_tr);
}
*/
void Graphics::setFont(const uint8_t *font){
  _u8g2.setFont(font);
}
/*
void Graphics::terminalPrint(String texto){
  //_u8x8log.println(texto);
}
*/
void Graphics::drawStr(byte x, byte y ,const char *text) {
  _u8g2.drawStr(x,y,text);
}
void Graphics::firstPage() {
  _u8g2.firstPage();
 
}
bool Graphics::nextPage(){
  return _u8g2.nextPage();
}

U8G2 Graphics::getU8g2(){
  return _u8g2;
}

void Graphics::setCursor(byte x, byte y) {
  _u8g2.setCursor(x,y);
}