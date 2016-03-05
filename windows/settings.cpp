//
// Created by gaudima on 30.01.2016.
//

#include "settings.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui-events-SFML.h"
#include "../imgui/imgui-rendering-SFML.h"
#include "../jsoncpp/json/json.h"
#include <SFML/Graphics.hpp>
#include <fstream>

Settings::Settings() {
    currentWindow = Controls;
    open = false;
    for(int i = 0; i < 8; i++) {
        buttonConfiguration[i].button = -1;
        buttonConfiguration[i].axis = -1;
        buttonConfiguration[i].vid = 0;
        buttonConfiguration[i].pid = 0;
    }
    visualSettings.scaleFactor = 2;
    visualSettings.enableAA = false;
    visualSettings.enableDebug = true;
    buttonToConfigure = -1;
    loadFromFile();
}

void Settings::loadFromFile() {
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
    visualSettings.enableAA = root["visuals"]["enableAA"].asBool();
    visualSettings.enableDebug = root["visuals"]["enableDebug"].asBool();
}

void Settings::saveToFile() {
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
    out << root;
    out.close();
}

void Settings::drawConfigButton(const char *name, GbButton button) {
    ImGui::Text(name);
    ImGui::SameLine();
    char buttonText[50];
    char deviceName[20];
    if(buttonConfiguration[button].vid == 0 && buttonConfiguration[button].pid == 0) {
        sprintf(deviceName, "Kbd");
    } else {
        sprintf(deviceName, "Joy%Xx%X", buttonConfiguration[button].vid, buttonConfiguration[button].pid);
    }
    if(buttonConfiguration[button].button == -1 && buttonConfiguration[button].axis == -1) {
        sprintf(buttonText, "Press to assign");
    } else if(buttonConfiguration[button].axis > -1) {
        sprintf(buttonText, "%s_Axis: %d%s", deviceName, buttonConfiguration[button].axis,
                (buttonConfiguration[button].axisSign > 0) ? "+" : "-");
    } else if(buttonConfiguration[button].button > -1) {
        sprintf(buttonText, "%s_Button: %d", deviceName, buttonConfiguration[button].button);
    }
    ImGui::PushID(button);
    if(ImGui::Button(buttonText)) {
        buttonToConfigure = button;
    }
    ImGui::PopID();
}

void Settings::drawControlsWindow() {
    ImGui::BeginChild("child0", ImVec2(0, 0), true);
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
    ImGui::EndChild();
}

void Settings::drawVisualsWindow() {
    ImGui::AlignFirstTextHeightToWidgets();
    ImGui::Text("ScaleFactor:");
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
    if(ImGui::Combo("", &index, "x2\0x2.5\0x3\0x3.5\0x4")) {
        visualSettings.scaleFactor = factorForIndex[index];
    }
    ImGui::Checkbox("Enable antialiasing", &visualSettings.enableAA);
    ImGui::Checkbox("Enable debug mode", &visualSettings.enableDebug);
}

void Settings::draw(sf::RenderWindow *window) {
    if(open) {
        bool tmp = true;
        sf::Vector2u size = window->getSize();
        ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::Begin("Controls", &tmp, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                       ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);

        if(ImGui::BeginMenuBar()) {
            if(ImGui::Button("Controls")) {
                currentWindow = Controls;
            }
            ImGui::SameLine();
            if(ImGui::Button("Visuals")) {
                currentWindow = Visuals;
            }
            ImGui::SameLine(ImGui::GetWindowWidth() - 20);
            if(ImGui::Button("X")) {
                saveToFile();
                open = false;
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
        window->clear(sf::Color::Red);
        ImGui::Render();
    }
}

void Settings::processEvent(sf::Event event) {
    if(open) {
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