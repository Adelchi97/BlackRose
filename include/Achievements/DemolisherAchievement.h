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

protected:
    const int target = 5; //after "target" enemies killed the Player gains the achievement
    float progress;
    bool completed = false;

};


#endif //BLACKROSE_DEMOLISHERACHIEVEMENT_H
