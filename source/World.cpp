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
    //remove projectiles from the world and put them into the weapon
    for(int i=0; i<20; i++) {
        projectileArray.push_back(Projectile());
        auto p = projectileArray.back();
        projectileArray.pop_back();
        rangedWeapon->addProjectile(p);
    }
}

void World::update(sf::Time dt) {
    player->update(dt);
}

void World::draw() {
    window->setView(window->getDefaultView());
    window->draw(player->getSprite());
    drawProjectiles();
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
        useProjectile();
}

//gets the projectile back in the array of the world and setes the right position
void World::useProjectile() {
    auto p = player->shoot();
    p.rect.setPosition(player->rect.getPosition());
    projectileArray.push_back(p);
}

void World::drawProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            window->draw(projectileArray[ counter ].rect);
            counter++;
        }
    }
}