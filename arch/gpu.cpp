//
// Created by gaudima on 23.01.2016.
//

#include "gpu.h"
#include "mmu.h"
#include "cpu.h"
#include "../windows/settings.h"

Emu::Gpu::Gpu(Emu *emu) : view(sf::FloatRect(0, 0, 400, 300)) {
    this->emu = emu;
    reset();
    drawSplashScreen();
}

void Emu::Gpu::reset() {
    screen.create(160, 144, sf::Color::White);
    screenTex.create(160, 144);
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                tiles[i][j][k] = 0;
            }
        }
    }

    line = 0;
    scanlineClock = 114;

    colors[0] = sf::Color(255, 255, 255, 255);
    colors[1] = sf::Color(192, 192, 192, 255);
    colors[2] = sf::Color(96, 96, 96, 255);
    colors[3] = sf::Color(0, 0, 0, 255);
}

void Emu::Gpu::drawSplashScreen() {
    int x = 34;
    int y = 54;
    for(int i = 0; i < 344; i++) {
        for(int j = 0; j < (splashScreen[i] & 0x7F); j++) {
            if(splashScreen[i] & 0x80) {
                screen.setPixel(x, y, sf::Color::Black);
            }
            x++;
            if(x == 126) {
                x = 34;
                y++;
            }
        }
    }
}

void Emu::Gpu::readGpuData() {
    uint8_t control = emu->mmu->rb(0xFF40);
    lcdEnable = ((control & 0x80) != 0);
    windowTileMap = ((control & 0x40) ? 1 : 0);
    windowEnable = ((control & 0x20) != 0);
    tileData = ((control & 0x10) ? 1 : 0);
    bgTileMap = ((control & 0x08) ? 1 : 0);
    spriteSize = ((control & 0x04) ? 1 : 0);
    spritesEnable = ((control & 0x02) != 0);
    bgDisplay = ((control & 0x01) != 0);

    scrollY = emu->mmu->rb(0xFF42);
    scrollX = emu->mmu->rb(0xFF43);
    windowY = emu->mmu->rb(0xFF4A);
    windowX = emu->mmu->rb(0xFF4B) - 7;


    uint8_t bgPal = emu->mmu->rb(0xFF47);
    uint8_t sPal1 = emu->mmu->rb(0xFF48);
    uint8_t sPal2 = emu->mmu->rb(0xFF49);
    for (int i = 0; i < 4; i++) {
        bgPalette[i] = colors[(bgPal & (3 << (i * 2))) >> (i * 2)];
        spritePal1[i] = colors[(sPal1 & (3 << (i * 2))) >> (i * 2)];
        spritePal2[i] = colors[(sPal2 & (3 << (i * 2))) >> (i * 2)];
    }
}

void Emu::Gpu::renderScreen() {
    screenTex.update(screen);
    screenTex.setSmooth(emu->settings->visualSettings.enableAA);
    screenSprite.setTexture(screenTex);
    float scale = emu->settings->visualSettings.scaleFactor;
    screenSprite.setScale(scale, scale);
    float scaledWidth = std::ceil(160.f * scale);
    float scaledHeight = std::ceil(144.f * scale) + 20;
    view.setCenter(scaledWidth / 2, scaledHeight / 2);
    view.setSize(scaledWidth, scaledHeight);
    emu->window->setView(view);
    emu->window->setSize(sf::Vector2u((int)scaledWidth, (int)scaledHeight));
    screenSprite.setPosition(0, 20);
    emu->window->draw(screenSprite);
    //emu->window->display();
}

void Emu::Gpu::renderScanline() {
    if (bgDisplay) {
        renderTiles();
    }
    if(windowEnable) {
        renderWindow();
    }
    if (spritesEnable) {
        renderSprites();
    }
}

