//
// Created by Elena Faillace on 27/07/2018.
//

#ifndef BLACKROSE_TEXTUREDISPLAY_H
#define BLACKROSE_TEXTUREDISPLAY_H

#include "Entity.h"

class TextureDisplay: public Entity {
public:
    TextureDisplay(sf::Vector2f position);

    void update();
    void display();

public:
    bool displayed;
    sf::RectangleShape bar;

private:
    sf::Clock timerTextures;

};


#endif //BLACKROSE_TEXTUREDISPLAY_H
