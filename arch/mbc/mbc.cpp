//
// Created by gaudima on 2/19/16.
//

#include "mbc.h"

Emu::Mmu::Mbc::Mbc(uint8_t *rom, uint32_t romSize, uint8_t *ram, uint32_t ramSize) :
        rom(rom),
        romSize(romSize),
        ram(ram),
        ramSize(ramSize),
        enableRam(false)
{ }

Emu::Mmu::Mbc::~Mbc() {
    delete ram;
    delete rom;
    std::cout << "Mbc: destructor" << std::endl;
}