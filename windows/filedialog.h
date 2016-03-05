//
// Created by gaudima on 05.03.2016.
//

#ifndef C_BOY_FILEDIALOG_H
#define C_BOY_FILEDIALOG_H

#include <dirent.h>
#include <iostream>
#include <vector>

class FileDialog {
public:
    FileDialog();
private:
    void readDir(std::string dir);
    std::vector<dirent> curretDir;
};


#endif //C_BOY_FILEDIALOG_H
