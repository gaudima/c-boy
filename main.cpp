#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "arch/emu.h"
#include "windows/settings.h"
using namespace std;

int main(int argc, char **argv) {
    Emu emu(argv[0]);
    emu.run();
    return 0;
}