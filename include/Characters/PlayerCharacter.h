//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_PLAYERCHARACTER_H
#define BLACKROSE_PLAYERCHARACTER_H

#include <string>
#include "Character.h"
#include "../Objects/Shield.h"
#include "../management/ResourceHolder.h"
#include "../management/ResourceIdentifier.h"

class Weapon;
class PlayerCharacter : public Character {
public:
    enum Direction {
        up,
        down,
        left,
        right
    };
    enum Type {
        blueHero,
        blondHero
    };

    PlayerCharacter(Type type, const TextureHolder& textures);
    bool equip();
    //a movement that covers several tiles thanks to the ProtoBelt
    void dash();
    virtual void die();
    void update(sf::Time dt);

    void setPosition(const sf::Vector2f &movement);
    void setPosition(float x, float y);

    const sf::Sprite &getSprite() const;
    void setDirection(PlayerCharacter::Direction direction);

    float getSpeed() const;
    void setSpeed(int speed);

public:
    std::string name;
    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;
    Type type;

private:
    const TextureHolder& textures;
    int counter;

    std::shared_ptr<Weapon> rangedWeapon;
    std::shared_ptr<Weapon> meleeWeapon;
    std::shared_ptr<Shield> slotShield;

};


#endif //BLACKROSE_PLAYERCHARACTER_H
