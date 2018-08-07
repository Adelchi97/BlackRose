//
// Created by Ludovico on 28/06/2018.
//

#include "ctime"
#include "../include/ProceduralMap.h"
/*
Textures::ID toTextureID( ProceduralMap::TileType type) {
    switch(type) {
        case ProceduralMap::Floor:
            return Textures::labTile;
        case ProceduralMap::Wall:
            return Textures::labTile;
        case ProceduralMap::Unused:
            return Textures::labTile;
/*
        case TileType::Door:
            return Textures::HeroWhite;
        case TileType::dirtFloor:
            return Textures::HeroGray;
        case TileType::dir:
            return Textures::StarLord;

    }
}
*/

ProceduralMap::ProceduralMap(const TextureHolder &textures): xsize(800), ysize(800), objects(10), oldSeed(0), chanceRoom(80), chanceCorridor(20),
                                minRoomSide(5), maxRoomSide(xsize/10), textures(textures) {
    for (int i=0; i<25; i++) {
        for  (int j=0; j<25; j++) {
            tileMap.emplace_back(std::make_shared<Tile>(textures, sf::Vector2f(i,j), Tile::BackGroundType::labFloor));
        }
    }
    //  levelMap = 0; // 0 is TileType::Unused, see the enum class TipeTyle
    //  createLevel(xsize,ysize);
}

ProceduralMap::ProceduralMap(const TextureHolder &textures, Tile::BackGroundType backGroundType): xsize(800), ysize(800),
               objects(10), oldSeed(0), chanceRoom(80), chanceCorridor(20), minRoomSide(5), maxRoomSide(xsize/10),
               textures(textures) {

    for (int i=0; i<25; i++) {
        for  (int j=0; j<25; j++) {
            tileMap.emplace_back(std::make_shared<Tile>(textures, sf::Vector2f(i,j), backGroundType));
        }
    }
    //tileMap.emplace_back(std::make_shared<Tile>(textures, sf::Vector2f(2,2),Tile::BackGroundType::labFloor ));
    setCell(0,0, Tile::BackGroundType::labFloor);
    //  levelMap = 0; // 0 is TileType::Unused, see the enum class TipeTyle
    //  createLevel(xsize,ysize);
}


ProceduralMap::~ProceduralMap() {

}

int ProceduralMap::getRand(int x, int y){
    long seed = time(nullptr) + oldSeed;
    oldSeed = seed;
}


/*
Tile::BackGroundType ProceduralMap::getCell(int x, int y) const {
    Tile::BackGroundType tmp = *tileMap[x*y]::Tile::BackGroundType ;
    return tmp;

}
*/
//TODO questa funzione va modificata affinché lavori interfacciandosi con tileMap[i].coordinate

void ProceduralMap::setCell(int x, int y, Tile::BackGroundType inputTile) {

    //Tile(textures, tileMap[x+y*25]->coordinates, inputTile);

    std::shared_ptr<Tile> tmp = std::make_shared<Tile>(textures, sf::Vector2f(x,y), inputTile);
    //std::shared_ptr<Tile>(std::move(tileMap[x+y*25]).swap(tmp));

    //std::shared_ptr& operator=(const std::shared_ptr<Tile>& tileMap[x+y*25]) noexcept;

    std::shared_ptr<Tile>(tmp).swap(tileMap[x+y*25]);

    //tileMap[x+y*25]->coordinates.x = x;
    //tileMap[x+y*25]->coordinates.y = y;
    //tileMap[x+y*25] = std::make_shared<Tile>(textures, sf::Vector2f(x,y), inputTile);

    //tileMap.at(x*y) = (std::make_shared<Tile>(textures, sf::Vector2f(x,y), inputTile));


    //tileMap.insert(tileMap[(x*y)+1],  );
    //std::shared_ptr<Tile> tmp = std::make_shared<Tile>(textures, sf::Vector2f(x,y), inputTile);
    //tileMap[x*y].swap(tmp);
}

