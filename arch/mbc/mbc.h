//
// Created by gaudima on 2/19/16.
//

#ifndef C_BOY_MBC_H
#define C_BOY_MBC_H

#include "../mmu.h"

class Emu::Mmu::Mbc {
public:
    virtual uint8_t rb(uint16_t addr) = 0;

    virtual void wb(uint16_t addr, uint8_t val) = 0;

    ~Mbc();
    ///static Emu::Mmu::Mbc* loadRom(std::string path);

protected:
    Mbc(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize);
    uint8_t *rom;
    uint8_t *ram;

    uint32_t romOffset;
    uint32_t ramOffset;

    uint32_t romSize;
    uint32_t ramSize;

    bool enableRam;
};


#endif //C_BOY_MBC_H
