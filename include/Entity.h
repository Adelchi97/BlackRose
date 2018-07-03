//
// Created by Elena Faillace on 25/06/2018.
//

#ifndef BLACKROSE_ENTITY_H
#define BLACKROSE_ENTITY_H


#include <SFML/System.hpp>
#include "SceneNode.h"
#include "ResourceIdentifier.h"

class Entity : public SceneNode {

public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float velX, float velY);
    sf::Vector2f getVelocity() const;

private:
    virtual void updateCurrent(sf::Time dt);

    sf::Vector2f mVelocity;
};


#endif //BLACKROSE_ENTITY_H
