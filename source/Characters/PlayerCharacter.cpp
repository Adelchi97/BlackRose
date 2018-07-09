//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/PlayerCharacter.h"

Textures::ID toTextureID(PlayerCharacter::Type type) {
    switch(type) {
        case PlayerCharacter::Type::blueHero:
            return Textures::HeroBlue;
        case PlayerCharacter::Type::blondHero:
            return Textures::HeroBlond;
        case PlayerCharacter::Type::whiteHero:
            return Textures::HeroWhite;
        case PlayerCharacter::Type::grayHero:
            return Textures::HeroGray;
        case PlayerCharacter::Type::starLord:
            return Textures::StarLord;
    }
}

PlayerCharacter::PlayerCharacter(Type type, const TextureHolder& textures): type(type), textures(textures), counterWalk(0),
    isMovingUp(false), isMovingDown(false), isMovingLeft(false), isMovingRight(false), delayWalk(false),
    delayMoreWalk(false), shooting(false) {

    speed = 2;
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

void PlayerCharacter::update(sf::Time dt) {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
        setDirection(PlayerCharacter::up);
    }
    if(isMovingDown) {
        movements.y+=speed;
        setDirection(PlayerCharacter::down);
    }
    if(isMovingRight) {
        movements.x+=speed;
        setDirection(PlayerCharacter::right);
    }
    if(isMovingLeft) {
        movements.x-=speed;
        setDirection(PlayerCharacter::left);
    }

    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }

    setPosition(movements /* *dt.asSeconds()*/);
}

bool PlayerCharacter::equip(std::shared_ptr<RangedWeapon>& weapon) {
    rangedWeapon = weapon;
    return true;
}
bool PlayerCharacter::equip(std::shared_ptr<MeleeWeapon>& weapon) {

    return true;
}

std::shared_ptr<Projectile> PlayerCharacter::shoot() {
    //TODO it will dipend on the weapon equipped
    return rangedWeapon->shootProjectile();

}

void PlayerCharacter::dash() {

}

void PlayerCharacter::die() {

}

void PlayerCharacter::setPosition(const sf::Vector2f &movement) {
    rect.move(movement);
}

void PlayerCharacter::setPosition(float x, float y) {
    rect.move(x,y);
}

const sf::Sprite &PlayerCharacter::getSprite() {
    return Entity::getSprite();
}

float PlayerCharacter::getSpeed() const {
    return speed;
}

void PlayerCharacter::setSpeed(int speed) {
    this->speed = speed;
}

void PlayerCharacter::setDirection(PlayerCharacter::Direction direction) {
    switch(direction) {
        case up:
            this->direction = up;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
            break;
        case down:
            this->direction = down;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
            break;
        case left:
            this->direction = left;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
            break;
        case right:
            this->direction = right;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
            break;
    }
}
