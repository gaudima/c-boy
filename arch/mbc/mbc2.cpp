//
// Created by gaudima on 2/19/16.
//

#include "mbc2.h"

Emu::Mmu::Mbc2::Mbc2(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize) :
        Mbc(rom, romSize, ram, ramSize)
{
    romOffset = 0x4000;
    ramOffset = 0;
}

uint8_t Emu::Mmu::Mbc2::rb(uint16_t addr) {
    if(0x0000 <= addr && addr <= 0x3FFF) {
        return rom[addr];
    }
    if(0x4000 <= addr && addr <= 0x7FFF) {
        return rom[romOffset + addr - 0x4000];
    } else if(0xA000 <= addr && addr <= 0xBFFF) {
        return ram[addr - 0xA000];
    }
}

void Emu::Mmu::Mbc2::wb(uint16_t addr, uint8_t val) {
    if(0x0000 <= addr && addr <= 0x1FFF) {
        if((addr & 0x0100) == 0) {
            if ((val & 0x0F) == 0x0A) {
                enableRam = true;
            } else {
                enableRam = false;
            }
        }
    } else if(0x2000 <= addr && addr <= 0x3FFF) {
        if((addr & 0x0100) != 0) {
            romOffset = (val & 0x0F) % romSize;
            if (romOffset == 0 || romOffset == 20 || romOffset == 40 || romOffset == 60) {
                romOffset++;
            }
            romOffset *= 0x4000;
        }
    } else if(0xA000 <= addr && addr <= 0xBFFF) {
        ram[addr - 0xA000] = val & 0x0F;
    }
}
