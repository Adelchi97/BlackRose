//
// Created by Ludovico on 15/09/2018.
//

#ifndef BLACKROSE_DEMOLISHERACHIEVEMENT_H
#define BLACKROSE_DEMOLISHERACHIEVEMENT_H

#include "Achievement.h"

class DemolisherAchievement : public Achievement {
public:
    DemolisherAchievement();
    void update() final;
    //void showProgress();

    float progress = 0.f;
    sf::Text textProgress;
protected:
    const float target = 5.f; //after "target" enemies killed the Player gains the achievement

    bool completed = false;

};


#endif //BLACKROSE_DEMOLISHERACHIEVEMENT_H
