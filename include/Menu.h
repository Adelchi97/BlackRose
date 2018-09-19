//
// Created by Ludovico on 19/09/2018.
//

#ifndef BLACKROSE_MENU_H
#define BLACKROSE_MENU_H

#include "../include/management/ResourceHolder.h"
#include "SFML/Graphics.hpp"

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(std::shared_ptr<sf::RenderWindow> window);
    void MoveUp();
    void MoveDown();

public:
    int selectedChoice;
    sf::Font font; // font utilizzato nel menu
    std::vector<sf::Text> choicesVector; //vettore di possibilità di un menu
};


#endif //BLACKROSE_MENU_H
