//
// Created by gaudima on 2/21/16.
//

#ifndef C_BOY_MBC1_H
#define C_BOY_MBC1_H

#include "mbc.h"

class Emu::Mmu::Mbc1 : public Emu::Mmu::Mbc {
public:
    Mbc1(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize);

    virtual uint8_t rb(uint16_t addr);
    virtual void wb(uint16_t addr, uint8_t val);
private:
    uint8_t romOffsetBanks;
    bool romBanking;
};


#endif //C_BOY_MBC1_H
