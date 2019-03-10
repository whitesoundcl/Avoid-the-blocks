#ifndef PLAYER_H
#define PLAYER_H
#include "Input.h"
#include <Arduino.h>
#include "CharacterEntity.h"

class Player {
    private:
        int _btn_right;
        int _btn_left;
        byte _screenWidth;
        byte _screenHeight;
        CharacterEntity *_character;
    public:
        Player(int btn_right, int btn_left, CharacterEntity* p, byte screenWidth, byte screenHeight);
        void updateControl(Input *input);
        //void setPersonaje(CharacterEntity* p);
};

#endif