//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Character.h"

Character::Character() {
    //all characters are this big
    rect.setSize(sf::Vector2f(32,32));

    //TODO istanzia un inventory
}

void Character::move() {

}

void Character::fight() {

}

bool Character::interactWithObject() {
    return true;
}

void Character::die() {

}