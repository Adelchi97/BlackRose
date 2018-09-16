//
// Created by Elena Faillace on 14/09/2018.
//

#include "../../include/management/PatrolStrategy.h"

PatrolStrategy::PatrolStrategy(sf::Vector2u windowSize) {
    speed = 1;
    this->windowSize = windowSize;
}

void PatrolStrategy::update(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, sf::RectangleShape& rect) {

    if(counterDirection==0) {
        changeDirection(isMovingUp, isMovingDown, isMovingLeft, isMovingRight);
        changeDirectionTime = generateRandom(200);
    }
    counterDirection = (counterDirection+1)%changeDirectionTime;

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
    }
    if(isMovingDown) {
        movements.y+=speed;
    }
    if(isMovingRight) {
        movements.x+=speed;
    }
    if(isMovingLeft) {
        movements.x-=speed;
    }

    rect.move(movements);

}

void PatrolStrategy::changeDirection(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight) {
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

void PatrolStrategy::animation(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, bool&
    delayWalk, bool& delayMoreWalk, int& counterWalk) {

    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
}


