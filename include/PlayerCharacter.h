//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_PLAYERCHARACTER_H
#define BLACKROSE_PLAYERCHARACTER_H

#include <string>
#include "Character.h"
#include "Shield.h"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"


class PlayerCharacter : public Character {
public:
    PlayerCharacter();
    enum Type {
        blueHero,
        blondHero
    };

    PlayerCharacter(Type type, const TextureHolder& textures);
    bool equip();
    //a movement that covers several tiles thanks to the ProtoBelt
    void dash();
    virtual void die();

    const sf::Vector2f &getPosition() const;
    void setPosition(const sf::Vector2f &position);
    void setPosition(float x, float y);
    const sf::Sprite &getSprite() const;
    float getSpeed() const;
    void setSpeed(float speed);

public:
    std::string name;

private:
    const TextureHolder& textures;
    sf::Sprite sprite;
    sf::Texture texture;
    Type type;

    sf::Vector2f position;
    float speed;

    std::shared_ptr<Weapon> rangedWeapon;
    std::shared_ptr<Weapon> meleeWeapon;
    std::shared_ptr<Shield> slotShield;

};


#endif //BLACKROSE_PLAYERCHARACTER_H
