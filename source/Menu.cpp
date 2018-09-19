//
// Created by Ludovico on 19/09/2018.
//

#include "../include/Menu.h"

Menu::Menu(std::shared_ptr<sf::RenderWindow> window): window(window) {
}

Menu::~Menu() {

}

void Menu::draw(){
    int counter = 0;
    for(auto iter = choicesVector.begin(); iter != choicesVector.end(); iter++){
        window->draw(choicesVector[counter]);
        counter++;
    }
}

void Menu::moveUp() {
    if(selectedChoice -1 >= 0){
        choicesVector[selectedChoice].setFillColor(sf::Color::White);
        selectedChoice--;
        choicesVector[selectedChoice].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(selectedChoice +1 < choicesVector.size()){
        choicesVector[selectedChoice].setFillColor(sf::Color::White);
        selectedChoice++;
        choicesVector[selectedChoice].setFillColor(sf::Color::Red);
    }
}