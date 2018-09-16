//
// Created by Elena Faillace on 14/09/2018.
//

#ifndef BLACKROSE_STRATEGY_H
#define BLACKROSE_STRATEGY_H

#include <SFML/Graphics.hpp>

class Strategy {
public:
    enum Type {
        patrol,
        seek
    };

    Strategy();

    virtual void update(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, sf::RectangleShape& rect);
    virtual void animation(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, bool&
        delayWalk, bool& delayMoreWalk, int& counterWalk);

};


#endif //BLACKROSE_STRATEGY_H
