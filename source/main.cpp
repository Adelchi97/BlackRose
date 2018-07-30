#include <iostream>

#include "../include/Game.h"

int main() {
    try {
        Game game;
        game.run();
    } catch (std::exception& ex) {
        std::cout << "\nEXCEPTION: " << ex.what() << std::endl;
    }
}
