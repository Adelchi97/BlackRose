//
// Created by Ludovico on 28/06/2018.
//

#ifndef SFMLTEST3_PROCEDURALMAP_H
#define SFMLTEST3_PROCEDURALMAP_H

#include "SFML/Graphics.hpp"
#include "Objects/Tile.h"



class ProceduralMap {
public:

    //ProceduralMap(const TextureHolder &textures);
    ProceduralMap(const TextureHolder &textures, Tile::BackGroundType backGroundType, sf::Vector2u windowSize);

    ~ProceduralMap();

    bool createLevel(int inx, int iny);
    //Tile::BackGroundType getCell (int x, int y) const;
    void setCell (int x, int y, Tile::BackGroundType inputTile);
    std::shared_ptr<Tile> getCell (int x, int y);

private:

    bool makeCorridor(int x, int y, int length, int direction);
    bool makeRoom(int x, int y, int direction);
    //ci può essere soltanto una bossroom per livello
    bool makeBossRoom(int x, int y);
    int getRand(int min, int max);


public:
    std::vector<std::shared_ptr<Tile>> tileMap;


private:

    std::shared_ptr<sf::RenderWindow> mapWindow;
    std::vector<std::shared_ptr<Tile>> wallArray;

    const TextureHolder& textures;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    //la misura della mappa sarà costante per ogni livello essendo in un torre
    const int xsize; //800 perchè sono 100 colonne da 8 pixel
    const int ysize; // stessa cosa, è una torre a pianta quadrata

    const int maxRoomSide;
    const int minRoomSide;

    const int numSideCell = 25;
    int towerLevel = 0;
    int objects; //chest, loot on the map


    //rooms have priority, define rooms and corridors chance to be created
    const int chanceRoom;
    const int chanceCorridor;
    const int chance1Door = 30;
    const int chance2Door = 85;
    const int chance3Door = 95;
    const int chance4Door = 100;




    bool bossRoom = false;
    const int minBossRoomSide = 10;

    bool mapFilled = false;
};


#endif //SFMLTEST3_PROCEDURALMAP_H