//    int rand;
/*
    tileSprite.setPosition(x*32, y*32);
    if(tile == Floor){
        tileSprite.setTextureRect(sf::IntRect(0,0,32,32));
        mapWindow->draw(tileSprite);
        levelMap[x + xsize*y] = 1;
    }
    if (tile == Unused){
        tileSprite.setTextureRect(sf::IntRect(32,0,32*2,32));
        mapWindow->draw(tileSprite);
        levelMap[x + xsize*y] = 0;
    }
    if(tile == Wall){
        tileSprite.setTextureRect(sf::IntRect(32,32,32*2,32*2));
        mapWindow->draw(tileSprite);
        levelMap[x + xsize*y] = 2;
    }

    if (tile == TileType::Floor){
        rand = getRand(1,3);
        switch (rand){
            case 1:
                levelMap[x + xsize * y] = TileType::Floor;
                break;
            case 2:
                levelMap[x + xsize * y] = TileType::dirtFloor;
                break;
            case 3:
                levelMap[x + xsize * y] = TileType::brokenFloor;
                break;
            default:
                levelMap[x + xsize * y] = TileType::Floor;
                break;
        }
    }

    else if (tile == TileType::Wall){
        rand = getRand(1,3);
        switch (rand){
            case 1:
                levelMap[x + xsize * y] = TileType::Wall;
                break;
            case 2:
                levelMap[x + xsize * y] = TileType::dirtWall;
                break;
            case 3:
                levelMap[x + xsize * y] = TileType::brokenWall;
                break;
            default:
                levelMap[x + xsize * y] = TileType::Wall;
                break;
        }

    }
    else if (tile == TileType::Door){
        rand = getRand(1,2);
        switch (rand){
            case 1:
                levelMap[x + xsize * y] = TileType::Door;
                break;
            case 2:
                levelMap[x + xsize * y] = TileType::BrokenDoor;
                break;
            default:
                levelMap[x + xsize * y] = TileType::Door;
                break;
        }
    }

}
*/

bool ProceduralMap::makeBossRoom(int x, int y) {

    //TODO
    bossRoom = true;
    return true;
}

