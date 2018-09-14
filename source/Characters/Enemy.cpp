//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Enemy.h"

Enemy::Enemy() {
    //boh

}


int Enemy::getAttackDamage() {
    if(attackClock.getElapsedTime().asSeconds() > .5) {
        std::cout << "GOT HIT!" << std::endl;
        attackClock.restart();
        return attackDamage;
    }
    else return 0;
}
/*
void Enemy::setRandomType() {
    int rand = generateRandom(2);
    if(rand==1)
        subType = Enemy::SubType::robotRed;
    if(rand==2)
        subType = Enemy::SubType::robotGray;
}
*/
void Enemy::update() {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }

    //change direction every x frames
    if(counterDirection==0) {
        changeDirection();
        changeDirectionTime = generateRandom(200);
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

    if(hp<=0)
        active = false;

    Character::update();

    setPositionMovement(movements /* *dt.asSeconds()*/);

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

void Enemy::setPositionMovement(const sf::Vector2f &movement) {
    rect.move(movement);

    if((rect.getPosition().x)+32>windowSize.x) {
        rect.setPosition(windowSize.x - 32, rect.getPosition().y);
        changeDirection();
    }
    else if(rect.getPosition().x<0) {
        rect.setPosition(0, rect.getPosition().y);
        changeDirection();
    }
    if((rect.getPosition().y)+32>windowSize.y) {
        rect.setPosition(rect.getPosition().x, windowSize.y - 32);
        changeDirection();
    }
    else if(rect.getPosition().y<0) {
        rect.setPosition(rect.getPosition().x, 0);
        changeDirection();
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

void Enemy::die() {

}



