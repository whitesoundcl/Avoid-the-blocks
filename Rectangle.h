#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <Arduino.h>
class Rectangle {
  private:
    byte _x, _y, _width, _height;
  public:
    Rectangle();
    Rectangle(byte x, byte y, byte width, byte height);
    void set(byte x, byte y, byte width, byte height);
    void setX(byte x);
    void setY(byte y);
    void setPos(byte x, byte y);
    byte getX(){return _x;};
    byte getY(){return _y;};
    bool contains(byte x, byte y);
    byte getX2();
    byte getY2();
    bool overlaps(Rectangle* rect);
    
    
};

#endif
