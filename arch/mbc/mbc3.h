//
// Created by gaudima on 10.03.2016.
//

#ifndef C_BOY_MBC3_H
#define C_BOY_MBC3_H

#include "mbc.h"

class Emu::Mmu::Mbc3 : public Emu::Mmu::Mbc {
public:
    Mbc3(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize);

    virtual uint8_t rb(uint16_t addr);
    virtual void wb(uint16_t addr, uint8_t val);
private:
    uint8_t romOffsetBanks;
    bool romBanking;
};

#endif //C_BOY_MBC3_H
