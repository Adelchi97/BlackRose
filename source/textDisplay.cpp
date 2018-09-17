//
// Created by Elena Faillace on 28/07/2018.
//

#include "../include/textDisplay.h"

textDisplay::textDisplay() {
    text.setPosition(10,10);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(50);
}

void textDisplay::update() {
    text.setString("life: " + string);
}

void textDisplay::setString(std::string mstring) {
    string = mstring;
}
