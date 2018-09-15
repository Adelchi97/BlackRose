//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H

#include <memory>
#include "Character.h"
#include "../Random.h"
#include "Subject.h"
#include "../management/PatrolStrategy.h"

class Enemy : public Character, public Subject {
public:

    enum SubType {
        robotRed,
        robotGray,
    };

    Enemy();

    void update() override;
    void setDirection();
    void changeDirection() override;
    void setPosition(float x, float y) override;
    void setPosition(sf::Vector2f &movement) override;
    const sf::Sprite &getSprite() override;
    int getAttackDamage() override;

    virtual void seek();
    virtual void patrol();
    void die() override;

    void registerObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;

public:
    Type type;
    Direction dir;
    bool killedByRangedWeapon = false, killedBySword = false;
    SubType subType;
    std::shared_ptr<Strategy> strategy;

    std::vector<Observer*> observers; //achievements


    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Shield> shield;

    sf::Vector2f windowSize;

    sf::Clock attackClock;
    int counterWalk;
    bool delayWalk, delayMoreWalk;


};


#endif //BLACKROSE_ENEMY_H