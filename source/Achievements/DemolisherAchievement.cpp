//
// Created by Ludovico on 15/09/2018.
//

#include "../../include/Achievements/DemolisherAchievement.h"

DemolisherAchievement::DemolisherAchievement() {
    mStatisticsText.setPosition(5.f,60.f);
    mStatisticsText.setString("Demolisher: 0%");

/*
    if (timerTextures.getElapsedTime().asSeconds() > .5)
        barDisplayed = false;
*/
}

void DemolisherAchievement::update() {
    if(!completed)
        counter++;
    progress = counter/target;
    std::string a = mStatisticsText.getString();
    std::string b = std::to_string(progress) + "%";
    mStatisticsText.setString(a + b);
    //showProgress();
    if (counter == target)
        completed = true;
}
/*
void DemolisherAchievement::showProgress() {
    std::string a = mStatisticsText.getString();
    std::string b = std::to_string(progress) + "%";
    mStatisticsText.setString(a + b);
}
*/