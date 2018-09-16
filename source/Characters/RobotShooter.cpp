//
// Created by Elena Faillace on 14/09/2018.
//

#include "../../include/Characters/RobotShooter.h"

RobotShooter::RobotShooter(const TextureHolder &textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy):
    textures(textures) {

    if(std::dynamic_pointer_cast<PatrolStrategy>(strategy) != nullptr)
        this->strategy = std::make_shared<PatrolStrategy>(windowSize);
    else
        std::cout <<"errore sulla conversione della strategia"<< std::endl;


    //TODO sposta queste cose in character o enemy
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

    //create his weapon
    weapon = std::make_shared<RangedWeapon>(textures, RangedWeapon::Type::energyShooter);
}

void RobotShooter::update() {
    //TODO if it's in seek but now do every once in a while
    if(shootingTimer.getElapsedTime().asSeconds() > .5) {
        std::cout << "ROBOT SHOOT!" << std::endl;
        attackAvailable = true;
        shootingTimer.restart();
    }
    Enemy::update();

}
