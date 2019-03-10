#ifndef ENTITY_H
#define ENTITY_H

#include <Arduino.h>
#include "Graphics.h"
#include "Rectangle.h"

class Entity{
  private:
    int _xVel = 0, _yVel = 0;
    Rectangle _rectangle;
    bool _living;
    
  public:
    Entity(byte x, byte y);
    Entity(byte c, byte y, byte w, byte h);
    virtual void loop();
    void setup();
    virtual void draw(Graphics* g);
    Rectangle* getRectangle(){return &_rectangle;};
    void setLiving(bool l) {_living = l;};
    bool isLiving() { return _living;};
    
};

#endif
