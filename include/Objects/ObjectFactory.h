//
// Created by Elena Faillace on 18/09/2018.
//

#ifndef BLACKROSE_OBJECTFACTORY_H
#define BLACKROSE_OBJECTFACTORY_H

#include "../management/ResourceIdentifier.h"
#include "../management/ResourceHolder.h"
#include "Healpack.h"
#include "RangedWeapon.h"
#include "MeleeWeapon.h"
#include "Shield.h"
#include "../Random.h"

class ObjectFactory: public Object {
public:
    std::shared_ptr<Object> createObject(Object::Type type, const TextureHolder&textures);
    std::shared_ptr<Object> createObject(const TextureHolder&textures);

private:
    Object::Type typeDrop();

};


#endif //BLACKROSE_OBJECTFACTORY_H
