//
// Created by Elena Faillace on 25/07/2018.
//

#ifndef BLACKROSE_HEALPACK_H
#define BLACKROSE_HEALPACK_H

#include "ConsumableObject.h"

class Healpack: public ConsumableObject {
public:
    Healpack(const sf::Texture& textures);

private:
    const sf::Texture& textures;
};


#endif //BLACKROSE_HEALPACK_H
