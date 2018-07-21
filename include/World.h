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
#include "Characters/Enemy.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock);

private:
    void createWeapon();
    void createEnemies();

    void useWeapon();

    void drawProjectiles();
    void drawEnemies();

    void updateProjectiles();
    void updateEnemies();

    void checkCollision();

private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;

    std::shared_ptr<PlayerCharacter> player;
    std::vector<std::shared_ptr<Enemy>> enemyArray;
    std::shared_ptr<RangedWeapon> rangedWeapon;
    //these are in the world
    std::vector<std::shared_ptr<Projectile>> projectileArray;
};


#endif //BLACKROSE_WORLD_H
