//
// Created by gaudima on 21.01.2016.
//

#ifndef C_BOY_MMU_H
#define C_BOY_MMU_H

#include <iostream>
#include <string>
#include "emu.h"

class Emu::Mmu {
public:
    class Mbc;
    class NoMbc;
    class Mbc1;
    class Mbc2;

    Mmu(Emu *emu);

    ~Mmu();

    void reset();

    uint8_t rb(uint16_t addr);

    uint16_t rw(uint16_t addr);

    uint8_t rbu(uint16_t addr);

    uint16_t rwu(uint16_t addr);

    void wb(uint16_t addr, uint8_t val);

    void ww(uint16_t addr, uint16_t val);

    void wbu(uint16_t addr, uint8_t val);

    void wwu(uint16_t addr, uint16_t val);

    void loadRom(std::string filename);

private:
    void processDMATransfer(uint8_t data);

    Emu *emu;
    bool bios_loaded;
    uint8_t bios[256];
    uint8_t ram[65536];
    uint8_t *rom;
    uint8_t *wram;
    uint8_t *wramsh;
    Mbc *mbc;
};


#endif //C_BOY_MMU_H
