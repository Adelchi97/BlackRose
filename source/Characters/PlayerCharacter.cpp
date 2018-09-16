//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/PlayerCharacter.h"


Textures::ID toTextureID(PlayerCharacter::SubType type) {
    switch(type) {
        case PlayerCharacter::SubType::blueHero:
            return Textures::HeroBlue;
        case PlayerCharacter::SubType::blondHero:
            return Textures::HeroBlond;
        case PlayerCharacter::SubType::whiteHero:
            return Textures::HeroWhite;
        case PlayerCharacter::SubType::grayHero:
            return Textures::HeroGray;
        case PlayerCharacter::SubType::starLord:
            return Textures::StarLord;
    }
}

PlayerCharacter::PlayerCharacter(SubType subType, const TextureHolder& textures, sf::Vector2u windowSize):
    textures(textures), counterWalk(0), delayWalk(false), delayMoreWalk(false), shooting(false), dead(false) {

    this->subType = subType;
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;
    isMovingUp = false;
    isMovingRight = false;
    isMovingLeft = false;
    isMovingDown = false;
    active = true;

    rect.setPosition(windowSize.x/2.f,windowSize.y/2.f);
    //rect.setPosition(generateRandom(800), generateRandom(800));
    speedBasic = 2;
    hp = 200;
    hpMax = hp;
    attackDamage = 0;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(toTextureID(subType));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));

}

void PlayerCharacter::update(sf::Time dt) {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speedBasic;
        setDirection(PlayerCharacter::up);
    }
    if(isMovingDown) {
        movements.y+=speedBasic;
        setDirection(PlayerCharacter::down);
    }
    if(isMovingRight) {
        movements.x+=speedBasic;
        setDirection(PlayerCharacter::right);
    }
    if(isMovingLeft) {
        movements.x-=speedBasic;
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

    Character::update();

    //if dead
    if(hp<=0) {
        dead = true;
        std::cout<<"GAME OVER"<<std::endl;
    }
}

bool PlayerCharacter::interactWithObject(std::shared_ptr<Object> &object) {

    rangedWeapon = std::dynamic_pointer_cast<RangedWeapon>(object);
    if(rangedWeapon.get() != nullptr) {
        rangedWeapon->equipped = true;
        if(inventory.addItem(object.get()))
            std::cout<<"Weapon equipped"<<std::endl;
    }
    return true;
}


bool PlayerCharacter::shoot() {
    //TODO it will depend on the weapon equipped
    if(rangedWeapon.get() == nullptr) {
        std::cout<<"you don't have a weapon"<<std::endl;
        return false;
    }
    if(!rangedWeapon->shootProjectile()) {
        std::cout<<"out of projectiles"<<std::endl;
        return false;
    }
    return true;
}

void PlayerCharacter::dash() {

}

void PlayerCharacter::die() {

}

void PlayerCharacter::setPosition(sf::Vector2f movement) {

    Character::setPosition(movement);
    checkWorldBounds();

}

void PlayerCharacter::checkWorldBounds() {
    //check right bound
    if((rect.getPosition().x+16)>windowSize.x)
        rect.setPosition(windowSize.x-16, rect.getPosition().y);
        //check left bound;
    else if(rect.getPosition().x-16<0)
        rect.setPosition(16, rect.getPosition().y);
    //check button bound
    if((rect.getPosition().y)+16>windowSize.y)
        rect.setPosition(rect.getPosition().x, windowSize.y-16);
        //check upper bound
    else if(rect.getPosition().y-16<0)
        rect.setPosition(rect.getPosition().x, 16);
}

void PlayerCharacter::setPosition(float x, float y) {
    Character::setPosition(x,y);
}

sf::Vector2f PlayerCharacter::getPosition() {
    return Character::getPosition();
}

const sf::Sprite &PlayerCharacter::getSprite() {
    return Entity::getSprite();
}

float PlayerCharacter::getSpeed() const {
    return speedBasic;
}

void PlayerCharacter::setSpeed(int speed) {
    this->speedBasic = speed;
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