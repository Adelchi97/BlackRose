//
// Created by Elena Faillace on 12/09/2018.
//

#ifndef BLACKROSE_CHARACTERFACTORY_H
#define BLACKROSE_CHARACTERFACTORY_H

#include "RobotShooter.h"
#include "RobotFighter.h"
#include "Enemy.h"

class EnemyFactory {
public:
    std::shared_ptr<Enemy> createEnemy(Enemy::SubType subtype, const TextureHolder&textures, sf::Vector2u windowSize);
};


#endif //BLACKROSE_CHARACTERFACTORY_H
