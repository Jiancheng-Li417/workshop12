#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    Ship ship(10, 10);
    Mine mine(15, 10);

    std::cout << "Ship Position: " << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << "\n";
    ship.move(5, 0);
    std::cout << "Ship New Position: " << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << "\n";

    Explosion explosion = mine.explode();
    explosion.apply(ship);

    std::cout << "Ship Position after explosion: " << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << "\n";

    return 0;
}
