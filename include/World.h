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
#include "ProceduralMap.h"
#include "TextureDisplay.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock);

//private:
    void createWeapons();
    void createEnemies();

    void useWeapon();

    void drawProjectiles();
    void drawEnemies();
    void drawMap();
    void drawObjects();
    void drawTextureDisplayed();

    void updateProjectiles();
    void updateEnemies();
    void updateObjects();
    void updateTextureDisplayed();

    void checkCollision();
    void collisionProjectiles();
    void collisionPlayerEnemy();
    void checkCollection();

private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;
    std::vector<std::shared_ptr<TextureDisplay>> textureDisplayArray;
    sf::Clock textureTimer;

    std::shared_ptr<PlayerCharacter> player;
    std::vector<std::shared_ptr<Enemy>> enemyArray;
    std::shared_ptr<RangedWeapon> rangedWeapon;

    std::vector<std::shared_ptr<Projectile>> projectileArray;
    std::vector<std::shared_ptr<Object>> collectableObject;

    std::shared_ptr<ProceduralMap> map;

};


#endif //BLACKROSE_WORLD_H
