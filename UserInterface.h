#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "Graphics.h"

class UserInterface {
    private:
        int _deaths = 0;
        int _framesRemaining = 0;
        byte _currentLine = 0;
        bool _visible = true;
        bool _death, _filling = false;
        byte _sWidth, _sHeight;
    public:
        UserInterface(byte screenWidth, byte screenHeight);
        void draw(Graphics* gfx);
        void setDeaths(int d);
        void setVisible(bool visible);
        void update();
        void setDeath(bool d);
        bool isDeathScreen() {return _death;};
        bool isFilling() {return _filling;};

};

#endif