//TODO va adattata alla struttura dati scelta
/*
bool ProceduralMap::makeRoom(int x, int y, int direction) {

    //check if a bossRoom is needed
    if (!bossRoom){
        //I want bossRoom will be build only in a central part of the map
        if((x >= xsize/4 && x <= (xsize/4)*3) && (y >= ysize/4 && y <= (ysize/4)*3)){
            makeBossRoom(x, y);
        }
    }

// rooms will respect the min and max width and length, the walkable tiles will be 2 less for length and 2 less for width
    int xLength = getRand(minRoomSide, maxRoomSide);
    int yLength = getRand(minRoomSide, maxRoomSide);
    //two cases in room creation. I'll manage what tile version of wall or floor to take in SetCell
    TileType wall = TileType::Wall;
    TileType floor = TileType ::Floor;
    int dir = 0;
    if (direction > 0 && direction < 4)
        dir = direction;

    switch (dir) {
        case 0:
            //north
            //Check if there's enough space left for it. It checks a row and a column more than what we need
            for (int yTemp = y; yTemp > (y - yLength); yTemp--) {  //decrementing y means to go north
                if (yTemp < 0 || yTemp > ysize)
                    return false; // not enough lenght space, out from makeroom and the calling function will call again makeroom avoiding the same direction
                //if xLength is odd the room will be one more in the right half
                for (int xTemp = (x - xLength / 2); xTemp < (x + ((xLength + 1) / 2)); xTemp++) {
                    if (xTemp < 0 || xTemp > xsize)
                        return false;  //not enough width space
                    if (getCell(xTemp, yTemp) != Tile::BackGroundType::woodFloor)
                        return false; //no space left
                }
            }

            //we're still here, build
            for (int ytemp = y; ytemp > (y - yLength); ytemp--) {
                for (int xtemp = (x - xLength / 2); xtemp < (x + ((xLength + 1) / 2)); xtemp++) {
                    //start with the walls
                    if (xtemp == (x - xLength / 2))
                        setCell(xtemp, ytemp, Tile::BackGroundType::metalWall);
                    else if (xtemp == (x + (xLength - 1) / 2))
                        setCell(xtemp, ytemp, Tile::BackGroundType::metalWall);
                    else if (ytemp == y)
                        setCell(xtemp, ytemp, Tile::BackGroundType::metalWall);
                    else if (ytemp == (y - yLength + 1))
                        setCell(xtemp, ytemp, Tile::BackGroundType::metalWall);
                        //and then fill with the floor
                    else {
                        tileTexture = textures.get(toTextureID(floor));
                        tileSprite.setTexture(tileTexture);
                        tileSprite.setTextureRect(sf::IntRect(0,0,32,32));
                        setCell(xtemp, ytemp, floor);

                    }
                }
            }
            break;
        case 1:
            //east
            for (int ytemp = (y - yLength / 2); ytemp < (y + (yLength + 1) / 2);
                 ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = x; xtemp < (x + xLength); xtemp++) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = (y - yLength / 2); ytemp < (y + (yLength + 1) / 2);
                 ytemp++) {
                for (int xtemp = x; xtemp < (x + xLength); xtemp++) {

                    if (xtemp == x)
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x + xLength - 1))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y - yLength / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + (yLength - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
        case 2:
            //south
            for (int ytemp = y; ytemp < (y + yLength); ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = (x - xLength / 2); xtemp < (x + (xLength + 1) / 2);
                     xtemp++) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = y; ytemp < (y + yLength); ytemp++) {
                for (int xtemp = (x - xLength / 2); xtemp < (x + (xLength + 1) / 2);
                     xtemp++) {

                    if (xtemp == (x - xLength / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x + (xLength - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == y)
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + yLength - 1))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
        case 3:
            //west
            for (int ytemp = (y - yLength / 2); ytemp < (y + (yLength + 1) / 2);
                 ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = x; xtemp > (x - xLength); xtemp--) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = (y - yLength / 2); ytemp < (y + (yLength + 1) / 2);
                 ytemp++) {
                for (int xtemp = x; xtemp > (x - xLength); xtemp--) {

                    if (xtemp == x)
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x - xLength + 1))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y - yLength / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + (yLength - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
    }

    // successful build
    return true;
}


//TODO va adattata alla struttura dati
/*
bool ProceduralMap::makeCorridor(int x, int y, int lenght, int direction) {
//define the dimensions of the corridor (er.. only the width and height..)
    int len = getRand(2, lenght);
    TileType floor = TileType::Floor;
    int dir = 0;
    if (direction > 0 && direction < 4)
        dir = direction;

    int xtemp = 0;
    int ytemp = 0;

    switch (dir) {
        case 0:
            //north
            //check if there's enough space for the corridor
            //start with checking it's not out of the boundaries
            if (x < 0 || x > xsize)
                return false;
            else
                xtemp = x;

            //same thing here, to make sure it's not out of the boundaries
            for (ytemp = y; ytemp > (y - len); ytemp--) {
                if (ytemp < 0 || ytemp > ysize)
                    return false; // out of boundaries
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            //if we're still here, let's start building
            for (ytemp = y; ytemp > (y - len); ytemp--) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 1:
            //east
            if (y < 0 || y > ysize)
                return false;
            else
                ytemp = y;

            for (xtemp = x; xtemp < (x + len); xtemp++) {
                if (xtemp < 0 || xtemp > xsize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (xtemp = x; xtemp < (x + len); xtemp++) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 2:
            //south
            if (x < 0 || x > xsize)
                return false;
            else
                xtemp = x;

            for (ytemp = y; ytemp < (y + len); ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (ytemp = y; ytemp < (y + len); ytemp++) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 3:
            //west
            if (ytemp < 0 || ytemp > ysize)
                return false;
            else
                ytemp = y;

            for (xtemp = x; xtemp > (x - len); xtemp--) {
                if (xtemp < 0 || xtemp > xsize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (xtemp = x; xtemp > (x - len); xtemp--) {
                setCell(xtemp, ytemp, floor);
            }
            break;
    }

    // Successful build
    return true;
}
*/

//TODO va dattata alla struttura dati
/*
bool ProceduralMap::createLevel(int inx, int iny) {
    towerLevel++;
    objects = getRand(10, 100);


    for (int y = 0; y < ysize; y++) {
        for (int x = 0; x < xsize; x++) {
            // making the borders of unwalkable walls
            if (y == 0)
                setCell(x, y, Wall);
            else if (y == ysize - 1)
                setCell(x, y, Wall);
            else if (x == 0)
                setCell(x, y, Wall);
            else if (x == xsize - 1)
                setCell(x, y, Wall);

                //and fill the rest with unused
            else
                setCell(x, y, Unused);
        }
    }

    //start with creating a room in a random location, all its features are random
    //makeRoom(getRand(0, xsize), getRand(0, ysize), getRand(0, 3));
    /*
    //now we have a room (or a bossRoom)
    int buildSpace = getRand(0, 100);
    int vaildTile = -1;

    while(mapFilled){
        //TODO
    }

    //TODO


}
*/
