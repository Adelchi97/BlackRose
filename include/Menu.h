//
// Created by Ludovico on 19/09/2018.
//

#ifndef BLACKROSE_MENU_H
#define BLACKROSE_MENU_H

#include "../include/management/ResourceHolder.h"
#include "SFML/Graphics.hpp"

class Menu {
public:
    Menu(std::shared_ptr<sf::RenderWindow> window);
    ~Menu();

    void draw();
    void moveUp();
    void moveDown();
    int getPressedChoice() {return selectedChoice; };

public:
    float width, height;
    int selectedChoice;
    sf::Font font; // font utilizzato nel menu
    std::vector<sf::Text> choicesVector; //vettore di possibilità di un menu
    std::shared_ptr<sf::RenderWindow> window;
};


#endif //BLACKROSE_MENU_H
