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

void Emu::Joy::keyPressed(sf::Event::KeyEvent key) {
    for (int i = 0; i < 8; i++) {
        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
        if (button.vid == 0 && button.pid == 0 && button.button == key.code) {
            gbKeyPressed((Settings::GbButton)i);
        }
    }
}

void Emu::Joy::keyReleased(sf::Event::KeyEvent key) {
    for (int i = 0; i < 8; i++) {
        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
        if (button.vid == 0 &&
                button.pid == 0 &&
                button.axis == -1 &&
                button.axisSign == -1 &&
                button.button == key.code) {
            gbKeyReleased((Settings::GbButton)i);
        }
    }
}
//
//void Emu::Joy::keyPressed(sf::Event::JoystickButtonEvent key) {
//    for (int i = 0; i < 8; i++) {
//        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
//        sf::Joystick::Identification id = sf::Joystick::getIdentification(key.joystickId);
//        if(button.vid == id.vendorId &&
//                button.pid == id.productId &&
//                button.axis == -1 &&
//                button.axisSign == -1 &&
//                button.button == key.button) {
//            gbKeyPressed((Settings::GbButton)i);
//        }
//    }
//}
//
//void Emu::Joy::keyReleased(sf::Event::JoystickButtonEvent key) {
//    for (int i = 0; i < 8; i++) {
//        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
//        sf::Joystick::Identification id = sf::Joystick::getIdentification(key.joystickId);
//        if(button.vid == id.vendorId &&
//           button.pid == id.productId &&
//           button.axis == -1 &&
//           button.axisSign == -1 &&
//           button.button == key.button) {
//            gbKeyReleased((Settings::GbButton)i);
//        }
//    }
//}
//
//void Emu::Joy::keyPressed(sf::Event::JoystickMoveEvent key) {
////    for (int i = 0; i < 8; i++) {
////        Settings::ButtonConfig button = emu->settings->buttonConfiguration[i];
////        sf::Joystick::Identification id = sf::Joystick::getIdentification(key.joystickId);
////        if(button.vid == id.vendorId &&
////           button.pid == id.productId &&
////           button.axis == key.axis &&
////           button.axisSign == key.position &&
////           button.button == key.button) {
////            gbKeyPressed((Settings::GbButton)i);
////        }
////    }
//}
//
//void Emu::Joy::keyReleased(sf::Event::JoystickMoveEvent key) {
//
//}

void Emu::Joy::gbKeyPressed(Settings::GbButton key) {
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
    if((!dPadButton && (keyState & 0x20) == 0) || (dPadButton && (keyState & 0x10) == 0)) {
        requestInterrupt = true;
    }

    if(requestInterrupt && !prevPressed) {
        emu->cpu->requestInterrupt(emu->cpu->Joypad);
    }
}

void Emu::Joy::gbKeyReleased(Settings::GbButton key) {
    buttonState[key] = false;
}

uint8_t Emu::Joy::getJoypadState() {
    uint8_t state = emu->mmu->rbu(0xFF00);
    int shift = -1;
    if((state & 0x10) != 0) {
        state &= 0xEF;
        shift = 4;
    } else if((state & 0x20) != 0) {
        state &= 0xDF;
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