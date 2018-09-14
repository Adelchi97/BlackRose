//
// Created by Elena Faillace on 14/09/2018.
//

#include "../../include/Characters/RobotFighter.h"

RobotFighter::RobotFighter(const TextureHolder &textures, sf::Vector2u windowSize): textures(textures) {
    //TODO spostali in costruttore di character
    typeCharacter = enemy;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    active = true;

    subType = robotGray;
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    changeDirectionTime = generateRandom(200);
    speed = 2;
    hp = 20;
    hpMax = hp;
    attackDamage = 20;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(Textures::RobotGray);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}