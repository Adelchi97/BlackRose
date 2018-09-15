//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Enemy.h"

Enemy::Enemy() {

}


int Enemy::getAttackDamage() {
    if(attackClock.getElapsedTime().asSeconds() > .5) {
        std::cout << "GOT HIT!" << std::endl;
        attackClock.restart();
        return attackDamage;
    }
    else return 0;
}

void Enemy::update() {

    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    //controls the walking animation
    strategy->animation(isMovingUp,isMovingDown,isMovingLeft,isMovingRight,delayMoreWalk,delayMoreWalk,counterWalk);

    strategy->update(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, rect);

    //serve puramente alla texture corretta
    setDirection();

    if(hp<=0) {
        this->die();
    }

    Character::update();

}

void Enemy::setDirection() {
    if(isMovingUp) {
        this->direction = up;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
    } else if(isMovingRight) {
        this->direction = right;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
    } else if(isMovingLeft) {
        this->direction = left;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
    } else if(isMovingDown) {
        this->direction = down;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
    }
}

void Enemy::setPosition(float x, float y) {
    Character::setPosition(x,y);
}

void Enemy::setPosition(sf::Vector2f &movement) {
    Character::setPosition(movement);
    //checkWorldBounds();
}

const sf::Sprite &Enemy::getSprite() {
    return Entity::getSprite();
}

void Enemy::seek() {

}

void Enemy::patrol() {

}

void Enemy::die() {
    active = false;
    notifyObservers();//TODO call the observer (PlayerCharacter) who will update his enemyKills counter, advancing with achievements
}

void Enemy::registerObserver(Observer* o) {
    observers.push_back(o);
}

void Enemy::removeObserver(Observer* o) {
    for(auto iter=observers.begin(); iter!=observers.end(); iter++){
        if(iter.operator*() == o)
            observers.erase(iter);
    }
}

void Enemy::notifyObservers() const {
    for(auto iter=observers.begin(); iter!=observers.end(); iter ++){
        (*iter)->update();
    }
}

void Enemy::changeDirection() {
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



