//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H


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
    void setPosition(const sf::Vector2f &movement);
    void setPosition(float x, float y);
    virtual const sf::Sprite &getSprite();
    void setDirection(Enemy::Direction direction);


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

    int counterWalk;
    int changeDirectionTime, counterDirection = 0;
    bool delayWalk, delayMoreWalk;
    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;

};


#endif //BLACKROSE_ENEMY_H
