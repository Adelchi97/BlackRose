//
// Created by Elena Faillace on 24/07/2018.
//

#include "../include/Objects/Tile.h"
#include "../include/management/ResourceIdentifier.h"

Textures::ID toTextureID(Tile::BackGroungType type) {
    switch(type) {
        case Tile::BackGroungType::lab:
            return Textures::ID::lab;
        case Tile::BackGroungType ::wood:
            return Textures::ID ::wood;
        case Tile::BackGroungType ::metal:
            return Textures::ID::metal;
    }
};

Tile::Tile(const TextureHolder &textures, sf::Vector2f coordinates, BackGroungType btype): textures(textures),
                                                                                           backGroung(btype),
                                                                                    coordinates(coordinates) {
    texture = textures.get(toTextureID(backGroung));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(32*0,32*0,32,32));
    rect.setPosition(coordinates.x * 32, coordinates.y * 32);
    sprite.setPosition(rect.getPosition());
}

Tile::Tile(const TextureHolder &textures, sf::Vector2f coordiantes): textures(textures), type(TileType::Floor),
                                                                     coordinates(coordiantes), backGroung
                                                                             (BackGroungType::lab) {
    texture = textures.get(toTextureID(backGroung));
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    rect.setPosition(coordinates.x * 32, coordinates.y * 32);
    sprite.setPosition(rect.getPosition());
}
