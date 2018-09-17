//
// Created by Ludovico on 15/09/2018.
//

#include "../../include/Achievements/AchievementFactory.h"

std::vector<std::shared_ptr<Achievement>> AchievementFactory::createAchievement() {
    auto demolisher = std::make_shared<DemolisherAchievement>();
    listAchievements.emplace_back(demolisher);

    auto sniper = std::make_shared<SniperAchievement>();
    listAchievements.emplace_back(sniper);

    return listAchievements;
}
