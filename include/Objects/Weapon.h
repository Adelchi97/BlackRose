//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_WEAPON_H
#define BLACKROSE_WEAPON_H

#include "Object.h"

class Weapon : public Object {
public:
    Weapon();
    void update() override;
    //TODO si il nome...
    virtual bool addStuff(int added);
    bool use() override;

public:
    int range;
    int power;
};


#endif //BLACKROSE_WEAPON_H
