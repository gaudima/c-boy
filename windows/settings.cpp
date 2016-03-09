//
// Created by gaudima on 30.01.2016.
//

#include "settings.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui-events-SFML.h"
#include "../imgui/imgui-rendering-SFML.h"
#include "../jsoncpp/json/json.h"
#include "../arch/cpu.h"
#include "../cppformat/format.h"
#include <fstream>

Emu::Settings::Settings(Emu *emu) {
    this->emu = emu;
    controlsColor = ImVec4(0.09, 0.0, 0.0, 1.0);
    visualsColor = ImGui::GetStyle().Colors[ImGuiCol_Button];
    currentWindow = Controls;
    isOpen = false;
    for(int i = 0; i < 8; i++) {
        buttonConfiguration[i].button = -1;
        buttonConfiguration[i].axis = -1;
        buttonConfiguration[i].vid = 0;
        buttonConfiguration[i].pid = 0;
    }
    visualSettings.scaleFactor = 2;
    visualSettings.enableAA = false;
    visualSettings.enableDebug = true;
    visualSettings.ffSpeed = 300;
    buttonToConfigure = -1;
    loadFromFile();
}

void Emu::Settings::loadFromFile() {
    std::ifstream in("settings.json", std::ios::binary);
    if(!in.good()) {
        in.close();
        return;
    }
    Json::Value root;
    in >> root;
    in.close();
    for(int i = 0; i < 8; i++) {
        buttonConfiguration[i].vid = root["controls"][i]["vid"].asUInt();
        buttonConfiguration[i].pid = root["controls"][i]["pid"].asUInt();
        buttonConfiguration[i].button = root["controls"][i]["button"].asInt();
        buttonConfiguration[i].axis = root["controls"][i]["axis"].asInt();
        buttonConfiguration[i].axisSign = root["controls"][i]["axisSign"].asInt();
    }
    visualSettings.scaleFactor = root["visuals"]["scaleFactor"].asFloat();
    visualSettings.ffSpeed = root["visuals"]["ffSpeed"].asInt();
    visualSettings.enableAA = root["visuals"]["enableAA"].asBool();
    visualSettings.enableDebug = root["visuals"]["enableDebug"].asBool();
}

void Emu::Settings::saveToFile() {
    std::ofstream out("settings.json", std::ios::binary);
    Json::Value root;
    for(int i = 0; i < 8; i++) {
        root["controls"][i]["vid"] = buttonConfiguration[i].vid;
        root["controls"][i]["pid"] = buttonConfiguration[i].pid;
        root["controls"][i]["button"] = buttonConfiguration[i].button;
        root["controls"][i]["axis"] = buttonConfiguration[i].axis;
        root["controls"][i]["axisSign"] = buttonConfiguration[i].axisSign;
    }
    root["visuals"]["scaleFactor"] = visualSettings.scaleFactor;
    root["visuals"]["enableAA"] = visualSettings.enableAA;
    root["visuals"]["enableDebug"] = visualSettings.enableDebug;
    root["visuals"]["ffSpeed"] = visualSettings.ffSpeed;
    out << root;
    out.close();
}

void Emu::Settings::drawConfigButton(const char *name, GbButton button) {
    ImGui::AlignFirstTextHeightToWidgets();
    ImGui::Text(name);
    ImGui::SameLine();
    std::string buttonText;
    std::string deviceName;
    if(buttonConfiguration[button].vid == 0 && buttonConfiguration[button].pid == 0) {
        deviceName = "Kbd";
    } else {
        deviceName = fmt::format("Joy{:X}x{:X}", buttonConfiguration[button].vid, buttonConfiguration[button].pid);
    }
    if(buttonConfiguration[button].button == -1 && buttonConfiguration[button].axis == -1) {
        buttonText = "Press to assign";
    } else if(buttonConfiguration[button].axis > -1) {
        buttonText = fmt::format("{}_Axis: {}{}", deviceName, buttonConfiguration[button].axis,
                (buttonConfiguration[button].axisSign > 0) ? "+" : "-");
    } else if(buttonConfiguration[button].button > -1) {
        buttonText = fmt::format("{}_Button: {}", deviceName, buttonConfiguration[button].button);
    }
    ImGui::PushID(button);
    if(ImGui::Button(buttonText.c_str())) {
        buttonToConfigure = button;
    }
    ImGui::PopID();
}

void Emu::Settings::drawControlsWindow() {
    ImGui::Text("Button Mapping:");
    ImGui::BeginChild("child1", ImVec2(0, 0), true);
    drawConfigButton("Dpad Up:       ", Dpad_Up);
    drawConfigButton("Dpad Left:     ", Dpad_Left);
    drawConfigButton("Dpad Down:     ", Dpad_Down);
    drawConfigButton("Dpad Right:    ", Dpad_Right);
    drawConfigButton("Button A:      ", Button_A);
    drawConfigButton("Button B:      ", Button_B);
    drawConfigButton("Button Select: ", Button_Select);
    drawConfigButton("Button Start:  ", Button_Start);
    ImGui::EndChild();
}

