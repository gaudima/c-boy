//
// Created by gaudima on 2/21/16.
//

#include "mbc1.h"

Emu::Mmu::Mbc1::Mbc1(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize) :
        Mbc(rom, romSize, ram, ramSize)
{
    romOffset = 0x4000;
    romOffsetBanks = 1;
    romBanking = false;
    ramOffset = 0;
}

uint8_t Emu::Mmu::Mbc1::rb(uint16_t addr) {
    if(0x0000 <= addr && addr <= 0x3FFF) {
        return rom[addr];
    }
    if(0x4000 <= addr && addr <= 0x7FFF) {
        return rom[romOffset + addr - 0x4000];
    } else if(0xA000 <= addr && addr <= 0xBFFF) {
        return ram[ramOffset + addr - 0xA000];
    }
}

void Emu::Mmu::Mbc1::wb(uint16_t addr, uint8_t val) {
    if(0x0000 <= addr && addr <= 0x1FFF) {
        if((val & 0x0F) == 0x0A) {
            enableRam = true;
        } else {
            enableRam = false;
        }
    } else if(0x2000 <= addr && addr <= 0x3FFF) {
        uint8_t lo5 = val & 0x1F;
        romOffsetBanks &= ~(0x1F);
        romOffsetBanks |= lo5;
        if (romOffsetBanks == 0) {
            romOffsetBanks++;
        }
        romOffset = romOffsetBanks * 0x4000;
    } else if(0x4000 <= addr && addr <= 0x5FFF) {
        if(romBanking) {
            romOffsetBanks &= 0x1F;
            val &= ~(0x1F);
            romOffsetBanks |= val;
            if(romOffsetBanks == 0) {
                romOffsetBanks++;
            }
            romOffset = romOffsetBanks * 0x4000;
        } else {
            ramOffset = (val & 0x03) * 0x4000;
        }
    } else if(0x6000 <= addr && addr <= 0x7FFF) {
        romBanking = ((val & 0x01) == 0);
        if(romBanking) {
            romOffsetBanks = 0;
        }
    }else if(0xA000 <= addr && addr <= 0xBFFF) {
            ram[ramOffset + addr - 0xA000] = val;
    }
}
