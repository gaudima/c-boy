//
// Created by gaudima on 05.03.2016.
//

#include "filedialog.h"
#include "../imgui/imgui.h"
#include "../arch/cpu.h"
#include "settings.h"

#ifdef _WIN32
#include <windows.h>
#endif

Emu::FileDialog::FileDialog(Emu *emu) :
cp1251_utf8 {
        0x0082D0,0x0083D0,0x9A80E2,0x0093D1,0x9E80E2,0xA680E2,0xA080E2,0xA180E2,
        0xAC82E2,0xB080E2,0x0089D0,0xB980E2,0x008AD0,0x008CD0,0x008BD0,0x008FD0,
        0x0092D1,0x9880E2,0x9980E2,0x9C80E2,0x9D80E2,0xA280E2,0x9380E2,0x9480E2,
        0x000000,0xA284E2,0x0099D1,0xBA80E2,0x009AD1,0x009CD1,0x009BD1,0x009FD1,
        0x00A0C2,0x008ED0,0x009ED1,0x0088D0,0x00A4C2,0x0090D2,0x00A6C2,0x00A7C2,
        0x0081D0,0x00A9C2,0x0084D0,0x00ABC2,0x00ACC2,0x00ADC2,0x00AEC2,0x0087D0,
        0x00B0C2,0x00B1C2,0x0086D0,0x0096D1,0x0091D2,0x00B5C2,0x00B6C2,0x00B7C2,
        0x0091D1,0x9684E2,0x0094D1,0x00BBC2,0x0098D1,0x0085D0,0x0095D1,0x0097D1,
        0x0090D0,0x0091D0,0x0092D0,0x0093D0,0x0094D0,0x0095D0,0x0096D0,0x0097D0,
        0x0098D0,0x0099D0,0x009AD0,0x009BD0,0x009CD0,0x009DD0,0x009ED0,0x009FD0,
        0x00A0D0,0x00A1D0,0x00A2D0,0x00A3D0,0x00A4D0,0x00A5D0,0x00A6D0,0x00A7D0,
        0x00A8D0,0x00A9D0,0x00AAD0,0x00ABD0,0x00ACD0,0x00ADD0,0x00AED0,0x00AFD0,
        0x00B0D0,0x00B1D0,0x00B2D0,0x00B3D0,0x00B4D0,0x00B5D0,0x00B6D0,0x00B7D0,
        0x00B8D0,0x00B9D0,0x00BAD0,0x00BBD0,0x00BCD0,0x00BDD0,0x00BED0,0x00BFD0,
        0x0080D1,0x0081D1,0x0082D1,0x0083D1,0x0084D1,0x0085D1,0x0086D1,0x0087D1,
        0x0088D1,0x0089D1,0x008AD1,0x008BD1,0x008CD1,0x008DD1,0x008ED1,0x008FD1}
{
    this->emu = emu;
    isOpen = false;
    drivesCArr = NULL;
    getDrivesList();

    currentPath = appendToPath(winPathToUnix(emu->path), "..");
    currentDrive = 0;
#ifdef _WIN32
    std::string driveLetter = currentPath.substr(0, currentPath.find("/") + 1);
    for(int i = 0; i < drives.size(); i++) {
        if(drives[i] == driveLetter) {
            currentDrive = i;
            break;
        }
    }
#endif
    readDir(currentPath);
    for(auto d: drives) {
        std::cout << d << std::endl;
    }
    for(auto a: currentDir) {
        std::cout << a.isDir << " " << a.name << std::endl;
    }
}

Emu::FileDialog::~FileDialog() {
    clearDrivesCArr();
}

void Emu::FileDialog::readDir(std::string dir) {
    currentDir.clear();
    dirent *dirEntry;
    struct stat entryStat;
    selectedRow = 0;
    DIR *curDir = opendir(dir.c_str());
    if(curDir != NULL) {
        while(dirEntry = readdir(curDir)) {
            stat(std::string(dir + "/" + dirEntry->d_name).c_str(), &entryStat);
            std::string name = dirEntry->d_name;
            //name = cp1251ToUtf8(name);
            if(name != ".") {
                size_t pos = name.rfind(".");
                std::string extension;
                if (pos != std::string::npos) {
                    extension = name.substr(pos + 1, name.length() - pos - 1);
                } else {
                    extension = "";
                }
                if(S_ISDIR(entryStat.st_mode) || extension == "gb") {
                    currentDir.push_back((DirEntry) {
                            .isDir = S_ISDIR(entryStat.st_mode),
                            .name = name,
                    });
                }
            }
        }
        closedir(curDir);
        std::sort(currentDir.begin(), currentDir.end(), [&](DirEntry a, DirEntry b) {
            if(a.isDir == b.isDir) {
                return a.name < b.name;
            } else {
                return a.isDir;
            }
        });
    }
}

