//
// Created by gaudima on 28.01.2016.
//

#include "emu.h"
#include "cpu.h"
#include "mmu.h"
#include "gpu.h"
#include "joy.h"
#include "../windows/filedialog.h"
#include "../windows/settings.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui-events-SFML.h"
#include "../imgui/imgui-rendering-SFML.h"
#include "../cppformat/format.h"

Emu::Emu(std::string path) {
    this->path = path;
    window = new sf::RenderWindow(sf::VideoMode(400, 300), "C-Boy", sf::Style::Default & ~sf::Style::Resize);
    cpu = new Cpu(this);
    mmu = new Mmu(this);
    gpu = new Gpu(this);
    joy = new Joy(this);
    settings = new Settings(this);
    fileDialog = new FileDialog(this);
    if (!debugFont.loadFromFile("ubuntu_mono.ttf")) {
        std::cout << "Unable to load font" << std::endl;
    }
    debugText.setFont(debugFont);
    debugText.setCharacterSize(14);
    debugText.setPosition(0, 19);
    debugText.setColor(sf::Color(255,255,255));
    debugFrame.setSize(sf::Vector2f(180, 140));
    debugFrame.setPosition(0, 19);
    debugFrame.setFillColor(sf::Color(0, 0, 0, 190));
    //loadRom("loz.gb");
    cpu->paused = true;
    fastForward = false;
    frameCounter = 1;
    fpsAccum = 0;
}

Emu::~Emu() {
    delete cpu;
    delete mmu;
    delete gpu;
    delete joy;
    delete settings;
    delete fileDialog;
    delete window;
}

void Emu::runFrame() {
    cpu->runFrame();
}

void Emu::loadRom(std::string rom) {
    mmu->loadRom(rom);
}

void Emu::reset() {
    cpu->reset();
    gpu->reset();
    mmu->reset();
    fastForward = false;
    frameCounter = 1;
    fpsAccum = 0;
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
                } else if (event.key.code == sf::Keyboard::F10) {
                    if(!fastForward) {
                        window->setFramerateLimit(std::round(60.f * settings->visualSettings.ffSpeed / 100.f));
                    } else {
                        window->setFramerateLimit(60);
                    }
                    fastForward = !fastForward;
                }
            }
        }
        window->clear(sf::Color::Black);
        drawMenuBar();
        runFrame();
        window->setTitle(getFpsTitleString());
        displayDebugInfo();
        settings->draw();
        fileDialog->draw();
        ImGui::Render();
        window->display();
    }
}

void Emu::initImGui() {
    ImGui::GetIO().Fonts->AddFontFromFileTTF("ubuntu_mono.ttf", 14, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
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
            fileDialog->open();
        }
        ImGui::SameLine();
        if(ImGui::Button("Settings")) {
            settings->open();
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();
    ImGui::GetStyle().WindowFillAlphaDefault = oldAlpha;
    ImGui::PopStyleVar();
}

std::string Emu::getFpsTitleString() {
    double fps = 1000000.f / fpsClock.restart().asMicroseconds();
    fpsAccum += fps;
    frameCounter++;
    if(frameCounter == 21) {
        avgFps = fpsAccum / 20;
        fpsAccum = 0;
        frameCounter = 1;
    }
    return fmt::format("C-Boy : FPS: {:.2f} : Avg FPS: {:.2f}", fps, avgFps);
}

void Emu::displayDebugInfo() {
    if(settings->visualSettings.enableDebug) {
        window->draw(debugFrame);
        debugText.setString(cpu->getRegString());
        window->draw(debugText);
    }
}