//
// Created by Elena Faillace on 12/09/2018.
//

#include "CharacterFactory.h"


std::shared_ptr<Character> CharacterFactory::createCharacter(Character::Type type, Enemy::SubType subtype,
                                                             const TextureHolder &textures, sf::Vector2u windowSize) {
    std::shared_ptr<Character> character;

    if ( type == Character::enemy ) {
        //character = new Enemy(subtype, textures, windowSize);
        character = std::make_shared<Enemy>(subtype, textures, windowSize);

    } else if(type == Character::player) {

    }

    return character;

}
