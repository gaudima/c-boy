//
// Created by gaudima on 2/17/16.
//

#include "joy.h"
#include "mmu.h"
#include "cpu.h"

Emu::Joy::Joy(Emu *emu) {
    this->emu = emu;
    for(int i = 0; i < 8; i++) {
        buttonState[i] = false;
    }
}

void Emu::Joy::updateJoypad() {
    for(int i = 0; i < 8; i++) {
        bool pressed = false;
        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
        if(button.vid == 0 &&
           button.pid == 0 &&
           button.axis == -1 &&
           button.axisSign == -1) {
            pressed = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)button.button);
        } else {
            for(int j = 0; j < sf::Joystick::Count; j++) {
                if(sf::Joystick::isConnected(j)) {
                    sf::Joystick::Identification id = sf::Joystick::getIdentification(j);
                    if(id.vendorId == button.vid && id.productId == button.pid) {
                        if(button.axis == -1) {
                            pressed = sf::Joystick::isButtonPressed(j, button.button);
                        } else {
                            float axisPos = sf::Joystick::getAxisPosition(j, (sf::Joystick::Axis)button.axis);
                            int sign = ((axisPos > 0) ? 1 : -1);
                            pressed = (sign == button.axisSign && abs(axisPos) > 30);
                        }
                    }
                }
            }
        }
        setGbKeyState((Settings::GbButton)i, pressed);
    }
}


void Emu::Joy::setGbKeyState(Settings::GbButton key, bool pressed) {
    if(!pressed) {
        buttonState[key] = false;
        return;
    }
    bool prevPressed = false;
    if(buttonState[key]) {
        prevPressed = true;
    }

    buttonState[key] = true;

    bool dPadButton = true;

    if(key <= 3) {
        dPadButton = false;
    }

    uint8_t keyState = emu->mmu->rbu(0xFF00);
    bool requestInterrupt = false;
    if((!dPadButton && ((keyState & 0x20) == 0)) || (dPadButton && ((keyState & 0x10) == 0))) {
        requestInterrupt = true;
    }

    if(requestInterrupt && !prevPressed) {
        emu->cpu->requestInterrupt(emu->cpu->Joypad);
    }
}

uint8_t Emu::Joy::getJoypadState() {
    updateJoypad();
    uint8_t state = emu->mmu->rbu(0xFF00);
    int shift = -1;
    state |= 0xCF;
    if((state & 0x10) != 0) {
        shift = 4;
    } else if((state & 0x20) != 0) {
        shift = 0;
    }
    if (shift >= 0) {
        for (int i = shift; i < shift + 4; i++) {
            if (buttonState[i]) {
                state &= ~(1 << (i - shift));
            } else {
                state |= (1 << (i - shift));
            }
        }
    }
    return state;
}