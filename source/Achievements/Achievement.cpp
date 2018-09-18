//
// Created by Ludovico on 14/09/2018.
//

#include "../../include/Achievements/Achievement.h"

Achievement::Achievement() {
    sf::Font font;
    mFont.loadFromFile("Media/Digitalism.ttf");
    mStatisticsText.setFont(mFont);
    mStatisticsText.setCharacterSize(40);

}

void Achievement::update() {
    counter++;
}