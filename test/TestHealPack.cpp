//
// Created by Elena Faillace on 24/07/2018.
//

#include "gtest/gtest.h"
#include "../include/Objects/Healpack.h"

//setting fixture
struct HealPackTest: testing::Test {

    //std::shared_ptr<World> world1 = std::make_shared<World>(window1, textures);

};

TEST_F(HealPackTest, Healpack_Costructor_Test) {

    TextureHolder textures;
    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    Healpack healpack = Healpack(textures);
    EXPECT_EQ(healpack.active, true);
    EXPECT_EQ(healpack.equipped, false);
    EXPECT_EQ(healpack.counterLifeTime, 1);
    EXPECT_EQ(healpack.getSprite().getPosition(), sf::Vector2f(300,300));
    EXPECT_EQ(healpack.powerUp, 50);
}

TEST_F(HealPackTest, HealPackTest_Update_Test) {
    TextureHolder textures;
    textures.load(Textures::healPack,"../../Media/Objects/grayHealPack.png");
    Healpack healpack = Healpack(textures);
    healpack.position = sf::Vector2f(42, -42);
    healpack.update();
    EXPECT_EQ(healpack.sprite.getPosition(), sf::Vector2f(42, -42));
}

/*
TEST(TestOggetti, testConsistenzaCostruttore) {
    std::cout << "Test consistenza costruttori.\n";

    Oggetto oggettoTest(15., "Hatkanda", "L'oggetto di un film generico", 400);
    EXPECT_EQ(oggettoTest.getPeso(), 15.);
    EXPECT_EQ(oggettoTest.getNome(), "Hatkanda");
    EXPECT_EQ(oggettoTest.getDescrizione(), "L'oggetto di un film generico");
    EXPECT_EQ(oggettoTest.getValore(), 400);
    EXPECT_GT(oggettoTest.attacca().getAmmontare(), 2.5); //ln(16) non so quanto faccia di preciso
}*/