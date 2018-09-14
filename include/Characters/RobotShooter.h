//
// Created by Elena Faillace on 14/09/2018.
//

#ifndef BLACKROSE_ROBOT_H
#define BLACKROSE_ROBOT_H


#include "Enemy.h"

class RobotShooter: public Enemy {
public:

    explicit RobotShooter(const TextureHolder& textures, sf::Vector2u windowSize);

private:
    const TextureHolder& textures;

};


#endif //BLACKROSE_ROBOT_H
