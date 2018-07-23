//
// Created by Ludovico on 23/07/2018.
//

#ifndef BLACKROSE_WALL_H
#define BLACKROSE_WALL_H

#include "Entity.h"
#include "management/ResourceIdentifier.h"
#include "management/ResourceHolder.h"

class Wall : public Entity {
public:
    Wall(const TextureHolder& textures);

    //void update;
private:
    const TextureHolder& textures;
};


#endif //BLACKROSE_WALL_H