void Emu::Gpu::renderWindow() {
    if(windowY <= line) {
        uint16_t bgMem = 0;
        bool usingUnsigned = true;
        if(tileData == 0) {
            usingUnsigned = false;
        }

        if (windowTileMap == 1) {
            bgMem = 0x9C00;
        } else {
            bgMem = 0x9800;
        }
        uint8_t yPos = line - windowY;

        uint16_t tileRow = (((uint8_t)(yPos / 8)) * 32);

        for(int pixel = 0; pixel < 160; pixel++) {
            if(pixel < windowX) {
                continue;
            }
            uint8_t xPos = pixel - windowX;
            //std::cout << std::dec << "pixel: " << pixel << "\nwindowX: " << (int)windowX << "\nxPos: " <<(int) xPos << std::endl;

            uint16_t tileCol = xPos / 8;
            int16_t tileNum;
            uint16_t tileAddr = bgMem + tileRow + tileCol;
            if(usingUnsigned) {
                tileNum = (uint8_t)emu->mmu->rb(tileAddr);
            } else {
                tileNum = (int8_t)emu->mmu->rb(tileAddr);
            }

            if(!usingUnsigned && tileNum < 128) {
                tileNum += 256;
            }

            if(line < 0 || line > 149 || pixel < 0 || pixel > 159) {
                continue;
            }
            uint8_t tileY = yPos % 8;
            uint8_t tileX = xPos % 8;
            screen.setPixel(pixel, line, bgPalette[tiles[tileNum][tileY][tileX]]);
        }
    }
}

void Emu::Gpu::renderTiles() {
    uint16_t bgMem = 0;
    bool usingUnsigned = true;

    if(tileData == 0) {
        usingUnsigned = false;
    }
    if(bgTileMap == 1) {
        bgMem = 0x9C00;
    } else {
        bgMem = 0x9800;
    }

    uint8_t yPos = 0;
    yPos = scrollY + line;

    uint16_t tileRow = (((uint8_t)(yPos / 8)) * 32);

    for(int pixel = 0; pixel < 160; pixel++) {
        uint8_t xPos = pixel + scrollX;

        uint16_t tileCol = xPos / 8;
        int16_t tileNum;
        uint16_t tileAddr = bgMem + tileRow + tileCol;
        if(usingUnsigned) {
            tileNum = (uint8_t)emu->mmu->rb(tileAddr);
        } else {
            tileNum = (int8_t)emu->mmu->rb(tileAddr);
        }

        if(!usingUnsigned && tileNum < 128) {
            tileNum += 256;
        }

        if(line < 0 || line > 149 || pixel < 0 || pixel > 159) {
            continue;
        }
        uint8_t tileY = yPos % 8;
        uint8_t tileX = xPos % 8;
        screen.setPixel(pixel, line, bgPalette[tiles[tileNum][tileY][tileX]]);
    }
}

void Emu::Gpu::updateSpritePriority() {
    spritePriority.clear();
    for(int8_t sprite = 39; sprite >= 0; sprite--) {
        uint8_t index = sprite * 4;
        spritePriority.push_back(0xFE00 + index);
    }
    std::stable_sort(spritePriority.begin(), spritePriority.end(), [&](uint16_t a, uint16_t b) {
        return (emu->mmu->rb(b + 1) < emu->mmu->rb(a + 1));
    });
    /*for(int i = 0; i < 40; i++) {
        std::cout << std::hex << spritePriority[i] << ":" << std::dec << (int)emu->mmu->rb(spritePriority[i] + 1) << " ";
    }
    std::cout << std::endl;*/
}

