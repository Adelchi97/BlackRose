//
// Created by Elena Faillace on 14/09/2018.
//

#include "../../include/Characters/RobotShooter.h"
/*
Textures::ID toTextureID(Enemy::SubType type) {
    switch(type) {
        case Enemy::SubType::robotGray:
            return Textures::RobotGray;
        case Enemy::SubType::robotRed:
            return Textures::RobotRed;
    }
}
*/

RobotShooter::RobotShooter(const TextureHolder &textures, sf::Vector2u windowSize): textures(textures) {

    //TODO
    typeCharacter = enemy;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    active = true;

    subType = robotRed;
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    changeDirectionTime = generateRandom(200);
    speed = 1;
    hp = 40;
    hpMax = hp;
    attackDamage = 40;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(Textures::RobotRed);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}