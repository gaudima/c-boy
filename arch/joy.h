//
// Created by lolka on 2/17/16.
//

#ifndef C_BOY_JOY_H
#define C_BOY_JOY_H

#include "emu.h"
#include "../windows/settings.h"

class Emu::Joy {
public:
    Joy(Emu *emu);

    void updateJoypad();

    void setGbKeyState(Emu::Settings::GbButton, bool pressed);

    uint8_t getJoypadState();

private:
    bool buttonState[8];
    Emu *emu;
};

#endif //C_BOY_JOY_H
