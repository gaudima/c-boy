#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "arch/emu.h"
#include "windows/settings.h"
using namespace std;

int main() {
    Emu emu;
    emu.run();
    return 0;
}