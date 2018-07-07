//
// Created by Elena Faillace on 07/07/2018.
//

#include <SFML/Graphics.hpp>
#include "../include/World.h"
#include "../include/ResourceIdentifier.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures) : window(window), textures(textures) {
World::World(std::shared_ptr <sf::RenderWindow> window, const TextureHolder &textures): window(window), textures
        (textures), isMovingUp(false), isMovingDown(false), isMovingLeft(false), isMovingRight(false),
        player(new PlayerCharacter(PlayerCharacter::blondHero,textures)) {
    player->setPosition(window->getSize().x/2.f,window->getSize().y/2.f);

}

void World::update(sf::Time dt) {
    sf::Vector2f movements = player->getPosition();
    if(isMovingUp) {
        movements.y-=player->getSpeed();
    }
    if(isMovingDown) {
        movements.y+=player->getSpeed();
    }
    if(isMovingRight) {
        movements.x+=player->getSpeed();
    }
    if(isMovingLeft) {
        movements.x-=player->getSpeed();
    }
    player->setPosition(movements * dt.asSeconds());
}

void World::draw() {
    window->setView(window->getDefaultView());
    window->draw(player->getSprite());
}

void World::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        isMovingRight = isPressed;
}
