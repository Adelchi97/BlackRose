//
// Created by Elena Faillace on 25/07/2018.
//

#ifndef BLACKROSE_HEALPACK_H
#define BLACKROSE_HEALPACK_H

#include "ConsumableObject.h"
#include "../management/ResourceHolder.h"
#include "../management/ResourceIdentifier.h"

class Healpack: public ConsumableObject {
public:
    Healpack(const TextureHolder& textures);
    void update() final;

private:
    const TextureHolder& textures;
};


#endif //BLACKROSE_HEALPACK_H
