#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <tuple>

enum class GameEntityType {
    ExplosionType,
    MineType,
    NoneType,
    ShipType
};

class GameEntity {
protected:
    std::tuple<int, int> position;
    GameEntityType type;

public:
    GameEntity(int x, int y, GameEntityType type) : position(x, y), type(type) {}
    std::tuple<int, int> getPos() { return position; }
    GameEntityType getType() { return type; }
};

#endif // GAMEENTITY_H
