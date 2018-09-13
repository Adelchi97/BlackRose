//
// Created by Elena Faillace on 12/09/2018.
//

#ifndef BLACKROSE_CHARACTERFACTORY_H
#define BLACKROSE_CHARACTERFACTORY_H

#include "Character.h"
#include "Enemy.h"

class CharacterFactory {
public:
    //TODO ovviamente enemy type non va bene
    std::shared_ptr<Character> createCharacter(Character::Type type, Enemy::Type subtype, const TextureHolder&
    textures, sf::Vector2u windowSize) {

        std::shared_ptr<Character> character;

        if ( type == Character::enemy ) {
            std::shared_ptr<Enemy> derived = std::dynamic_pointer_cast<Enemy>(character);
        } else if(type == Character::player)

        return character;
    }
};


#endif //BLACKROSE_CHARACTERFACTORY_H
