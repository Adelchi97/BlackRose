//
// Created by Elena Faillace on 17/09/2018.
//

#include "../../include/management/SeekStrategy.h"

SeekStrategy::SeekStrategy(sf::Vector2u windowSize) {
    speed = 1.5f;
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
        movements = sf::Vector2f(playerPosition.x/modulo*speed, enemyPos.y/modulo*speed);
    //player is down left
    } else if(playerPosition.x <= enemyPos.x && playerPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(-playerPosition.x/modulo*speed, enemyPos.y/modulo*speed);
    //player is up right
    } else if(playerPosition.x >= enemyPos.x && playerPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(enemyPos.x/modulo*speed, -playerPosition.y/modulo*speed);
    //player is up left
    } else if(playerPosition.x <= enemyPos.x && playerPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(-enemyPos.x/modulo*speed, -playerPosition.y/modulo*speed);
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

