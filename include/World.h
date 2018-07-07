//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H


#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);

private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;

};


#endif //BLACKROSE_WORLD_H
