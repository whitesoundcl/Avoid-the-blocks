#include "Entity.h"

Entity::Entity(byte x, byte y){
  _rectangle.set(x,y,1,1);
  
}

Entity::Entity(byte x, byte y, byte w, byte h){
  _rectangle.set(x,y,w,h);
  
}

void Entity::setup(){
  
}

void Entity::loop(){
  
}

void Entity::draw(Graphics* g){
  
}
