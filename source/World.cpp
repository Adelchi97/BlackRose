//
// Created by Elena Faillace on 07/07/2018.
//

#include <SFML/Graphics.hpp>
#include "../include/World.h"
#include "../include/management/ResourceIdentifier.h"

World::World(std::shared_ptr <sf::RenderWindow> window, const TextureHolder &textures): window(window), textures
        (textures), player(new PlayerCharacter(PlayerCharacter::blueHero,textures)), rangedWeapon(new RangedWeapon()) {

    player->rect.setPosition(window->getSize().x/2.f,window->getSize().y/2.f);

    createWeapon();
    //equipe it
    player->equip(rangedWeapon);

}

void World::createWeapon() {
    rangedWeapon->addProjectile(20);
}

void World::update(sf::Time dt) {
    player->update(dt);
    updateProjectiles();
}

void World::updateProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            projectileArray[ counter ]->update(window->getSize());
            if ( !projectileArray[ counter ]->active ) {
                projectileArray.erase(projectileArray.begin() + counter);
            }
            counter++;
        }
    }
}

void World::draw() {
    window->setView(window->getDefaultView());
    drawProjectiles();
    window->draw(player->getSprite());
}

void World::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        player->isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        player->isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        player->isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        player->isMovingRight = isPressed;
    else if (key == sf::Keyboard::Space && isPressed)
        useWeapon();
}

//gets the projectile back in the array of the world and sets the right position
void World::useWeapon() {
    if(player->shoot()) {
        projectileArray.emplace_back(std::make_shared<Projectile>(textures));
        projectileArray.back()->setPosition(player->rect.getPosition(), player->direction);
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