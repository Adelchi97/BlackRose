//
// Created by Ludovico on 15/09/2018.
//

#include "../../include/Achievements/DemolisherAchievement.h"

DemolisherAchievement::DemolisherAchievement() {
    mStatisticsText.setPosition(5.f,60.f);
    std::string temp = std::to_string(progress) + "%";
    mStatisticsText.setString("Demolisher:" + temp);
    /*
    achievementText = std::make_shared<textDisplay>();
    sf::Font font;
    font.loadFromFile("Media/Digitalism.ttf");
    achievementText->text.setFont(font);

    achievementText->text.setString("Demolisher:" + std::to_string(progress));

    mStatisticsText.setPosition(5.f,60.f);
    std::string b = std::to_string(progress) + "%";
    mStatisticsText.setString("Demolisher:" + b);


    if (timerTextures.getElapsedTime().asSeconds() > .5)
        barDisplayed = false;
*/
}

void DemolisherAchievement::update() {
    if(!completed){
        ++counter;
        progress = (counter/target)*100;
        std::string temp = std::to_string(progress) + "%";
        mStatisticsText.setString("Demolisher:" + temp);
    }

    //achievementText->setString("Demolisher:" + std::to_string(progress));


/*

    //textProgress.setString(std::to_string(progress) + "%");
    //std::string a = mStatisticsText.getString();
    //std::string b = std::to_string(progress) + "%";
    //mStatisticsText.setString(a + std::to_string(progress) + "%");
    //showProgress();
*/
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