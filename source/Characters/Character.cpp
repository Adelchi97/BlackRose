//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Character.h"

Character::Character() {
    //all characters are this big
    rect.setSize(sf::Vector2f(32,32));

    //life bar
    bar = sf::RectangleShape(sf::Vector2f(32,5));
    bar.setOutlineThickness(3);
    bar.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Green);
    bar.setPosition(position.x, position.y-16);

    //TODO istanzia un inventory
}

void Character::move() {

}

void Character::fight() {

}

bool Character::interactWithObject(std::shared_ptr<Object> &object) {
    return true;
}

void Character::die() {

}

void Character::display() {
    barDisplayed = true;
    timerTextures.restart();
}

void Character::update() {

}
