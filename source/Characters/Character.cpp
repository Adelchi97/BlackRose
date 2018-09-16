//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Character.h"


Character::Character() {

    //all characters are this big
    rect.setSize(sf::Vector2f(32,32));

    //life bar
    bar = sf::RectangleShape(sf::Vector2f(32,5));
    lifeBar = sf::RectangleShape(sf::Vector2f(32,5));
    bar.setOutlineThickness(3);
    bar.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Black);
    lifeBar.setFillColor(sf::Color::Green);

    /*
    bar.setPosition(position.x, position.y-16);
    lifeBar.setPosition(position.x, position.y-16);
     */

    //TODO istanzia un inventory
}

void Character::move() {

}

void Character::fight() {

}

bool Character::interactWithObject(std::shared_ptr <Object> &object) {
    return true;
}

void Character::die() {

}

void Character::display() {
    barDisplayed = true;
    timerTextures.restart();
}

void Character::update() {
    //life bar
    if(barDisplayed) {
        bar.setPosition(position.x-16,position.y-32);
        lifeBar.setPosition(position.x-16,position.y-32);
        lifeBar.setSize(sf::Vector2f(32*hp/hpMax,5));
        if(lifeBar.getSize().x <= 16)
            lifeBar.setFillColor(sf::Color::Yellow);
        if(lifeBar.getSize().x <= 8)
            lifeBar.setFillColor(sf::Color::Red);
        if(timerTextures.getElapsedTime().asSeconds() > .5) {
            barDisplayed = false;
        }
    }
}

void Character::setPosition(sf::Vector2f& movement) {
    rect.move(movement.x, movement.y);
}

void Character::setPosition(float x, float y) {
    rect.move(x,y);
}

void Character::changeDirection() {

}

int Character::getAttackDamage() {
    return 0;
}

sf::Vector2f Character::getPosition() {
    return position;
}
