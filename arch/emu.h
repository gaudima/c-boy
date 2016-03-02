//
// Created by gaudima on 28.01.2016.
//

#ifndef C_BOY_EMU_H
#define C_BOY_EMU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../windows/settings.h"

class Emu {
public:
    class Cpu;

    class Mmu;

    class Gpu;

    class Joy;

    Emu();

    ~Emu();

    void run();

    void runFrame();

    void loadRom(std::string rom);

private:
    std::string getFpsString();

    sf::Clock fpsClock;
    size_t frameCounter;
    double avgFps;
    sf::RenderWindow *window;
    Cpu *cpu;
    Gpu *gpu;
    Mmu *mmu;
    Joy *joy;
    Settings *settings;

};


#endif //C_BOY_EMU_H
