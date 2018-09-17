//
// Created by Elena Faillace on 25/07/2018.
//

#include "../../include/Objects/Healpack.h"

Healpack::Healpack(const TextureHolder &textures): textures(textures) {

    texture = textures.get(Textures::healPack);
    sprite.setTexture(texture);

    rect.setPosition(sf::Vector2f(300,300));
    rect.setOrigin(32/2,23/2);
    sprite.setOrigin(32/2,23/2);
    rect.setSize(sf::Vector2f(32,23));
    sprite.setPosition(rect.getPosition());

    collected = false;
}

void Healpack::update() {
    ConsumableObject::update();
}
