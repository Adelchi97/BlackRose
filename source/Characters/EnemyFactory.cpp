//
// Created by Elena Faillace on 12/09/2018.
//

#include "../../include/Characters/EnemyFactory.h"


std::shared_ptr<Enemy> EnemyFactory::createEnemy(Enemy::SubType subtype, const TextureHolder& textures, sf::Vector2u windowSize) {

    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<Strategy> strategy;

    if ( subtype == Enemy::SubType::robotRed ) {
        strategy = std::make_shared<PatrolStrategy>(windowSize);
        enemy = std::make_shared<RobotShooter>(textures, windowSize, strategy);

    } else if(subtype == Enemy::SubType::robotGray ) {
        strategy = std::make_shared<PatrolStrategy>(windowSize);
        enemy = std::make_shared<RobotFighter>(textures, windowSize, strategy);
    }

    return enemy;

}
