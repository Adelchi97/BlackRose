//

// Created by Elena Faillace on 07/07/2018.
//

#include <SFML/Graphics.hpp>
#include "../include/World.h"
#include "../include/management/ResourceIdentifier.h"
#include "../include/ProceduralMap.h"

World::World(std::shared_ptr <sf::RenderWindow> window, const TextureHolder &textures): window(window), textures
        (textures), player(new PlayerCharacter(PlayerCharacter::blueHero,textures, window->getSize())),
                           rangedWeapon(new RangedWeapon()), wall(new Wall(textures)) {

    player->rect.setPosition(window->getSize().x/2.f,window->getSize().y/2.f);

    createEnemies();
    createWeapon();



    //equipe it
    player->equip(rangedWeapon);

}

void World::createEnemies() {
    for(int i=0; i<generateRandom(5); i++) {
        enemyArray.emplace_back(std::make_shared<Enemy>(textures, window->getSize()));
    }
}

void World::createWeapon() {
    rangedWeapon->addProjectile(50);
}

void World::update(sf::Time dt) {

    player->update(dt);
    updateEnemies();
    updateProjectiles();

    checkCollision();

}

void World::checkCollision() {
    if(!projectileArray.empty() && !enemyArray.empty()) {
        int counterProjectiles = 0;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            int counterEnemy = 0;
            for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
                if ( projectileArray[ counterProjectiles ]->rect.getGlobalBounds().
                        intersects(enemyArray[ counterEnemy ]->rect.getGlobalBounds())) {
                    std::cout << "Collision!" << std::endl;
                    enemyArray[counterEnemy]->hp--;
                    projectileArray[counterProjectiles]->active = false;
                }
                counterEnemy++;
            }
            counterProjectiles++;
        }
    }
}

void World::updateEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            enemyArray[ counter ]->update();

            if ( !enemyArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            enemyArray.erase(enemyArray.begin() + deleted);
    }
}

void World::updateProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            projectileArray[ counter ]->update();

            if ( !projectileArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            projectileArray.erase(projectileArray.begin() + deleted);
    }
}

void World::draw() {
    window->setView(window->getDefaultView());
    window->draw(wall->sprite);
    drawProjectiles();
    drawEnemies();
    window->draw(player->getSprite());
}

void World::drawEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            window->draw(enemyArray[ counter ]->getSprite());
            counter++;
        }
    }
}

void World::handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock) {
    if (key == sf::Keyboard::W)
        player->isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        player->isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        player->isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        player->isMovingRight = isPressed;
    else if (key == sf::Keyboard::Space && isPressed) {
        if(shootingClock.getElapsedTime().asSeconds() >= 0.2) {
            useWeapon();
            shootingClock.restart();
        }
    }
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}

//gets the projectile back in the array of the world and sets the right position
void World::useWeapon() {
    if(player->shoot()) {
        projectileArray.emplace_back(std::make_shared<Projectile>(textures));
        projectileArray.back()->setPosition(player->rect.getPosition(), player->direction);
        projectileArray.back()->range = player->rangedWeapon->range;
    } else
        std::cout<<"non puo sparare "<<std::endl;
}

void World::drawProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            window->draw(projectileArray[ counter ]->getSprite());
            counter++;
        }
    }
}
