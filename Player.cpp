#include "Player.h"

Player::Player(int btn_right, int btn_left, CharacterEntity* p, byte screenWidth, byte screenHeight){
    pinMode(btn_right, INPUT_PULLUP);
    pinMode(btn_left, INPUT_PULLUP);
    _btn_right = btn_right;
    _btn_left = btn_left;
    _character = p;
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

}

void Player::updateControl(Input *input){
    if (input->isButtonPressed(_btn_left)) {
        if(_character->getRectangle()->getX() > 0) {
            _character->getRectangle()->setX(_character->getRectangle()->getX()-2);
        }
    }
    if (input->isButtonPressed(_btn_right)){
        if(_character->getRectangle()->getX() < _screenWidth){
            _character->getRectangle()->setX(_character->getRectangle()->getX()+2);
        }
    }
}
