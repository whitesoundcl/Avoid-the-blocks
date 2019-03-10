#include "UserInterface.h"

UserInterface::UserInterface(byte screenWidth, byte screenHeight)
{
    _sWidth = screenWidth;
    _sHeight = screenHeight;
}

void UserInterface::draw(Graphics *gfx)
{
    if(!_visible) {
        return;
    } 
    gfx->setFont(u8g2_font_u8glib_4_tf);
    gfx->setCursor(0, _sHeight);
    gfx->getU8g2().print(_deaths);
    if (_death)
    {
        for (byte i = 0; i < _currentLine; i++)
        {
            gfx->drawLine(0,i, _sWidth, i);
        }
    }
}

void UserInterface::setDeaths(int d)
{
    _deaths = d;
}

void UserInterface::setVisible(bool visible)
{
    _visible = visible;
}

void UserInterface::update()
{
    if (_death)
    {
        if (_currentLine > 0)
        {
            if (_currentLine >= _sHeight)
            {
                _filling = false;
            }
        }
        else if( !_filling)
        {
            _death = false;
        }

        if (_filling)
        {
            _currentLine+=20;
        }
        else
        {
            _currentLine-=20;
        }
    }
}

void UserInterface::setDeath(bool d)
{
    _death = d;
    _framesRemaining = (_sHeight * 2)/4;
    _filling = true;
    _currentLine = 0;
}
