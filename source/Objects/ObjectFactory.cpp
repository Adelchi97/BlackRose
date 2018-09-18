//
// Created by Elena Faillace on 18/09/2018.
//

#include "../../include/Objects/ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::Type type, const TextureHolder &textures) {

    std::shared_ptr<Object> object;

    if ( type == Object::Type::rangedWeapon ) {

        object = std::make_shared<RangedWeapon>(textures, RangedWeapon::Type::energyShooter);

    } else if(type== Object::Type::meleeWeapon ) {

        object = std::make_shared<MeleeWeapon>(textures);

    } else if(type== Object::Type::healPack ) {

        object = std::make_shared<Healpack>(textures);

    } else if( type == Object::Type::Shield ) {

    }

    return object;

}

std::shared_ptr<Object> ObjectFactory::createObject(const TextureHolder &textures) {


    std::shared_ptr<Object> object;
    Object::Type type = typeDrop();

    if ( type == Object::Type::rangedWeapon ) {

        object = std::make_shared<RangedWeapon>(textures, RangedWeapon::Type::energyShooter);

    } else if(type== Object::Type::meleeWeapon ) {

        object = std::make_shared<MeleeWeapon>(textures);

    } else if(type== Object::Type::healPack ) {

        object = std::make_shared<Healpack>(textures);

    } else if( type == Object::Type::Shield ) {

    }

    return object;
}

Object::Type ObjectFactory::typeDrop() {

    int random = generateRandom(100);
    Object::Type typeSelected;

    if(random < 15)
        typeSelected = healPack;
    else if(random < 65)
        typeSelected = rangedWeapon;


    return typeSelected;
}
