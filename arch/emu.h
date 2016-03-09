//
// Created by gaudima on 28.01.2016.
//

#ifndef C_BOY_EMU_H
#define C_BOY_EMU_H

#include <SFML/Graphics.hpp>
#include <memory>

class Emu {
public:
    class Cpu;

    class Mmu;

    class Gpu;

    class Joy;

    class Settings;

    class FileDialog;

    Emu(std::string path);

    ~Emu();

    void initImGui();

    void run();

    void runFrame();

    void loadRom(std::string rom);

    void reset();

private:
    std::string getFpsTitleString();

    void displayDebugInfo();

    void drawMenuBar();
    std::string path;
    sf::Clock fpsClock;
    sf::Font debugFont;
    sf::Text debugText;
    sf::RectangleShape debugFrame;
    size_t frameCounter;
    double avgFps;
    double fpsAccum;
    bool fastForward;
    sf::RenderWindow *window;
    Cpu *cpu;
    Gpu *gpu;
    Mmu *mmu;
    Joy *joy;
    Settings *settings;
    FileDialog *fileDialog;
};


#endif //C_BOY_EMU_H
