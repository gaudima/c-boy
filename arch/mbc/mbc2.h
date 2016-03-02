//
// Created by gaudima on 2/19/16.
//

#ifndef C_BOY_MBC2_H
#define C_BOY_MBC2_H

#include "mbc.h"

class Emu::Mmu::Mbc2 : public Emu::Mmu::Mbc {
public:
    Mbc2(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize);

    virtual uint8_t rb(uint16_t addr);
    virtual void wb(uint16_t addr, uint8_t val);

};


#endif //C_BOY_MBC2_H
