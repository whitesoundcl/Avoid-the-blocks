#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(byte x, byte y, byte screenWidth, byte screenHeight, CharacterEntity* c) : Entity(x, y){
    _screenWidth = screenWidth; 
    _screenHeight = screenHeight;
    _character = c;
    setLiving(true);
}

void EnemyEntity::draw(Graphics* gfx) {
    gfx->drawPixel(getRectangle()->getX(), getRectangle()->getY());
}

void EnemyEntity::loop() {

    if(_character->getRectangle()->getX() > getRectangle()->getX()){
        getRectangle()->setX(getRectangle()->getX()+1);
    } else if (_character->getRectangle()->getX() < getRectangle()->getX()) {
        getRectangle()->setX(getRectangle()->getX()-1);
    }
    getRectangle()->setY(getRectangle()->getY()+2);
    if(getRectangle()->getY() > _screenHeight){
        setLiving(false);
    }
    
}
