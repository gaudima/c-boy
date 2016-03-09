//
// Created by gaudima on 30.01.2016.
//

#ifndef C_BOY_SETTINGS_H
#define C_BOY_SETTINGS_H
#include <string>
#include <SFML/Graphics.hpp>
#include "../arch/emu.h"
#include "../imgui/imgui.h"
class Emu::Settings {
public:
    enum GbButton {
        Dpad_Right,
        Dpad_Left,
        Dpad_Up,
        Dpad_Down,
        Button_A,
        Button_B,
        Button_Select,
        Button_Start
    };
    struct ButtonConfig {
        unsigned int vid;
        unsigned int pid;
        int axis;
        int axisSign;
        int button;
    };
    ButtonConfig buttonConfiguration[8];
    struct VisualSettings {
        float scaleFactor;
        bool enableAA;
        bool enableDebug;
        int ffSpeed;
    };
    VisualSettings visualSettings;
    Settings(Emu *emu);
    void open();
    void close();
    void draw();
    void processEvent(sf::Event event);
private:
    Emu *emu;
    bool isOpen;
    bool cpuPauseSave;
    sf::View view;
    enum CurrentWindow {
        Controls,
        Visuals
    };
    void loadFromFile();
    void saveToFile();
    void drawConfigButton(const char *name, GbButton button);
    int buttonToConfigure;
    CurrentWindow currentWindow;
    ImVec4 controlsColor;
    ImVec4 visualsColor;
    void drawControlsWindow();
    void drawVisualsWindow();
};


#endif //C_BOY_SETTINGS_H
