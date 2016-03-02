//
// Created by gaudima on 23.01.2016.
//

#ifndef C_BOY_GPU_H
#define C_BOY_GPU_H

#include <iostream>
#include <memory>
#include <vector>
#include "emu.h"

class Emu::Gpu {
public:
    Gpu(Emu *emu);

    sf::Image screen;
    sf::Texture screenTex;
    sf::Sprite screenSprite;
    uint8_t tiles[512][8][8];
    sf::Color bgPalette[4];
    sf::Color spritePal1[4];
    sf::Color spritePal2[4];
    sf::Color colors[4];

    void reset();

    void exec(uint16_t m);

    void updateTile(uint16_t addr, uint8_t val);

    void renderScanline();

    void readGpuData();

    void renderScreen();

    void updateLCDStatus();

    void renderTiles();

    void updateSpritePriority();

    void renderSprites();

    void renderWindow();

private:
    Emu *emu;
    sf::View view;
    int scanlineClock;
    uint8_t mode;
    uint8_t line;
    bool lcdEnable;
    uint8_t windowTileMap;
    bool windowEnable;
    uint8_t tileData;
    uint8_t bgTileMap;
    uint8_t spriteSize;
    bool spritesEnable;
    bool bgDisplay;
    uint8_t scrollY;
    uint8_t scrollX;
    int16_t windowY;
    int16_t windowX;
    std::vector<uint16_t> spritePriority;
};


#endif //C_BOY_GPU_H
