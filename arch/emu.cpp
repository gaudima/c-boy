//
// Created by gaudima on 28.01.2016.
//

#include "emu.h"
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "joy.h"
#include "../cppformat/format.h"

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
            if(event.type == sf::Event::JoystickButtonPressed) {
                joy->keyPressed(event.joystickButton);
            } else if(event.type == sf::Event::JoystickButtonReleased) {
                joy->keyReleased(event.joystickButton);
            }
            if(event.type == sf::Event::JoystickMoved) {
                joy->axisMove(event.joystickMove);
            }
        }
        window->clear(sf::Color::Black);
        runFrame();
        text.setString(getFpsString() + "\n" + cpu->getRegString());
        window->draw(text);
        window->display();
    }
}

std::string Emu::getFpsString() {
    double fps = 1000000.f / fpsClock.restart().asMicroseconds();
    avgFps = ((frameCounter - 1) * avgFps + fps) / frameCounter;
    frameCounter++;
    return fmt::format("FPS: {:.2f}\nAvg FPS: {:.2f}", fps, avgFps);;
}