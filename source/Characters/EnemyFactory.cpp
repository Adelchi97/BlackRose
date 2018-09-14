//
// Created by Elena Faillace on 12/09/2018.
//

#include "../../include/Characters/EnemyFactory.h"


std::shared_ptr<Enemy> EnemyFactory::createEnemy(Enemy::SubType subtype, const TextureHolder&textures, sf::Vector2u windowSize) {

     auto enemy = std::make_shared<Enemy>();

    if ( subtype == Enemy::SubType::robotRed ) {
        return enemy = std::make_shared<RobotShooter>(textures, windowSize);

    } else if(subtype == Enemy::SubType::robotGray) {
        return enemy = std::make_shared<RobotFighter>(textures, windowSize);
    }

    return enemy;

}
