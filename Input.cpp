#include "Input.h"


bool Input::isButtonPressed(int button) {
    return digitalRead(button) == LOW;
}