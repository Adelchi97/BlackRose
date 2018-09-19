//
// Created by Elena Faillace on 19/09/2018.
//

#include "gtest/gtest.h"
#include "../include/Characters/EnemyFactory.h"

struct TestEnemyFactory: testing::Test {
    TextureHolder textures;
};

TEST_F(TestEnemyFactory, EnemyFactory_Create_Test) {
    textures.load(Textures::RobotGray,"../../Media/Characters/Robot/gray.png");
    EnemyFactory enemyFactory;

    std::shared_ptr<Enemy> enemy = enemyFactory.createEnemy(Enemy::SubType::robotGray, textures, sf::Vector2u(1600, 1600));
    EXPECT_TRUE(std::dynamic_pointer_cast<RobotFighter>(enemy));

    textures.load(Textures::RobotRed,"../../Media/Characters/Robot/red.png");
    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");

    std::shared_ptr<Enemy> enemy2 = enemyFactory.createEnemy(Enemy::SubType::robotRed, textures, sf::Vector2u(1600,
            1600));
    EXPECT_TRUE(std::dynamic_pointer_cast<RobotShooter>(enemy2));
}
