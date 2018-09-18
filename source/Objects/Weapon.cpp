//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Objects/Weapon.h"

Weapon::Weapon() {
}

void Weapon::update() {
    //if(!equipped) Object::update();   //checks the time passed since it spawned
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}

bool Weapon::addStuff(int added) {
    return false;
}

bool Weapon::use() {
    return false;
}
