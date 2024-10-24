#include <iostream>
#include "Utils.h"

int main() {
    auto pos1 = Utils::generateRandomPos(100, 100);
    auto pos2 = Utils::generateRandomPos(100, 100);

    std::cout << "Position 1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")\n";
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")\n";

    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance: " << distance << std::endl;

    return 0;
}
