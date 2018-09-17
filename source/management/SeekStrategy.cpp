//
// Created by Elena Faillace on 17/09/2018.
//

#include "../../include/management/SeekStrategy.h"

SeekStrategy::SeekStrategy(sf::Vector2u windowSize) {

}

void SeekStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight,
                          sf::RectangleShape &rect) {
    Strategy::update(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, rect);
}

void
SeekStrategy::animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk,
                        bool &delayMoreWalk, int &counterWalk) {
    Strategy::animation(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, delayWalk, delayMoreWalk, counterWalk);
}

