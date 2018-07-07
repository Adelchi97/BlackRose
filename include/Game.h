//
// Created by Elena Faillace on 22/06/2018.
//

#ifndef BLACKROSE_GAME_H
#define BLACKROSE_GAME_H

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "World.h"

class Game : private sf::NonCopyable {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time);
    void render();

    void updateStatistics(sf::Time elapsedTime);

    void loadTextures();

private:
    std::shared_ptr<World> world;

    TextureHolder textureHolder;
    std::shared_ptr<sf::RenderWindow> mWindow;
    static const sf::Time TimePerFrame;

    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t	mStatisticsNumFrames;

};


#endif //BLACKROSE_GAME_H
