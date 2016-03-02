//
// Created by gaudima on 20.01.2016.
//

#include "cpu.h"
#include "gpu.h"
#include "mmu.h"
#include "ops.h"
#include <sstream>
#include <iomanip>
#include <cstring>

Emu::Cpu::Cpu(Emu *emu) : clockSpeed(1048576) {
    this->emu = emu;
    Ops::emu = emu;
    reset();
}

void Emu::Cpu::reset() {
    frameClock = 0;
    r.a = 0;
    r.b = 0;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    r.h = 0;
    r.l = 0;
    r.f = 0;
    r.sp = 0;
    r.pc = 0;
    r.m = 0;
    r.ime = 0;
    halt = 0;

    paused = false;
    std::cout << "Cpu: Reset" << std::endl;
}

void Emu::Cpu::exec() {
    uint8_t op = emu->mmu->rb(r.pc);
    char s[500];
    snprintf(s, 500, "af: 0x%04X\n"
                     "bc: 0x%04X\n"
                     "de: 0x%04X\n"
                     "hl: 0x%04X\n"
                     "sp: 0x%04X\n"
                     "pc: 0x%04X\n"
                     "m: %d\n"
                     "ime: %d",
             r.af,
             r.bc,
             r.de,
             r.hl,
             r.sp,
             r.pc,
             r.m,
             r.ime);
    r.m = 0;
    char s1[100];
    r.pc++;
    switch (Ops::opTable[op].argsize) {
        case 0: {
            snprintf(s1, 100, Ops::opTable[op].desc);
//            if(op == 0xF1 && r.pc > 0x0100) {
//                paused = true;
//            }
            Ops::opTable[op].pf(0);
        }
            break;
        case 1: {
            uint8_t arg = emu->mmu->rb(Cpu::r.pc);
            Cpu::r.pc++;
            if (op == 0xCB) {
                snprintf(s1, 100, Ops::opTable[op].desc, Ops::cbTable[arg]);

            } else {
                snprintf(s1, 100, Ops::opTable[op].desc, arg);
            }
            Ops::opTable[op].pf(arg);
        }
            break;
        case 2: {
            uint16_t arg = emu->mmu->rw(Cpu::r.pc);
            Cpu::r.pc += 2;
            snprintf(s1, 100, Ops::opTable[op].desc, arg);
            Ops::opTable[op].pf(arg);
        }
            break;
    }
    char ss[1000];
    snprintf(ss, 1000, "%s\nop: %s", s, s1);
    r.m += Ops::opTable[op].m;
    clock += r.m;
    frameClock += r.m;
    updateDivider(r.m);
    updateTimer(r.m);
    emu->gpu->exec(r.m);
    processInterrupts();
    regnop = std::string(ss);
}

void Emu::Cpu::runFrame() {
    while (!paused) {
        exec();
//        if(r.pc == 0x0040) {
//            paused = true;
//        }
        if (frameClock > 17555) {
            frameClock = 0;
            break;
        }
    }
    emu->gpu->renderScreen();
}

void Emu::Cpu::requestInterrupt(InterruptId id) {
    emu->mmu->wb(0xFF0F, emu->mmu->rb(0xFF0F) | (1 << id));
}

void Emu::Cpu::processInterrupts() {
    if (emu->cpu->r.ime == 1) {
        uint8_t requests = emu->mmu->rb(0xFF0F);
        uint8_t enabled = emu->mmu->rb(0xFFFF);
        if (requests > 0) {
            for (int i = 0; i < 5; i++) {
                if ((requests & (1 << i)) && (enabled & (1 << i))) {
                    serviceInterrupt((InterruptId) i);
                }
            }
        }
    }
}

void Emu::Cpu::serviceInterrupt(InterruptId id) {
    r.ime = 0;
    emu->mmu->wb(0xFF0F, emu->mmu->rb(0xFF0F) & ~(1 << id));
    //Ops::PUSH(r.pc);
    switch (id) {
        case VBlank:
            Ops::CALLnn(0x0040);
            break;
        case LCD:
            Ops::CALLnn(0x0048);
            break;
        case Timer:
        std::cout << "Timer interrupt" << std::endl;
            Ops::CALLnn(0x0050);
            break;
        case Joypad:
            Ops::CALLnn(0x0060);
            break;
    }
//    clock += 6;
//    frameClock += 6;
}

void Emu::Cpu::setTimerFreq() {
    uint8_t freqNum = emu->mmu->rb(0xFF07) & 0x03;
    switch (freqNum) {
        case 0:
            timerClocks = clockSpeed / 4096;
            break;
        case 1:
            timerClocks = clockSpeed / 262144;
            break;
        case 2:
            timerClocks = clockSpeed / 65536;
            break;
        case 3:
            timerClocks = clockSpeed / 16384;
            break;
    }
}

void Emu::Cpu::updateTimer(uint16_t m) {
    uint8_t tmc = emu->mmu->rb(0xFF07);
    bool timerEnabled = ((tmc & 0x04) != 0);
    if (timerEnabled) {
        timerClocks -= m;
        if (timerClocks <= 0) {
            setTimerFreq();
            if (emu->mmu->rb(0xFF05) == 255) {
                emu->mmu->wb(0xFF05, emu->mmu->rb(0xFF06));
                requestInterrupt(Timer);
            } else {
                emu->mmu->wb(0xFF05, emu->mmu->rb(0xFF05) + 1);
            }
        }
    }
}

void Emu::Cpu::updateDivider(uint16_t m) {
    dividerClocks += m;
    if (dividerClocks >= 63) {
        dividerClocks = 0;
        emu->mmu->wbu(0xFF04, emu->mmu->rb(0xFF04) + 1);
    }
}