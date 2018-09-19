//
// Created by Elena Faillace on 24/07/2018.
//

#include "gtest/gtest.h"
#include "../include/Objects/Healpack.h"

struct HealPackTest: testing::Test {

    TextureHolder textures;
};


TEST_F(HealPackTest, Healpack_Costructor_Test) {

    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    Healpack healpack = Healpack(textures);

    EXPECT_EQ(healpack.active, true);
    EXPECT_EQ(healpack.equipped, false);
    EXPECT_EQ(healpack.counterLifeTime, 1);
    EXPECT_EQ(healpack.getSprite().getPosition(), sf::Vector2f(300,300));
    EXPECT_EQ(healpack.powerUp, 50);
}

TEST_F(HealPackTest, HealPackTest_Update_Test) {

    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    Healpack healpack = Healpack(textures);

    healpack.position = sf::Vector2f(42, -42);
    healpack.update();
    EXPECT_EQ(healpack.sprite.getPosition(), sf::Vector2f(42, -42));
}
