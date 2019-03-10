#ifndef CHARACTER_ENTITY_H
#define CHARACTER_ENTITY_H
#include <Arduino.h>
#include "Entity.h"
#include "Graphics.h"

class CharacterEntity : public Entity {
  public:
    CharacterEntity(byte x, byte y);
    CharacterEntity(byte x, byte y, byte w, byte h);
    void setup();
    void draw(Graphics* g);
    void loop();
  private:
  
};
#endif
