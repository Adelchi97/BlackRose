//
// Created by Ludovico on 23/07/2018.
//



#include "../include/Wall.h"


Wall::Wall(const TextureHolder& textures): textures(textures) {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(400,200);
    texture = textures.get(Textures::FFloor);
    sprite.setTexture(texture);
    }
/*
    void Wall::update(){

}

*/