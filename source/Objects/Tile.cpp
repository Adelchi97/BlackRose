//
// Created by Elena Faillace on 24/07/2018.
//

#include "../../include/Objects/Tile.h"
#include "../../include/management/ResourceIdentifier.h"

Textures::ID toTextureID(Tile::BackGroundType type) {
    switch(type) {
        case Tile::BackGroundType::labFloor:
            return Textures::ID::labTile;
        case Tile::BackGroundType ::woodFloor:
            return Textures::ID ::labTile;//woodTile;
        case Tile::BackGroundType ::metalFloor:
            return Textures::ID::labTile;//metalTile;
        case Tile::BackGroundType::cementFloor:
            return Textures::ID::labTile;//cementTile;
        case Tile::BackGroundType::baseFloor:
            return Textures::ID::baseTile;
        case Tile::BackGroundType::metalWall:
            return  Textures::ID::metalWall;
        default:
            return Textures::ID::baseTile;
    }
};

Tile::Tile(const TextureHolder &textures, sf::Vector2f coordinates, BackGroundType btype): textures(textures), type
        (TileType::Floor), backGround(btype), coordinates(coordinates) {

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);

    texture = textures.get(toTextureID(backGround));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(64*0,64*0,64,64));
    rect.setSize(sf::Vector2f(64,64));

    rect.setPosition(coordinates.x * 64, coordinates.y * 64);
    sprite.setPosition(rect.getPosition());

}
/*
Tile::Tile(const TextureHolder &textures, sf::Vector2f coordiantes): textures(textures), type(TileType::Floor),
                                                                     coordinates(coordiantes), backGround
                                                                             (BackGroundType::labFloor) {
    texture = textures.get(toTextureID(backGround));
    sprite.setTextureRect(sf::IntRect(0,0,64,64));
    rect.setPosition(coordinates.x * 64, coordinates.y * 64);
    sprite.setPosition(rect.getPosition());
}
*/