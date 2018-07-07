//
// Created by Elena Faillace on 07/07/2018.
//

#include <SFML/Graphics.hpp>
#include "../include/World.h"
#include "../include/management/ResourceIdentifier.h"

World::World(std::shared_ptr <sf::RenderWindow> window, const TextureHolder &textures): window(window), textures
        (textures), player(new PlayerCharacter(PlayerCharacter::blueHero,textures)) {

    player->rect.setPosition(window->getSize().x/2.f,window->getSize().y/2.f);

}

void World::update(sf::Time dt) {
    player->update(dt);
}

void World::draw() {
    window->setView(window->getDefaultView());
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
}
