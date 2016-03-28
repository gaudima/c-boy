//
// Created by gaudima on 20.01.2016.
//

#include "cpu.h"
#include "gpu.h"
#include "mmu.h"
#include "ops.h"
#include "joy.h"
#include "../cppformat/format.h"
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
    timerClocks = 4;
    timerClockCounter = 0;
    paused = false;
    std::cout << "Cpu: Reset" << std::endl;
}

std::string Emu::Cpu::getRegString() {
    std::string regs = fmt::format("af: 0x{:04X}\n"
                                   "bc: 0x{:04X}\n"
                                   "de: 0x{:04X}\n"
                                   "hl: 0x{:04X}\n"
                                   "sp: 0x{:04X}\n"
                                   "pc: 0x{:04X}\n"
                                   "m: {:d}\n"
                                   "ime: {:d}\n"
                                   "op: ",
                                   r.af,
                                   r.bc,
                                   r.de,
                                   r.hl,
                                   r.sp,
                                   r.pc,
                                   r.m,
                                   r.ime);
    uint8_t op = emu->mmu->rb(r.pc);
    switch(Ops::opTable[op].argsize) {
        case 0: {
            regs += Ops::opTable[op].desc;
        }
            break;
        case 1: {
            uint8_t arg = emu->mmu->rb(r.pc + 1);
            if(op == 0xCB) {
                regs += fmt::format(Ops::opTable[op].desc, Ops::cbTable[arg].desc);
            } else {
                regs += fmt::format(Ops::opTable[op].desc, arg);
            }
        }
            break;
        case 2: {
            uint16_t arg = emu->mmu->rw(r.pc + 1);
            regs += fmt::format(Ops::opTable[op].desc, arg);
        }
            break;
    }
    return regs;
}

void Emu::Cpu::exec() {
    uint8_t op = emu->mmu->rb(r.pc);
    r.m = 0;
    r.pc++;
    switch (Ops::opTable[op].argsize) {
        case 0: {
            Ops::opTable[op].pf(0);
        }
            break;
        case 1: {
            uint8_t arg = emu->mmu->rb(Cpu::r.pc);
            Cpu::r.pc++;
            Ops::opTable[op].pf(arg);
        }
            break;
        case 2: {
            uint16_t arg = emu->mmu->rw(Cpu::r.pc);
            Cpu::r.pc += 2;
            Ops::opTable[op].pf(arg);
        }
            break;
    }
    r.m += Ops::opTable[op].m;
    clock += r.m;
    frameClock += r.m;
    updateDivider(r.m);
    updateTimer(r.m);
    emu->gpu->exec(r.m);
    processInterrupts();
}

void Emu::Cpu::runFrame() {
    while (!paused) {
        if(r.pc == bpVal && emu->settings->visualSettings.enableDebug) {
            paused = true;
        }
        exec();
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
//                if(i == 2 && (requests & (1 << i))) {
//                    std::cout << (requests & (1 << i)) << " " << (enabled & (1 << i)) << std::endl;
//                }
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
    //r.m = 6;
    //updateDivider(r.m);
    //updateTimer(r.m);
    //emu->gpu->exec(r.m);
    //processInterrupts();
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
            //int passedTimerTicks = timerClockCounter / timerClocks;
            if(emu->mmu->rb(0xFF05) == 0xFF) {
                emu->mmu->wb(0xFF05, emu->mmu->rb(0xFF06));
                requestInterrupt(Timer);
            } else {
                emu->mmu->wb(0xFF05, emu->mmu->rb(0xFF05) + 1);
            }
            //timerClocks  = 0;
            //timerClockCounter = 0;
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