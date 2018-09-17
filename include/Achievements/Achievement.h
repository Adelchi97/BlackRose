//
// Created by Ludovico on 14/09/2018.
//

#ifndef BLACKROSE_ACHIEVEMENT_H
#define BLACKROSE_ACHIEVEMENT_H

#include <SFML/Graphics.hpp>
#include "../Observer.h"
#include <string>


class Achievement : public Observer {

public:
    Achievement();
    virtual void update() override ;
    //virtual void showProgress();

public:
    int counter = 0;
    sf::Font mFont;
    sf::Text mStatisticsText;

};


#endif //BLACKROSE_ACHIEVEMENT_H
