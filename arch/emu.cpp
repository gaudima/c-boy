//
// Created by gaudima on 28.01.2016.
//

#include "emu.h"
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "joy.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui-events-SFML.h"
#include "../imgui/imgui-rendering-SFML.h"
#include "../cppformat/format.h"

Emu::Emu() {
    window = new sf::RenderWindow(sf::VideoMode(400, 300), "C-Boy");
    cpu = new Cpu(this);
    mmu = new Mmu(this);
    gpu = new Gpu(this);
    joy = new Joy(this);
    settings = new Settings();
    FileDialog dialog;
    if (!debugFont.loadFromFile("ubuntu.ttf")) {
        std::cout << "Unable to load font" << std::endl;
    }
    debugText.setFont(debugFont);
    debugText.setCharacterSize(12);
    debugText.setPosition(0, 19);
    debugText.setColor(sf::Color(255,255,255));
    debugFrame.setSize(sf::Vector2f(180, 140));
    debugFrame.setPosition(0, 19);
    debugFrame.setFillColor(sf::Color(0, 0, 0, 190));
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
    window->setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);
    initImGui();
    while (window->isOpen()) {
        ImGui::SFML::UpdateImGui();
        ImGui::SFML::UpdateImGuiRendering();
        sf::Event event;
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            settings->processEvent(event);
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F12) {
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
        drawMenuBar();
        runFrame();
        window->setTitle(getFpsTitleString());
        displayDebugInfo();
        cpu->paused = settings->open;
        settings->draw(window);
        ImGui::Render();
        window->display();
    }
}

void Emu::initImGui() {
    ImGui::SFML::SetRenderTarget(*window);
    ImGui::SFML::InitImGuiRendering();
    ImGui::SFML::SetWindow(*window);
    ImGui::SFML::InitImGuiEvents();
}

void Emu::drawMenuBar() {
    bool tmp = true;
    sf::Vector2u size = window->getSize();
    ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
    ImGui::SetNextWindowPos(ImVec2(0,0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    //ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.1f);
    float oldAlpha = ImGui::GetStyle().WindowFillAlphaDefault;
    ImGui::GetStyle().WindowFillAlphaDefault = 0.0f;
    ImGui::Begin("C-Boy", &tmp, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);
    if(ImGui::BeginMenuBar()) {
        if(ImGui::Button("Load Rom")) {
        }
        ImGui::SameLine();
        if(ImGui::Button("Settings")) {
            settings->open = true;
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();
    ImGui::GetStyle().WindowFillAlphaDefault = oldAlpha;
    ImGui::PopStyleVar();
}

std::string Emu::getFpsTitleString() {
    double fps = 1000000.f / fpsClock.restart().asMicroseconds();
    avgFps = ((frameCounter - 1) * avgFps + fps) / frameCounter;
    frameCounter++;
    return fmt::format("C-Boy : FPS: {:.2f} : Avg FPS: {:.2f}", fps, avgFps);;
}

void Emu::displayDebugInfo() {
    if(settings->visualSettings.enableDebug) {
        window->draw(debugFrame);
        debugText.setString(cpu->getRegString());
        window->draw(debugText);
    }
}