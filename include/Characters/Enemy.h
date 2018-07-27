//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H

#include <memory>
#include "Character.h"
#include "../Random.h"
#include "../management/ResourceIdentifier.h"
#include "../management/ResourceHolder.h"

class Enemy : public Character {
public:
    enum SkillType {
        skill1,
        skill2
    };

    enum Type {
        robotRed,
        robotGray
    };

    explicit Enemy(Type type, const TextureHolder& textures, sf::Vector2u windowSize);
    explicit Enemy(const TextureHolder& textures, sf::Vector2u windowSize);

    void update();
    void setPositionMovement(const sf::Vector2f &movement);
    void setPosition(float x, float y);
    void setPosition();
    virtual const sf::Sprite &getSprite();
    void setDirection(Enemy::Direction direction);
    int getAttackDamage();

    void seek();
    void patrol();
    void useSkill(SkillType type);
    virtual void die();

private:
    void changeDirection();
    void setRandomType();

public:
    Type type;
    bool active;

private:
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Shield> shield;

    const TextureHolder& textures;
    sf::Vector2f windowSize;

    sf::Clock attackClock;
    int counterWalk;
    int changeDirectionTime, counterDirection = 0;
    bool delayWalk, delayMoreWalk;
    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;

    std::random_device rd;
    std::uniform_real_distribution<> distribution;

};


#endif //BLACKROSE_ENEMY_H
