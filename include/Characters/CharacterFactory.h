//
// Created by Elena Faillace on 12/09/2018.
//

#ifndef BLACKROSE_CHARACTERFACTORY_H
#define BLACKROSE_CHARACTERFACTORY_H

#include "Enemy.h"

class CharacterFactory {
public:
    //TODO ovviamente enemy type non va bene
    std::shared_ptr<Character> createCharacter(Character::Type type, Enemy::SubType subtype, const TextureHolder&
    textures, sf::Vector2u windowSize);
};


#endif //BLACKROSE_CHARACTERFACTORY_H
