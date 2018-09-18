//// Created by Elena Faillace on 07/07/2018.//#include "../../include/Objects/RangedWeapon.h"Textures::ID toTextureID(RangedWeapon::Type type) {    switch(type) {        case RangedWeapon::Type::energyShooter:            return Textures::energyShooter;    }}RangedWeapon::RangedWeapon(const TextureHolder& textures, RangedWeapon::Type type): textures(textures), typeWeapon(type) {    equipped = false;    this->type = Object::Type::Weapon;    //counterLifeTime = 2000;   use it to have a life time    projectilesCounter = 0;    range = 400;   // power = 10;    texture = textures.get(toTextureID(type));    sprite.setTexture(texture);    rect.setPosition(sf::Vector2f(300,300));    rect.setOrigin(32/2,23/2);    sprite.setOrigin(32/2,23/2);    rect.setSize(sf::Vector2f(32,23));    sprite.setPosition(rect.getPosition());}bool RangedWeapon::addStuff(int added) {    projectilesCounter+=added;    return true;}bool RangedWeapon::use() {    if(projectilesCounter <= 0) {        std::cout<<"non ci sono proiettili da sparare"<<std::endl;        return false;    }    projectilesCounter--;    return true;}void RangedWeapon::update() {    Weapon::update();}