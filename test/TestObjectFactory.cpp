//
// Created by Elena Faillace on 19/09/2018.
//

#include "gtest/gtest.h"
#include "../include/Objects/ObjectFactory.h"

struct ObjectFactoryTest: testing::Test {

    TextureHolder textures;
};

TEST_F(ObjectFactoryTest, ObjectFactory_Costructor_WithType_Test) {
    textures.load(Textures::ShootingEnergy,"../../Media/Objects/shootingEnergy.png");
    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");
    textures.load(Textures::redProjectile,"../../Media/Objects/redProjectile.png");
    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");
    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    ObjectFactory objectFactory;

    std::shared_ptr<Object> healpack = objectFactory.createObject(Object::Type::healPack, textures);
    EXPECT_TRUE(std::dynamic_pointer_cast<Healpack>(healpack));

    std::shared_ptr<Object> rangedWeapon = objectFactory.createObject(Object::Type::rangedWeapon, textures);
    EXPECT_TRUE(std::dynamic_pointer_cast<RangedWeapon>(rangedWeapon));

    std::shared_ptr<Object> meleeWeapon = objectFactory.createObject(Object::Type::meleeWeapon, textures);
    EXPECT_TRUE(std::dynamic_pointer_cast<MeleeWeapon>(meleeWeapon));

}

TEST_F(ObjectFactoryTest, ObjectFactory_Costructor_RandomType_Test) {
    textures.load(Textures::ShootingEnergy,"../../Media/Objects/shootingEnergy.png");
    textures.load(Textures::energyShooter,"../../Media/Objects/gun.png");
    textures.load(Textures::redProjectile,"../../Media/Objects/redProjectile.png");
    textures.load(Textures::redShooter,"../../Media/Objects/enemyGun.png");
    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    ObjectFactory objectFactory;

    for(int i = 0; i<50; i++) {
        std::shared_ptr<Object> object = objectFactory.createObject(textures);
        EXPECT_TRUE(std::dynamic_pointer_cast<RangedWeapon>(object) || std::dynamic_pointer_cast<Healpack>(object) ||
                object == nullptr);
        EXPECT_FALSE(std::dynamic_pointer_cast<MeleeWeapon>(object) || std::dynamic_pointer_cast<Shield>(object));
    }
}