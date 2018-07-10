//
// Created by Ludovico on 28/06/2018.
//

#ifndef SFMLTEST3_PROCEDURALMAP_H
#define SFMLTEST3_PROCEDURALMAP_H
//il dado sarà chiamato in modo puntuale, definendo il range di valori adatti a ciò che si vuole come risultato, non c'è bisogno di dividerli
enum class TileType {
    Unused = 0, Wall, dirtWall, brokenWall, Floor, dirtFloor, brokenFloor, Door, BrokenDoor,  UpStairs, DownStairs, Chest
}; //BrokenFloor e BrokenWall costituiscono dei passaggi come Door, Upstairs e DownStairs

class ProceduralMap {
public:

    ProceduralMap();
    ~ProceduralMap();

    bool createLevel(int inx, int iny);
    TileType getCell (int x, int y) const;

private:

    bool makeCorridor(int x, int y, int lenght, int direction);
    //
    bool makeRoom(int x, int y, int xlength, int ylength, int direction); //ci può essere soltanto una bossroom per livello
    bool makeBossRoom(int x, int y);
    int getRand(int min, int max);
    void setCell(int x, int y, TileType tile);

    TileType* levelMap;

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
