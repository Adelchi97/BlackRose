//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H


#include <SFML/Graphics.hpp>
#include "management/ResourceHolder.h"
#include "management/ResourceIdentifier.h"
#include "Characters/PlayerCharacter.h"
#include "Objects/RangedWeapon.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void createWeapon();
    void useProjectile();
    void drawProjectiles();


private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;

    std::shared_ptr<PlayerCharacter> player;
    std::shared_ptr<RangedWeapon> rangedWeapon;
    //these are in the world
    std::vector<Projectile> projectileArray;
    /*
    //TODO non so se questi vengono copiati o messi in vector, credo la prima
    Projectile projectile1;
    Projectile projectile2;
    Projectile projectile3;
    Projectile projectile4;
    Projectile projectile5;
     */
};


#endif //BLACKROSE_WORLD_H
