//
// Created by lolka on 2/17/16.
//

#ifndef C_BOY_JOY_H
#define C_BOY_JOY_H

#include "emu.h"

class Emu::Joy {
public:
    Joy(Emu *emu);
    void keyPressed(sf::Event::KeyEvent key);
    void keyReleased(sf::Event::KeyEvent key);

    void keyPressed(sf::Event::JoystickButtonEvent key);
    void keyReleased(sf::Event::JoystickButtonEvent key);

    void axisMove(sf::Event::JoystickMoveEvent key);
    //void keyReleased(sf::Event::JoystickMoveEvent key);

    void gbKeyPressed(Settings::GbButton);
    void gbKeyReleased(Settings::GbButton);

    uint8_t getJoypadState();

private:
    bool buttonState[8];
    Emu *emu;
};

#endif //C_BOY_JOY_H
