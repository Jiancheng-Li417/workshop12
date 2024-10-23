#ifndef GAME_H
#define GAME_H

#include <vector>
#include <algorithm>
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game {
private:
    std::vector<GameEntity*> entities;

public:
    const std::vector<GameEntity*>& get_entities() const { return entities; }
    void set_entities(const std::vector<GameEntity*>& newEntities) { entities = newEntities; }

    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        for (int i = 0; i < numShips; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }
        for (int i = 0; i < numMines; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }
        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int iteration = 0; iteration < maxIterations; ++iteration) {
            for (auto& entity : entities) {
                if (auto ship = dynamic_cast<Ship*>(entity)) {
                    ship->move(1, 0);
                }
            }

            for (auto& entity : entities) {
                if (auto mine = dynamic_cast<Mine*>(entity)) {
                    for (auto& other : entities) {
                        if (auto ship = dynamic_cast<Ship*>(other)) {
                            if (Utils::calculateDistance(ship->getPos(), mine->getPos()) < mineDistanceThreshold) {
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                            }
                        }
                    }
                }
            }

            entities.erase(std::remove_if(entities.begin(), entities.end(),
                [](GameEntity* entity) { return entity->getType() == GameEntityType::NoneType; }), entities.end());
        }
    }

    ~Game() {
        for (auto entity : entities) {
            delete entity; 
        }
    }
};

#endif // GAME_H
