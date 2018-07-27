//
// Created by Elena Faillace on 27/07/2018.
//

#include "../include/TextureDisplay.h"

TextureDisplay::TextureDisplay(sf::Vector2f position): displayed(true) {

    bar = sf::RectangleShape(sf::Vector2f(32,5));
    bar.setOutlineThickness(3);
    bar.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Green);
    bar.setPosition(position.x, position.y-16);
}

void TextureDisplay::update() {

    if(timerTextures.getElapsedTime().asSeconds() > .5)
        displayed = false;
}

void TextureDisplay::display() {
    displayed = true;
    timerTextures.restart();
}