//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Enemy.h"

Textures::ID toTextureID(Enemy::Type type) {
    switch(type) {
        case Enemy::Type::robotGray:
            return Textures::RobotGray;
        case Enemy::Type::robotRed:
            return Textures::RobotRed;
    }
}

Enemy::Enemy(Type type, const TextureHolder& textures) : type(type), textures(textures), isMovingDown(false),
                                                         isMovingUp(false), isMovingLeft(false), isMovingRight(false) {
    changeDirectionTime = 100;
    speed = 1;
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

void Enemy::update(sf::Time dt) {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());

    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }

    if(counterDirection==0) {
        isMovingUp= false;
        isMovingDown= false;
        isMovingLeft= false;
        isMovingRight= false;
        int randDirection = generateRandom(4);
        if(randDirection==1) isMovingUp=true;
        if(randDirection==2) isMovingDown=true;
        if(randDirection==3) isMovingLeft=true;
        if(randDirection==4) isMovingRight=true;
    }
    counterDirection = (counterDirection+1)%changeDirectionTime;

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
        setDirection(Enemy::up);
    }
    if(isMovingDown) {
        movements.y+=speed;
        setDirection(Enemy::down);
    }
    if(isMovingRight) {
        movements.x+=speed;
        setDirection(Enemy::right);
    }
    if(isMovingLeft) {
        movements.x-=speed;
        setDirection(Enemy::left);
    }

    setPosition(movements /* *dt.asSeconds()*/);

}

void Enemy::setPosition(const sf::Vector2f &movement) {
    rect.move(movement);
}
void Enemy::setPosition(float x, float y) {
    rect.move(x,y);
}

const sf::Sprite &Enemy::getSprite() {
    return Entity::getSprite();
}


void Enemy::setDirection(Enemy::Direction direction) {
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

void Enemy::seek() {

}

void Enemy::patrol() {

}

void Enemy::useSkill(Enemy::SkillType type) {

}

void Enemy::die() {

}

