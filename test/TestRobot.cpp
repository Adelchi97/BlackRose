//
// Created by Elena Faillace on 19/09/2018.
//

#include "gtest/gtest.h"
#include "../include/Characters/RobotFighter.h"
#include "../include/Characters/RobotShooter.h"

struct TestRobot: testing::Test {
    TextureHolder textures;
};

TEST_F(TestRobot, RobotShooter_Costructor_Test) {
    textures.load(Textures::RobotRed,"../../Media/Characters/Robot/red.png");
    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");

    std::shared_ptr<Strategy> strategy = std::make_shared<PatrolStrategy>(sf::Vector2u(1600,1600));
    RobotShooter robotShooter(textures, sf::Vector2u(1600, 1600), strategy);

    EXPECT_EQ(robotShooter.hp, 40);
    EXPECT_EQ(robotShooter.attackDamage, 40);
    EXPECT_TRUE(std::dynamic_pointer_cast<RangedWeapon>(robotShooter.weapon));
    EXPECT_EQ(robotShooter.active, true);
    EXPECT_EQ(robotShooter.subType, Enemy::SubType::robotRed);
    robotShooter.hp = 0;
    robotShooter.update();
    EXPECT_EQ(robotShooter.active, false);
}

TEST_F(TestRobot, RobotFighter_Costructor_Test) {
    textures.load(Textures::RobotGray,"../../Media/Characters/Robot/gray.png");

    std::shared_ptr<Strategy> strategy = std::make_shared<PatrolStrategy>(sf::Vector2u(1600,1600));
    RobotFighter robotFighter(textures, sf::Vector2u(1600, 1600), strategy);

    EXPECT_EQ(robotFighter.hp, 20);
    EXPECT_EQ(robotFighter.attackDamage, 20);
    EXPECT_EQ(robotFighter.active, true);
    EXPECT_EQ(robotFighter.subType, Enemy::SubType::robotGray);
    robotFighter.hp = 0;
    robotFighter.update();
    EXPECT_EQ(robotFighter.active, false);
}