void Emu::FileDialog::getDrivesList() {
    clearDrivesCArr();
    drives.clear();
#ifdef _WIN32
    DWORD drivesMask = GetLogicalDrives();
    char drv[] = "A:/";
    for(int i = 0; i < sizeof(drivesMask) * 8; i++) {
        std::string driveName;
        if(drivesMask & 0x01) {
            driveName = drv;
           drives.push_back(driveName);
        }
        drivesMask >>= 1;
        drv[0]++;
    }
#else
    drives.push_back("/");
#endif
    drivesCArr = new char*[drives.size()];
    for(int i = 0; i < drives.size(); i++) {
        drivesCArr[i] = new char[drives[i].length() + 1];
        strcpy(drivesCArr[i], drives[i].c_str());
    }
}

void Emu::FileDialog::clearDrivesCArr() {
    for(int i = 0; i < drives.size(); i++) {
        delete drivesCArr[i];
    }
    if(drivesCArr != NULL) {
        delete[] drivesCArr;
    }
}

std::string Emu::FileDialog::winPathToUnix(std::string path) {
    for(size_t i = 0; i < path.length(); i++) {
        if(path[i] == '\\') {
            path[i] = '/';
        }
    }
    return path;
}

std::string Emu::FileDialog::cp1251ToUtf8(std::string in) {
#ifdef _WIN32
    std::string out;
    for(size_t i = 0; i < in.length(); i++) {
        char c = in[i];
        if(c & 0x80) {
            uint32_t v = cp1251_utf8[c & 0x7F];
            char vv = v & 0xFF;
            out.append(&vv, 1);
            vv = (v >> 8) & 0xFF;
            out.append(&vv, 1);
            if(v >> 16) {
                vv = (v >> 16) & 0xFF;
                out.append(&vv, 1);
            }
        } else {
            out.append(&c, 1);
        }
    }
    return out;
#else
    return in;
#endif
}

std::string Emu::FileDialog::appendToPath(std::string path, std::string app) {
    std::cout << path << " " << app << std::endl;

    if(path.length() > 0 && path[path.length() - 1] != '/') {
        path.append("/");
    }
    if(app.find("..") == 0) {
        path = path.substr(0, path.rfind("/", path.length() - 2) + 1);
    } else {
        path.append(app);
    }
    return path;
}

void Emu::FileDialog::open() {
    cpuPauseSave = emu->cpu->paused;
    emu->cpu->paused = true;
    isOpen = true;
}

void Emu::FileDialog::close() {
    isOpen = false;
    emu->cpu->paused = cpuPauseSave;
}

void Emu::FileDialog::draw() {
    if(isOpen) {
        bool tmp = true;
        sf::Vector2u size = emu->window->getSize();
        ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::Begin("FileDialog", &tmp, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                       ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);
        if(ImGui::BeginMenuBar()) {
            ImGui::SameLine(ImGui::GetWindowWidth() - 20);
            if(ImGui::Button("X")) {
                close();
            }
            ImGui::EndMenuBar();
        }
        ImGui::Text("Path:  ");
        ImGui::SameLine();
        ImGui::Text(cp1251ToUtf8(currentPath).c_str());
        ImGui::AlignFirstTextHeightToWidgets();
        ImGui::Text("Drive: ");
        ImGui::SameLine();
        ImGui::PushItemWidth(-1);
        if(ImGui::Combo("", &currentDrive, (const char **)drivesCArr, drives.size(), 5)) {
            currentPath = drives[currentDrive];
            readDir(currentPath);
        }
        //ImGui::PopItemWidth();
        ImGui::BeginChild("filesChild", ImVec2(0, 0), true);
        float scrollY = ImGui::GetScrollY();
        if(ImGui::GetIO().MouseWheel > 0) {
            ImGui::SetScrollY(scrollY - 20);
        } else if(ImGui::GetIO().MouseWheel < 0) {
            ImGui::SetScrollY(scrollY + 20);
        }
        ImGui::Columns(2, "files", true);
        for(int i = 0; i < currentDir.size(); i++) {
            ImGui::SetColumnOffset(1, ImGui::GetWindowWidth() - 100);
            if(ImGui::Selectable(cp1251ToUtf8(currentDir[i].name).c_str(),
                                 selectedRow == i,
                                 ImGuiSelectableFlags_SpanAllColumns)) {
                    selectedRow = i;
            }
            if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                if(currentDir[i].isDir) {
                    currentPath = appendToPath(currentPath, currentDir[i].name + "/");
                    readDir(currentPath);
                } else {
                    emu->reset();
                    emu->loadRom(appendToPath(currentPath, currentDir[i].name));
                    close();
                    if(!emu->settings->visualSettings.enableDebug) {
                        emu->cpu->paused = false;
                    }
                }
            }
            ImGui::NextColumn();
            if(currentDir[i].isDir) {
                ImGui::Text("<Dir>");
            } else {
                ImGui::Text("<Rom>");
            }
            ImGui::NextColumn();
        }
        ImGui::EndChild();
        ImGui::End();
        ImGui::PopStyleVar();
        emu->window->clear(sf::Color::Red);
        ImGui::Render();
    }
}