void Emu::Gpu::renderSprites() {
    //std::cout<<"here"<<std::endl;
    if(spritePriority.empty()) {
        updateSpritePriority();
    }
    std::vector<sf::Color> lineBuffer;
    lineBuffer.assign(160, sf::Color::Transparent);
    for(uint8_t sprite = 0; sprite < 40; sprite++) {
        uint16_t addr = spritePriority[sprite];
        int16_t spriteY = emu->mmu->rb(addr) - 16;
        uint8_t spriteX = emu->mmu->rb(addr + 1) - 8;
        uint8_t tileLocation = emu->mmu->rb(addr + 2);
        uint8_t attrs = emu->mmu->rb(addr + 3);
        bool flipY = ((attrs & 0x40) != 0);
        bool flipX = ((attrs & 0x20) != 0);
        uint8_t ySize = ((spriteSize == 0) ? 8 : 16);

        if(spriteY <= line && line < spriteY + ySize) {
            int sLine = line - spriteY;
            if(flipY) {
                sLine = ySize - sLine - 1;
            }

            sLine *= 2;

            uint16_t addr = 0x8000 + (tileLocation * 16) + sLine;
            uint8_t sx;
            for (uint8_t x = 0; x < 8; x++) {
                if (flipX) {
                    sx = 1 << x;
                } else {
                    sx = 1 << (7 - x);
                }
                uint8_t pixel = ((emu->mmu->rb(addr) & sx) ? 1 : 0) + ((emu->mmu->rb(addr + 1) & sx) ? 2 : 0);
                sf::Color pixelColor;
                if((attrs & 0x10) == 0) {
                    pixelColor = spritePal1[pixel];
                } else {
                    pixelColor = spritePal2[pixel];
                }
                //std::cout << std::dec << (int)colorNum << std::endl;
                if(pixel == 0 || ((attrs & 0x80) != 0 && screen.getPixel(x + spriteX, line) != sf::Color::White)) {
                    continue;
                }

                uint8_t pixelX = x + spriteX;
                if(pixelX < 0 || pixelX > 159 || line < 0 || line > 149) {
                    continue;
                }
                lineBuffer[pixelX] = pixelColor;
            }
        }
    }
    for(int i = 0; i < 160; i++) {
        if(lineBuffer[i] != sf::Color::Transparent) {
            screen.setPixel(i, line, lineBuffer[i]);
        }
    }
}

void Emu::Gpu::exec(uint16_t m) {
    updateLCDStatus();
    if (lcdEnable) {
        scanlineClock -= m;
    } else {
        return;
    }

    if (scanlineClock <= 0) {
        line++;
        emu->mmu->wbu(0xFF44, line);
        scanlineClock = 114;

        if (line == 144) {
            emu->cpu->requestInterrupt(emu->cpu->VBlank);
        } else if (line > 153) {
            line = 0;
            emu->mmu->wbu(0xFF44, line);
        }
        if (line < 144) {
            renderScanline();
        }
    }

}

void Emu::Gpu::updateTile(uint16_t addr, uint8_t val) {
    uint16_t addrt = addr & 0xFFFE;

    addr &= 0x1FFE;
    uint16_t tile = (addr >> 4) & 511;
    uint8_t y = (addr >> 1) & 7;

    uint8_t sx;
    for (uint8_t x = 0; x < 8; x++) {
        sx = 1 << (7 - x);
        tiles[tile][y][x] = ((emu->mmu->rb(addrt) & sx) ? 1 : 0) + ((emu->mmu->rb(addrt + 1) & sx) ? 2 : 0);
    }
}

void Emu::Gpu::updateLCDStatus() {
    readGpuData();
    uint8_t status = emu->mmu->rb(0xFF41);
    if (!lcdEnable) {
        scanlineClock = 114;
        line = 0;
        emu->mmu->wbu(0xFF44, 0);
        status &= 0xFC;
        status |= 0x01;
        emu->mmu->wb(0xFF41, status);
        return;
    }
    line = emu->mmu->rb(0xFF44);
    uint8_t currentMode = status & 0x03;
    uint8_t mode = 0;
    bool needToRequestInterrupt = false;

    status &= 0xFC;
    if (line >= 144) {
        mode = 1;
        status |= 0x01;
        needToRequestInterrupt = ((status & 0x10) != 0);
    } else {
        size_t m2b = 114 - 20;
        size_t m3b = m2b - 43;
        if (scanlineClock >= m2b) {
            mode = 2;
            status |= 0x02;
            needToRequestInterrupt = ((status & 0x20) != 0);
        } else if (scanlineClock >= m3b) {
            mode = 3;
            status |= 0x03;

        } else {
            mode = 0;
            needToRequestInterrupt = ((status & 0x08) != 0);
        }
    }

    if (needToRequestInterrupt && (mode != currentMode)) {
        emu->cpu->requestInterrupt(emu->cpu->LCD);
    }

    if (line == emu->mmu->rb(0xFF45)) {
        status |= 0x04;
        if ((status & 0x40) != 0) {
            emu->cpu->requestInterrupt(emu->cpu->LCD);
        }
        emu->mmu->wb(0xFF41, status);
    }
}