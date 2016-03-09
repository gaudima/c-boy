//
// Created by gaudima on 05.03.2016.
//

#ifndef C_BOY_FILEDIALOG_H
#define C_BOY_FILEDIALOG_H

#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../arch/emu.h"

class Emu::FileDialog {
public:
    FileDialog(Emu *emu);
    ~FileDialog();
    void draw();
    void open();
    void close();
private:
    struct DirEntry {
        bool isDir;
        std::string name;
    };
    bool isOpen;
    bool cpuPauseSave;
    Emu *emu;
    std::vector<DirEntry> currentDir;
    std::vector<std::string> drives;
    char **drivesCArr;
    int currentDrive;
    std::string currentPath;
    int selectedRow;
    const uint32_t cp1251_utf8[128];
    void readDir(std::string dir);
    void getDrivesList();
    void clearDrivesCArr();
    std::string cp1251ToUtf8(std::string in);
    std::string winPathToUnix(std::string path);
    std::string appendToPath(std::string path, std::string app);
};


#endif //C_BOY_FILEDIALOG_H
