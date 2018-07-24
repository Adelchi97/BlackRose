//
// Created by Elena Faillace on 24/07/2018.
//

#include "gtest/gtest.h"
#include "World.h"

//setting fixture
struct WorldTest: testing::Test {
    TextureHolder textures;

    std::shared_ptr<sf::RenderWindow> window1 = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800),
            "BlackRose", sf::Style::Default);

    //std::shared_ptr<World> world1 = std::make_shared<World>(window1, textures);

};

TEST_F(WorldTest, PlayerExeption) {

    //ASSERT_TRUE(world1->player.get() != nullptr);
}