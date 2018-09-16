//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_PLAYERCHARACTER_H
#define BLACKROSE_PLAYERCHARACTER_H

#include <string>
#include "Character.h"
#include "../Objects/RangedWeapon.h"
#include "../Objects/MeleeWeapon.h"

class Weapon;
class PlayerCharacter : public Character {
public:

    enum SubType {
        blueHero,
        blondHero,
        whiteHero,
        grayHero,
        starLord
    };

    PlayerCharacter(SubType subType, const TextureHolder& textures, sf::Vector2u windowSize);
    bool interactWithObject(std::shared_ptr<Object> &object) override;
    bool useWeapon();
    void changeWeapon(std::shared_ptr<Weapon>& newWeapon);
    //a movement that covers several tiles thanks to the ProtoBelt
    void dash();
    void die() override;
    void update(sf::Time dt);

    void setPosition(sf::Vector2f movement);
    void setPosition(float x, float y) override;
    sf::Vector2f getPosition() override;

    virtual const sf::Sprite &getSprite() override;
    void setDirection(PlayerCharacter::Direction direction);

    float getSpeed() const;
    void setSpeed(int speed);

private:
    void checkWorldBounds();

public:
    std::string name;
    bool shooting;
    std::shared_ptr<Weapon> weapon;

    std::shared_ptr<Weapon> meleeWeapon;
    std::shared_ptr<Shield> slotShield;

    SubType subType;

    bool dead;

private:
    const TextureHolder& textures;
    int counterWalk;
    bool delayWalk, delayMoreWalk;
    sf::Vector2u windowSize;

};


#endif //BLACKROSE_PLAYERCHARACTER_H