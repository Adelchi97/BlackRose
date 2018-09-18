//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WORLD_H
#define BLACKROSE_WORLD_H

#include <string>
#include <SFML/Audio.hpp>

#include "Characters/PlayerCharacter.h"
#include "Characters/RobotFighter.h"
#include "Characters/RobotShooter.h"
#include "ProceduralMap.h"
#include "textDisplay.h"
#include "Characters/EnemyFactory.h"
#include "Achievements/AchievementFactory.h"
#include "Objects/Healpack.h"
#include "Objects/ObjectFactory.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock);

//private:
    void createObjects();
    void dropObject(int index);
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
    void collisionWithMap();
    void collisionPlayerProjectilesOnObjects();
    void collisionEnemyProjectilesOnObjects();
    void collisionPlayerEnemy();
    void checkCollection();

public:
    std::shared_ptr<PlayerCharacter> player;
    std::shared_ptr<sf::RenderWindow> window;
    //std::vector<int> wallArray;

    std::shared_ptr<ProceduralMap> map;

    std::shared_ptr<DemolisherAchievement> dem;

private:

    const TextureHolder& textures;
    //this holds all the texts
    std::vector<std::shared_ptr<textDisplay>> textureDisplayArray;
    std::shared_ptr<textDisplay> playerLife;
    std::shared_ptr<textDisplay> demolisherAchievement;
    sf::Font mainFont;
    sf::Clock textureTimer;

    std::vector<std::shared_ptr<Enemy>> enemyArray;
    EnemyFactory enemyFactory;
    ObjectFactory objectFactory;

    std::vector<std::shared_ptr<Projectile>> projectilePlayerArray;
    std::vector<std::shared_ptr<Projectile>> projectileEnemyArray;
    std::vector<std::shared_ptr<Object>> collectableObject;

    std::shared_ptr<Healpack> healpack;

};


#endif //BLACKROSE_WORLD_H
