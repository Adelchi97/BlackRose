//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WEAPON_H
#define BLACKROSE_WEAPON_H

#include "Object.h"
#include "../Characters/Character.h"

class Character;
class Weapon : public Object {
public:
    Weapon();
    int range;

protected:
    int power;
};


#endif //BLACKROSE_WEAPON_H
