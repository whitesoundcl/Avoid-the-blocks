#ifndef ENEMY_ENTITY_H
#define ENEMY_ENTITY_H

#include "Entity.h"
#include "CharacterEntity.h"
#include "Graphics.h"
class EnemyEntity : public Entity {
  private: 
    byte _screenWidth, _screenHeight;
    CharacterEntity *_character;
  public:
    EnemyEntity(byte x, byte y, byte screenWidth, byte screenHeight, CharacterEntity* c);
    void setup();
    void loop();
    void draw(Graphics* g);
};

#endif