void Emu::Settings::drawVisualsWindow() {
    ImGui::AlignFirstTextHeightToWidgets();
    ImGui::Text("Scale factor:");
    ImGui::SameLine();
    float factorForIndex[5] = {2, 2.5, 3, 3.5, 4};
    int index;
    if(visualSettings.scaleFactor == 2) {
        index = 0;
    } else if(visualSettings.scaleFactor == 2.5) {
        index = 1;
    } else if(visualSettings.scaleFactor == 3) {
        index = 2;
    } else if(visualSettings.scaleFactor == 3.5) {
        index = 3;
    } else if(visualSettings.scaleFactor == 4) {
        index = 4;
    }
    ImGui::PushItemWidth(-1);
    if(ImGui::Combo("", &index, "x2\0x2.5\0x3\0x3.5\0x4")) {
        visualSettings.scaleFactor = factorForIndex[index];
    }
    ImGui::AlignFirstTextHeightToWidgets();
    ImGui::Text("Fast forward speed:");
    ImGui::SameLine();
    ImGui::PushItemWidth(-1);
    ImGui::SliderInt("", &visualSettings.ffSpeed, 150, 500, "%.0f%%");
    ImGui::Checkbox("Enable antialiasing", &visualSettings.enableAA);
    ImGui::Checkbox("Enable debug mode", &visualSettings.enableDebug);
}

void Emu::Settings::open() {
    cpuPauseSave = emu->cpu->paused;
    emu->cpu->paused = true;
    isOpen = true;
}

void Emu::Settings::close() {
    isOpen = false;
    emu->cpu->paused = cpuPauseSave;
}

void Emu::Settings::draw() {
    if(isOpen) {
        bool tmp = true;
        sf::Vector2u size = emu->window->getSize();
        ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::Begin("Controls", &tmp, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                       ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);

        if(ImGui::BeginMenuBar()) {
            ImVec4 btnCol = ImGui::GetStyle().Colors[ImGuiCol_Button];
            ImGui::PushStyleColor(ImGuiCol_Button, controlsColor);
            if(ImGui::Button("Controls")) {
                currentWindow = Controls;
                controlsColor = ImVec4(0.09, 0.0, 0.0, 1.0);
                visualsColor = btnCol;
            }
            ImGui::PopStyleColor(1);
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Button, visualsColor);
            if(ImGui::Button("Visuals")) {
                currentWindow = Visuals;
                visualsColor = ImVec4(0.09, 0.0, 0.0, 1.0);
                controlsColor = btnCol;
            }
            ImGui::PopStyleColor(1);
            ImGui::SameLine(ImGui::GetWindowWidth() - 20);
            if(ImGui::Button("X")) {
                saveToFile();
                close();
            }
            ImGui::EndMenuBar();
        }
        if(currentWindow == Controls) {
            drawControlsWindow();
        } else if(currentWindow = Visuals) {
            drawVisualsWindow();
        }
        ImGui::End();
        ImGui::PopStyleVar();
        emu->window->clear(sf::Color::Red);
        ImGui::Render();
    }
}

void Emu::Settings::processEvent(sf::Event event) {
    if(isOpen) {
        if(event.type == sf::Event::JoystickButtonPressed) {
            std::cout << "bp" << std::endl;
            sf::Joystick::Identification id = sf::Joystick::getIdentification(event.joystickButton.joystickId);
            if(buttonToConfigure > -1) {
                std::cout << "joystick button: " << event.joystickButton.button << std::endl;
                buttonConfiguration[buttonToConfigure].button = event.joystickButton.button;
                buttonConfiguration[buttonToConfigure].axis = -1;
                buttonConfiguration[buttonToConfigure].axisSign = -1;
                buttonConfiguration[buttonToConfigure].vid = id.vendorId;
                buttonConfiguration[buttonToConfigure].pid = id.productId;
                buttonToConfigure = -1;
            }
        }
        if(event.type == sf::Event::JoystickMoved) {
            if(std::abs(event.joystickMove.position) > 5) {
                std::cout << "jm" << std::endl;
                std::cout << "joystick axis: " << (event.joystickMove.axis == sf::Joystick::PovX) << " : " << event.joystickMove.position << std::endl;
                sf::Joystick::Identification id = sf::Joystick::getIdentification(
                        event.joystickButton.joystickId);
                if (buttonToConfigure > -1) {
                    buttonConfiguration[buttonToConfigure].axis = event.joystickMove.axis;
                    buttonConfiguration[buttonToConfigure].axisSign = (event.joystickMove.position > 0) ? 1 : -1;
                    buttonConfiguration[buttonToConfigure].vid = id.vendorId;
                    buttonConfiguration[buttonToConfigure].pid = id.productId;
                    buttonConfiguration[buttonToConfigure].button = -1;
                    buttonToConfigure = -1;
                }
            }
        }
        if(event.type == sf::Event::KeyPressed) {
            if(buttonToConfigure > -1) {
                buttonConfiguration[buttonToConfigure].button = event.key.code;
                buttonConfiguration[buttonToConfigure].axis = -1;
                buttonConfiguration[buttonToConfigure].axisSign = -1;
                buttonConfiguration[buttonToConfigure].vid = 0;
                buttonConfiguration[buttonToConfigure].pid = 0;
                buttonToConfigure = -1;
            }
        }
    }
}