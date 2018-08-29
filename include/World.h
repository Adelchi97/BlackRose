//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H

#include "Characters/PlayerCharacter.h"
#include "Characters/Enemy.h"
#include "ProceduralMap.h"
#include "textDisplay.h"

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
    void drawTextDisplayed();
    void drawPlayer();

    void updateProjectiles();
    void updateEnemies();
    void updateObjects();
    void updateTextureDisplayed();

    void checkCollision();
    void collisionWall();
    void collisionProjectiles();
    void collisionPlayerEnemy();
    void checkCollection();


private:
    std::shared_ptr<sf::RenderWindow> window;
    const TextureHolder& textures;
    std::vector<std::shared_ptr<textDisplay>> textureDisplayArray;
    sf::Clock textureTimer;

    std::shared_ptr<PlayerCharacter> player;
    std::shared_ptr<Character> characterArray;
    std::vector<std::shared_ptr<Enemy>> enemyArray;
    std::shared_ptr<RangedWeapon> rangedWeapon;

    std::vector<std::shared_ptr<Projectile>> projectileArray;
    std::vector<std::shared_ptr<Object>> collectableObject;

    std::shared_ptr<ProceduralMap> map;

};


#endif //BLACKROSE_WORLD_H
