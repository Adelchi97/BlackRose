//
// Created by Elena Faillace on 19/09/2018.
//
#include "gtest/gtest.h"
#include "../include/Objects/Tile.h"

struct TestTile: testing::Test {
    TextureHolder textures;
};

TEST_F(TestTile, Tile_Costructor_Test) {
    textures.load(Textures::labTile, "../../Media/Tiles/corridor.png");
    Tile tile(textures, sf::Vector2f(20,20), Tile::BackGroundType::woodFloor);
    EXPECT_EQ(tile.backGround, Tile::BackGroundType::woodFloor);
    EXPECT_EQ(tile.getSprite().getPosition(), sf::Vector2f(20 * 64, 20 * 64));

    Tile tile2(textures, sf::Vector2f(20,20), Tile::BackGroundType::labFloor);
    EXPECT_EQ(tile2.backGround, Tile::BackGroundType::labFloor);

    Tile tile3(textures, sf::Vector2f(20,20), Tile::BackGroundType::cementFloor);
    EXPECT_EQ(tile3.backGround, Tile::BackGroundType::cementFloor);

    textures.load(Textures::metalWall, "../../Media/Walls/wall.png");
    Tile tile4(textures, sf::Vector2f(20,20), Tile::BackGroundType::metalWall);
    EXPECT_EQ(tile4.backGround, Tile::BackGroundType::metalWall);


}