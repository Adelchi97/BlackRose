//
// Created by Ludovico on 28/06/2018.
//

#ifndef SFMLTEST3_PROCEDURALMAP_H
#define SFMLTEST3_PROCEDURALMAP_H

#include "SFML/Graphics.hpp"
#include "management/ResourceIdentifier.h"
#include "management/ResourceHolder.h"
#include "Objects/Tile.h"



class ProceduralMap {
public:

    //il dado sarà chiamato in modo puntuale, definendo il range di valori adatti a ciò che si vuole come risultato, non c'è bisogno di dividerli
    /*
    enum TileType {
        Unused = 0, Wall = 2, dirtWall, brokenWall, Floor = 1, dirtFloor, brokenFloor, Door, BrokenDoor,  UpStairs, DownStairs, Chest
    }; //BrokenFloor e BrokenWall costituiscono dei passaggi come Door, Upstairs e DownStairs
     */


    ProceduralMap(const TextureHolder &textures);
    ProceduralMap(const TextureHolder &textures, Tile::BackGroungType backGroungType);

    ~ProceduralMap();

    bool createLevel(int inx, int iny);
    int getCell (int x, int y) const;

private:

    bool makeCorridor(int x, int y, int lenght, int direction);
    //
    bool makeRoom(int x, int y, int direction); //ci può essere soltanto una bossroom per livello
    bool makeBossRoom(int x, int y);
    int getRand(int min, int max);
    //TODO implementa
    //void setCell(int x, int y, TileType tile);  //disegna il tile richiesto e riempie l'array levelMap con gli
    // interi corrispondenti agli enum

public:
    std::vector<std::shared_ptr<Tile>> tileMap;

private:

    std::shared_ptr<sf::RenderWindow> mapWindow;

    int levelMap[800*800]; //contiene interi che corrispondono a TileTYpe enum

    const TextureHolder& textures;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    //la misura della mappa sarà costante per ogni livello essendo in un torre
    const int xsize; //800 perchè sono 100 colonne da 8 pixel
    const int ysize; // stessa cosa, è una torre a pianta quadrata

    const int maxRoomSide;
    int towerLevel = 0;
    int objects; //chest, loot on the map

    long oldSeed; //old seed for Random number generation

    //rooms have priority, define rooms and corridors chance to be created
    const int chanceRoom;
    const int chanceCorridor;


    const int minRoomSide;

    bool bossRoom = false;
    const int minBossRoomSide = 10;

    bool mapFilled = false;
};


#endif //SFMLTEST3_PROCEDURALMAP_H
