#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.initGame(5, 5, 100, 100);
    game.gameLoop(10, 10.0);

    return 0;
}
