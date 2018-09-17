//
// Created by Elena Faillace on 14/09/2018.
//

#ifndef BLACKROSE_ROBOTFIGHTER_H
#define BLACKROSE_ROBOTFIGHTER_H


#include "Enemy.h"

class RobotFighter: public Enemy {
public:

    explicit RobotFighter(const TextureHolder& textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy);
    void registerObserver(std::shared_ptr<Observer> observer) final;

private:
    const TextureHolder& textures;

};


#endif //BLACKROSE_ROBOTFIGHTER_H
