//
// Created by Elena Faillace on 07/07/2018.
//

#include "../include/PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {

Textures::ID toTextureID(PlayerCharacter::Type type) {
    switch(type) {
        case PlayerCharacter::Type::blueHero:
            return Textures::HeroBlue;
        case PlayerCharacter::Type::blondHero:
            return Textures::HeroBlond;
    }
}
PlayerCharacter::PlayerCharacter(Type type, const TextureHolder& textures): type(type), textures(textures), speed(100) {
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

bool PlayerCharacter::equip() {

    return true;
}

void PlayerCharacter::dash() {

}

void PlayerCharacter::die() {

}}

const sf::Vector2f &PlayerCharacter::getPosition() const {
    return position;
}

void PlayerCharacter::setPosition(const sf::Vector2f &position) {
    PlayerCharacter::position = position;
}

void PlayerCharacter::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

const sf::Sprite &PlayerCharacter::getSprite() const {
    return sprite;
}

float PlayerCharacter::getSpeed() const {
    return speed;
}

void PlayerCharacter::setSpeed(float speed) {
    PlayerCharacter::speed = speed;
}
