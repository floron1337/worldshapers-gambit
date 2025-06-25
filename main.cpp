#include <iostream>
#include "headers/Game.h"

int main() {
    Game& game = Game::getInstance();
    game.start();

    return 0;
}
