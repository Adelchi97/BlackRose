//
// Created by Elena Faillace on 22/06/2018.
//

#ifndef BLACKROSE_GAME_H
#define BLACKROSE_GAME_H

#include "World.h"


class Game : private sf::NonCopyable {
public:
    Game();
    void run();

private:
    void processEvents(sf::Clock& shootingClock);
    void update(sf::Time);
    void render();

    void updateStatistics(sf::Time elapsedTime);

    void loadTextures();
    //void loadSound();

private:
    std::shared_ptr<World> world;
    std::shared_ptr<sf::View> view;

    /*
    sf::SoundBuffer soundBuffer;
    sf::Music music;
    sf::Sound sound;
    */

    TextureHolder textureHolder;
    std::shared_ptr<sf::RenderWindow> mWindow;
    static const sf::Time TimePerFrame;

    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t	mStatisticsNumFrames;


    std::shared_ptr<AchievementFactory> throphies;
};


#endif //BLACKROSE_GAME_H
