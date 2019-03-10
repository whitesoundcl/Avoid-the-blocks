#include "Rectangle.h"

Rectangle::Rectangle()
{
  set(0, 0, 1, 1);
}

Rectangle::Rectangle(byte x, byte y, byte width, byte height)
{
  set(x, y, width, height);
}

void Rectangle::set(byte x, byte y, byte width, byte height)
{
  _x = x;
  _y = y;
  _width = width;
  _height = height;
}

void Rectangle::setX(byte x)
{
  _x = x;
}

void Rectangle::setY(byte y)
{
  _y = y;
}

void Rectangle::setPos(byte x, byte y)
{
  _x = x;
  _y = y;
}

byte Rectangle::getX2()
{
  return _x + _width - 1;
}

byte Rectangle::getY2()
{
  return _y + _height - 1;
}

bool Rectangle::contains(byte x, byte y)
{
  if (x >= _x && y >= _y && x <= getX2() && y <= getY2())
  {
    return true;
  }

  return false;
}

bool Rectangle::overlaps(Rectangle *rect)
{

  if (_x <= rect->getX2() && getX2() >= rect->getX()) {
    return true;
  }
  
}
