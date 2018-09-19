//
// Created by Elena Faillace on 17/09/2018.
//

#include "../../include/management/SeekStrategy.h"

SeekStrategy::SeekStrategy(sf::Vector2u windowSize) {
    speed = 10;
    this->windowSize = windowSize;
    type = seek;
}

void SeekStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                          sf::RectangleShape &rect) {

    sf::Vector2f movements(0.f,0.f);
    sf::Vector2f enemyPos(rect.getPosition());
    //player is down right
    double modulo = sqrt(pow(playerPosition.x, 2) + pow(enemyPos.y,2));
    if(playerPosition.x >= enemyPos.x && playerPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(abs((playerPosition.x-enemyPos.x)/modulo*speed), abs((playerPosition.y-enemyPos.y)
        /modulo*speed));
        if(movements.x > movements.y) {
            isMovingRight = true;
            isMovingDown = false;
        } else {
            isMovingRight = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingLeft = false;
    //player is down left
    } else if(playerPosition.x <= enemyPos.x && playerPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(-abs((playerPosition.x-enemyPos.x)/modulo*speed), abs((playerPosition.y-enemyPos.y)
        /modulo*speed));
        if(-movements.x > movements.y) {
            isMovingLeft = true;
            isMovingDown = false;
        } else {
            isMovingLeft = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingRight = false;
    //player is up right
    } else if(playerPosition.x >= enemyPos.x && playerPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(abs((playerPosition.x-enemyPos.x)/modulo*speed), -abs((playerPosition.y-enemyPos.y)
        /modulo*speed));
        if(movements.x > -movements.y) {
            isMovingRight = true;
            isMovingUp = false;
        } else {
            isMovingRight = false;
            isMovingUp = true;
        }
        isMovingLeft = false;
        isMovingDown = false;
    //player is up left
    } else if(playerPosition.x <= enemyPos.x && playerPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(-abs((playerPosition.x-enemyPos.x)/modulo*speed), -abs((playerPosition.y-enemyPos.y)
        /modulo*speed));
        if(-movements.x > -movements.y) {
            isMovingLeft = true;
            isMovingUp = false;
        } else {
            isMovingLeft = false;
            isMovingUp = true;
        }

        isMovingRight = false;
        isMovingDown = false;
    }

    rect.move(movements);
}

void
SeekStrategy::animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk,
                        bool &delayMoreWalk, int &counterWalk) {

    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
}

