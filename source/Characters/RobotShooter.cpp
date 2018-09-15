//
// Created by Elena Faillace on 14/09/2018.
//

#include "../../include/Characters/RobotShooter.h"

RobotShooter::RobotShooter(const TextureHolder &textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy):
    textures(textures) {


    if(std::dynamic_pointer_cast<PatrolStrategy>(strategy) != nullptr)
        strategy = std::make_shared<PatrolStrategy>(windowSize);
    else
        std::cout <<"errore sulla conversione della strategia"<< std::endl;


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

    //changeDirectionTime = generateRandom(200);
    speedBasic = 0;
    hp = 40;
    hpMax = hp;
    attackDamage = 40;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(Textures::RobotRed);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}