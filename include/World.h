//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H

#include <string>

#include "Characters/PlayerCharacter.h"
#include "Characters/RobotFighter.h"
#include "Characters/RobotShooter.h"
#include "ProceduralMap.h"
#include "textDisplay.h"
#include "Characters/EnemyFactory.h"

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
    void collisionPlayerWall();
    void collisionEnemyWall();
    void collisionProjectiles();
    void collisionPlayerEnemy();
    void checkCollection();

public:
    std::shared_ptr<PlayerCharacter> player;
    std::shared_ptr<sf::RenderWindow> window;
    //std::vector<int> wallArray;

    std::shared_ptr<ProceduralMap> map;
private:

    const TextureHolder& textures;
    std::vector<std::shared_ptr<textDisplay>> textureDisplayArray;
    sf::Clock textureTimer;

    std::vector<std::shared_ptr<Enemy>> enemyArray;
    //std::vector<std::shared_ptr<Strategy>> strategyArray;
    std::shared_ptr<RangedWeapon> rangedWeapon;
    EnemyFactory enemyFactory;

    std::vector<std::shared_ptr<Projectile>> projectileArray;
    std::vector<std::shared_ptr<Object>> collectableObject;


};


#endif //BLACKROSE_WORLD_H
