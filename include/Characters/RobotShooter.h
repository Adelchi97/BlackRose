//
// Created by Elena Faillace on 14/09/2018.
//

#ifndef BLACKROSE_ROBOT_H
#define BLACKROSE_ROBOT_H


#include "Enemy.h"
#include "../Objects/RangedWeapon.h"

class RobotShooter: public Enemy {
public:

    explicit RobotShooter(const TextureHolder& textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy);

    void update() final;

public:
    std::shared_ptr<Weapon> weapon;

private:
    sf::Clock shootingTimer;
    const TextureHolder& textures;

};


#endif //BLACKROSE_ROBOT_H
