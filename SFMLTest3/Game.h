//
// Created by Ludovico on 11/06/2018.
//
#include <SFML/Graphics.hpp>

#ifndef SFMLTEST3_GAME_H
#define SFMLTEST3_GAME_H


class Game {
public:
    Game ();
    void run();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    sf::Texture tx;
    sf::Sprite mSprite;
    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
};


#endif //SFMLTEST3_GAME_H
