//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_CHARACTER_H
#define BLACKROSE_CHARACTER_H


#include <SFML/System.hpp>
#include "../Inventory.h"
#include "../Objects/Weapon.h"
#include "../Objects/Shield.h"
#include "../management/ResourceHolder.h"
#include "../management/ResourceIdentifier.h"

class Character: public Entity {
public:
    enum Type {
        player,
        enemy
    };
    /*
    enum SubType {
        robotRed,
        robotGray,
        blueHero,
        blondHero,
        whiteHero,
        grayHero,
        starLord
    };
    */
    Character();
    //virtual ~Character() = 0;
    virtual void move();
    virtual void setPosition(sf::Vector2f movement);
    virtual void fight();
    //basic interaction with the world, it will be associated with a key
    virtual bool interactWithObject(std::shared_ptr <Object> &object);
    virtual void die();
    void update();
    void display();


public:
    int hp;
    int hpMax;
    int attackDamage;
    Type typeCharacter;

    bool barDisplayed = false;
    sf::RectangleShape bar;
    sf::RectangleShape lifeBar;

    //TODO fare private
    sf::Vector2f windowSize;

protected:
    int resistance;
    int speed;
    sf::Vector2f position;
    Inventory inventory;
    sf::Clock timerTextures;
};


#endif //BLACKROSE_CHARACTER_H
