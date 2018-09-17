//
// Created by Ludovico on 15/09/2018.
//

#ifndef BLACKROSE_ACHIEVEMENTFACTORY_H
#define BLACKROSE_ACHIEVEMENTFACTORY_H

#include "../management/ResourceHolder.h"
#include "Achievement.h"
#include "DemolisherAchievement.h"
#include "SniperAchievement.h"

class AchievementFactory {
public:

    std::vector<std::shared_ptr<Achievement>> createAchievement();

public:

    std::vector<std::shared_ptr<Achievement>> listAchievements;

};


#endif //BLACKROSE_ACHIEVEMENTFACTORY_H
