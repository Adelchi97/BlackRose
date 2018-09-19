//
// Created by Elena Faillace on 19/09/2018.
//
#include "gtest/gtest.h"
#include "../include/Objects/RangedWeapon.h"

struct RangedWeaponTest: testing::Test {

    TextureHolder textures;
};


TEST_F(RangedWeaponTest, RangedWeapon_Costructor_Test) {

    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");
    RangedWeapon rangedWeapon(textures, RangedWeapon::Type::redShooter);

    EXPECT_EQ(rangedWeapon.typeWeapon, RangedWeapon::Type::redShooter);
    EXPECT_EQ(rangedWeapon.projectileType, Projectile::Type::redProjectile);
    EXPECT_EQ(rangedWeapon.type, Object::rangedWeapon);
    EXPECT_EQ(rangedWeapon.equipped, false);
    EXPECT_EQ(rangedWeapon.active, true);
    EXPECT_EQ(rangedWeapon.range, 400);
    EXPECT_EQ(rangedWeapon.power, 10);
    EXPECT_EQ(rangedWeapon.projectilesCounter, 40);
    EXPECT_EQ(rangedWeapon.counterLifeTime, 1);

    //Test different weapon
    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");
    RangedWeapon rangedWeapon2(textures, RangedWeapon::Type::energyShooter);
    EXPECT_EQ(rangedWeapon2.typeWeapon, RangedWeapon::Type::energyShooter);
    EXPECT_EQ(rangedWeapon2.projectileType, Projectile::Type::energyBall);
}

TEST_F(RangedWeaponTest, RangedWeapon_AddStuff_Test) {

    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");
    RangedWeapon rangedWeapon(textures, RangedWeapon::Type::energyShooter);
    rangedWeapon.addStuff(1200);
    EXPECT_EQ(rangedWeapon.projectilesCounter, 1240);

    RangedWeapon rangedWeapon2(textures, RangedWeapon::Type::energyShooter);
    rangedWeapon2.addStuff(-20);
    EXPECT_EQ(rangedWeapon2.projectilesCounter, 40);
}

TEST_F(RangedWeaponTest, RangedWeapon_Use_Test) {
    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");
    RangedWeapon rangedWeapon(textures, RangedWeapon::Type::energyShooter);

    rangedWeapon.use();
    EXPECT_EQ(rangedWeapon.projectilesCounter, 39);
    rangedWeapon.projectilesCounter = 0;
    EXPECT_EQ(rangedWeapon.use(), false);
}

TEST_F(RangedWeaponTest, RangedWeapon_ChangeType_Test) {
    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");
    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");

    RangedWeapon rangedWeapon(textures, RangedWeapon::Type::redShooter);

    rangedWeapon.changeType(RangedWeapon::Type::energyShooter);
    EXPECT_EQ(rangedWeapon.typeWeapon, RangedWeapon::Type::energyShooter);
    EXPECT_EQ(rangedWeapon.projectileType, Projectile::Type::energyBall);
}