//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H


#include <SFML/Graphics.hpp>
#include "management/ResourceHolder.h"
#include "management/ResourceIdentifier.h"
#include "Characters/PlayerCharacter.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;

    std::shared_ptr<PlayerCharacter> player;
};


#endif //BLACKROSE_WORLD_H
