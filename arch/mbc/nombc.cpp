//
// Created by gaudima on 2/21/16.
//

#include "nombc.h"
#include "mbc.h"

Emu::Mmu::NoMbc::NoMbc(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize) :
        Mbc(rom, romSize, ram, ramSize)
{
    romOffset = 0x4000;
    ramOffset = 0;
}

uint8_t Emu::Mmu::NoMbc::rb(uint16_t addr) {
    if(0x0000 <= addr && addr <= 0x7FFF) {
        return rom[addr];
    } else if(0xA000 <= addr && addr <= 0xBFFF) {
        return ram[addr - 0xA000];
    }
}

void Emu::Mmu::NoMbc::wb(uint16_t addr, uint8_t val) {
    if(0xA000 <= addr && addr <= 0xBFFF) {
        ram[addr - 0xA000] = val;
    }
}

