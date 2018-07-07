//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_PLAYERCHARACTER_H
#define BLACKROSE_PLAYERCHARACTER_H

#include <string>
#include "Character.h"
#include "Shield.h"

class PlayerCharacter : public Character {
public:
    PlayerCharacter();
    bool equip();
    //a movement that covers several tiles thanks to the ProtoBelt
    void dash();
    virtual void die();

public:
    std::string name;

private:
    std::shared_ptr<Weapon> rangedWeapon;
    std::shared_ptr<Weapon> meleeWeapon;
    std::shared_ptr<Shield> slotShield;

};


#endif //BLACKROSE_PLAYERCHARACTER_H
