//// Created by Elena Faillace on 08/07/2018.//#include "../include/Projectile.h"Projectile::Projectile(const TextureHolder& textures): textures(textures), active(false), delayWalk(false),delayMoreWalk        (false), delayMoreMoreWalk(false), counterWalk(0) {    //rect.setSize(sf::Vector2f(10,10));    rect.setPosition(0,0);    texture = textures.get(Textures::ShootingEnergy);    //sprite.setPosition(0,0);    sprite.setTexture(texture);    sprite.setTextureRect((sf::IntRect(0,0,56,56)));}void Projectile::setPosition(const sf::Vector2f &position, Direction direction) {    active = true;    this->direction = direction;    rect.move(position);    sprite.setPosition(rect.getPosition());}const sf::Sprite &Projectile::getSprite() {    return Entity::getSprite();}void Projectile::update(sf::Vector2u windowSize) {    switch(direction) {        case up:            rect.move(0,-movementSpeed);            break;        case down:            rect.move(0,movementSpeed);            break;        case left:            rect.move(-movementSpeed,0);            break;        case right:            rect.move(movementSpeed,0);            break;    }    if ( delayWalk ) {        if ( delayMoreWalk ) {            if(delayMoreMoreWalk)                counterWalk = (counterWalk + 1) % 4;            delayMoreMoreWalk = !delayMoreMoreWalk;        }        delayMoreWalk = !delayMoreWalk;    }    delayWalk = !delayWalk;    sprite.setTextureRect((sf::IntRect(counterWalk*58,0,56,56)));    if(windowSize.x<rect.getSize().x || windowSize.y<rect.getSize().y) {         active = false;    }    //keeps rect and sprite together    sprite.setPosition(rect.getPosition());}