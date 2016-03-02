//
// Created by gaudima on 28.01.2016.
//

#include "emu.h"
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "joy.h"

Emu::Emu() {
    window = new sf::RenderWindow(sf::VideoMode(400, 300), "C-Boy");
    cpu = new Cpu(this);
    mmu = new Mmu(this);
    gpu = new Gpu(this);
    joy = new Joy(this);
    settings = new Settings();
    loadRom("loz.gb");
    frameCounter = 1;
}

Emu::~Emu() {
    delete cpu;
    delete mmu;
    delete gpu;
    delete joy;
    delete settings;
    delete window;
}

void Emu::runFrame() {
    cpu->runFrame();
}

void Emu::loadRom(std::string rom) {
    mmu->loadRom(rom);
}

void Emu::run() {
    sf::Text text;
    text.setColor(sf::Color::White);
    sf::Font font;
    if (!font.loadFromFile("ubuntu.ttf")) {
        std::cout << "Unable to load font" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(12);
    window->setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    settings->open();
                } else if (event.key.code == sf::Keyboard::F12) {
                    cpu->paused = !cpu->paused;
                } else if (event.key.code == sf::Keyboard::F11) {
                    cpu->exec();
                } else {
                    joy->keyPressed(event.key);
                }
            } else if(event.type == sf::Event::KeyReleased) {
                joy->keyReleased(event.key);
            }
        }
        window->clear(sf::Color::Black);
        runFrame();
        text.setString(getFpsString() + "\n" + cpu->regnop);
        window->draw(text);
        window->display();
    }
}

std::string Emu::getFpsString() {
    char buf[100];
    double fps = 1000000.f / fpsClock.restart().asMicroseconds();
    avgFps = ((frameCounter - 1) * avgFps + fps) / frameCounter;
    frameCounter++;
    snprintf(buf, 100, "FPS: %f\nAvg FPS: %f", fps, avgFps);
    return std::string(buf);
}