//
// Created by Elena Faillace on 07/07/2018.
//

#include "../include/PlayerCharacter.h"

Textures::ID toTextureID(PlayerCharacter::Type type) {
    switch(type) {
        case PlayerCharacter::Type::blueHero:
            return Textures::HeroBlue;
        case PlayerCharacter::Type::blondHero:
            return Textures::HeroBlond;
    }
}
PlayerCharacter::PlayerCharacter(Type type, const TextureHolder& textures): type(type), textures(textures), speed
        (500.f), counter(0) {
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

}

void PlayerCharacter::setPosition(const sf::Vector2f &movement) {
    sprite.move(movement);
}

void PlayerCharacter::setPosition(float x, float y) {
    sprite.move(x,y);
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

void PlayerCharacter::setDirection(PlayerCharacter::Direction direction) {
    switch(direction) {
        case up:
            sprite.setTextureRect(sf::IntRect(counter*32,32*3,32,32));
            counter = (counter+1)%2;
            break;
        case down:
            sprite.setTextureRect(sf::IntRect(counter*32,0,32,32));
            counter = (counter+1)%2;
            break;
        case left:
            sprite.setTextureRect(sf::IntRect(counter*32,32,32,32));
            counter = (counter+1)%2;
            break;
        case right:
            sprite.setTextureRect(sf::IntRect(counter*32,32*2,32,32));
            counter = (counter+1)%2;
            break;
    }
}
