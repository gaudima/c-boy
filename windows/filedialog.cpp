//
// Created by gaudima on 05.03.2016.
//

#include "filedialog.h"
FileDialog::FileDialog() {
    readDir("./");
    for(auto a: curretDir) {
        std::cout << a.d_name << std::endl;
    }
}

void FileDialog::readDir(std::string dir) {
    dirent *dirEntry;
    DIR *curDir = opendir(dir.c_str());
    if(curDir != NULL) {
        while(dirEntry = readdir(curDir)) {
            curretDir.push_back(*dirEntry);
        }
    }
}
