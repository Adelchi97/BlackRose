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
#include "../Objects/RangedWeapon.h"
#include "../Objects/MeleeWeapon.h"

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
        blondHero,
        whiteHero,
        grayHero,
        starLord
    };

    PlayerCharacter(Type type, const TextureHolder& textures);
    bool equip(std::shared_ptr<RangedWeapon>& w);
    bool equip(std::shared_ptr<MeleeWeapon>& w);
    Projectile& shoot();
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
    bool shooting;
    Type type;

private:
    const TextureHolder& textures;
    int counterWalk;
    bool delayWalk, delayMoreWalk;

    std::shared_ptr<RangedWeapon> rangedWeapon;
    std::shared_ptr<Weapon> meleeWeapon;
    std::shared_ptr<Shield> slotShield;

};


#endif //BLACKROSE_PLAYERCHARACTER_H
