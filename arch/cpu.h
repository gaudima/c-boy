//
// Created by gaudima on 20.01.2016.
//

#ifndef C_BOY_CPU_H
#define C_BOY_CPU_H

#include <iostream>
#include "emu.h"
#include <memory>

class Emu::Cpu {
public:
    class Ops;

    Cpu(Emu *emu);

    size_t clock;
    const int clockSpeed;
    struct Reg {
        union {
            struct {
                uint8_t f;
                uint8_t a;

            };
            uint16_t af;
        };
        union {
            struct {
                uint8_t c;
                uint8_t b;
            };
            uint16_t bc;
        };
        union {
            struct {
                uint8_t e;
                uint8_t d;
            };
            uint16_t de;
        };
        union {
            struct {
                uint8_t l;
                uint8_t h;
            };
            uint16_t hl;
        };
        uint16_t pc;
        uint16_t sp;
        uint16_t r;
        uint16_t m;
        uint8_t ime;
    };

    enum InterruptId {
        VBlank,
        LCD,
        Timer,
        Serial,
        Joypad
    };

    Reg r;
    bool halt;
    std::string regnop;
    bool paused;

    void reset();

    void exec();

    void runFrame();

    void requestInterrupt(InterruptId id);

    void processInterrupts();

    void serviceInterrupt(InterruptId id);

    void updateTimer(uint16_t m);

    void setTimerFreq();

    void updateDivider(uint16_t m);

private:
    Emu *emu;
    uint16_t frameClock;
    int timerClocks;
    int dividerClocks;
};


#endif //C_BOY_CPU_H
