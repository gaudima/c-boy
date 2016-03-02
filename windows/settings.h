//
// Created by gaudima on 30.01.2016.
//

#ifndef C_BOY_SETTINGS_H
#define C_BOY_SETTINGS_H
#include <string>

class Settings {
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
    };
    VisualSettings visualSettings;
    Settings();
    void open();
private:
    enum CurrentWindow {
        Controls,
        Visuals
    };
    void loadFromFile();
    void saveToFile();
    void drawConfigButton(const char *name, GbButton button);
    int buttonToConfigure;
    CurrentWindow currentWindow;
    void drawControlsWindow();
    void drawVisualsWindow();
};


#endif //C_BOY_SETTINGS_H
