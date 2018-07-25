//
// Created by Elena Faillace on 24/07/2018.
//

#ifndef BLACKROSE_TILE_H
#define BLACKROSE_TILE_H

#include "../management/ResourceHolder.h"
#include "../management/ResourceIdentifier.h"
#include "../Entity.h"

class Tile : public Entity {
public:

    enum BackGroungType {
        labFloor,
        metalFloor,
        woodFloor,
        metalWall
    };

    enum TileType {
        Unused,
        Wall,
        dirtWall,
        brokenWall,
        Floor,
        dirtFloor,
        brokenFloor,
        Door, BrokenDoor,
        UpStairs,
        DownStairs,
        Chest
    }; //BrokenFloor e BrokenWall costituiscono dei passaggi come Door, Upstairs e DownStairs

    Tile(const TextureHolder& textures, sf::Vector2f coordinates, BackGroungType type);
    Tile(const TextureHolder& textures, sf::Vector2f coordinates);

public:
    TileType type;
    BackGroungType backGroung;
    sf::Vector2f coordinates;

private:
    const TextureHolder& textures;
};


#endif //BLACKROSE_TILE_H
