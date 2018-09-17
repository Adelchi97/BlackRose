//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H

#include <memory>
#include "Character.h"
#include "../Random.h"
#include "../Subject.h"
#include "../Observer.h"
#include "../management/PatrolStrategy.h"
#include "../Achievements/DemolisherAchievement.h"

class Enemy : public Character, public Subject {
public:

    enum SubType {
        robotRed,
        robotGray,
    };

    Enemy();

    //update qui serve per fare più che altro update della strategy
    void update() override;
    void setDirection();
    void changeDirection() override;
    void setPosition(float x, float y) override;
    void setPosition(sf::Vector2f &movement) override;
    const sf::Sprite &getSprite() override;
    int getAttackDamage() override;

    void die() override;

    void registerObserver(std::shared_ptr<Observer> observer) override;
    void removeObserver(std::shared_ptr<Observer> observer) override;
    void notifyObservers() const override;

public:
    Type type;
    Direction dir;
    bool killedByRangedWeapon = false, killedBySword = false;
    SubType subType;
    std::shared_ptr<Strategy> strategy;

    std::vector<std::shared_ptr<Observer>> observers; //achievements

    bool attackAvailable;
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Shield> shield;

    sf::Vector2f windowSize;

    sf::Clock attackClock;
    int counterWalk;
    bool delayWalk, delayMoreWalk;


};


#endif //BLACKROSE_ENEMY_H