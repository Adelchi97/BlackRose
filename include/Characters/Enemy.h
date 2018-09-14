//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H

#include <memory>
#include "Character.h"
#include "../Random.h"

class Enemy : public Character {
public:

    enum SubType {
        robotRed,
        robotGray,
    };

    Enemy();

    virtual void update();
    virtual void setPositionMovement(const sf::Vector2f &movement);
    virtual void setPosition(float x, float y);
    virtual void setPosition(sf::Vector2f &movement);
    virtual const sf::Sprite &getSprite();
    virtual void setDirection(Enemy::Direction direction);
    virtual int getAttackDamage();

    virtual void seek();
    virtual void patrol();
    virtual void changeDirection();
    virtual void die();

public:
    Type type;
    Direction dir;

protected:
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Shield> shield;

    sf::Vector2f windowSize;
    SubType subType;

    sf::Clock attackClock;
    int counterWalk;
    int changeDirectionTime, counterDirection = 0;
    bool delayWalk, delayMoreWalk;


};


#endif //BLACKROSE_ENEMY_H