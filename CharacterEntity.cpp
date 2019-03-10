#include "CharacterEntity.h"

CharacterEntity::CharacterEntity(byte x, byte y) : Entity(x, y)
{
}

CharacterEntity::CharacterEntity(byte x, byte y, byte w, byte h) : Entity(x, y, w, h)
{
}
void CharacterEntity::setup()
{
}

void CharacterEntity::draw(Graphics *g)
{
  for (byte i = getRectangle()->getX(); i <= getRectangle()->getX2() ; i++)
  {
    g->drawPixel(i, getRectangle()->getY());
  }
}

void CharacterEntity::loop()
{
}
