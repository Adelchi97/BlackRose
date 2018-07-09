//// Created by Elena Faillace on 08/07/2018.//#ifndef BLACKROSE_PROJECTILE_H#define BLACKROSE_PROJECTILE_H#include "Entity.h"#include "management/ResourceHolder.h"#include "management/ResourceIdentifier.h"class Projectile: public Entity {public:    Projectile(const TextureHolder& textures);    virtual void setPosition(const sf::Vector2f& position);private:    const TextureHolder& textures;    int movementSpeed = 10;    int attackDamage = 5;};#endif //BLACKROSE_PROJECTILE_H