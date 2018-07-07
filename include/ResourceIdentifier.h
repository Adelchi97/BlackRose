//
// Created by Elena Faillace on 27/06/2018.
//

#ifndef BLACKROSE_RESOURCEIDENTIFIER_H
#define BLACKROSE_RESOURCEIDENTIFIER_H

// Forward declaration of SFML classes
namespace sf {
    class Texture;
}

namespace Textures {
    enum ID {
        Floor,
        RobotGray,
        RobotRed
        RobotRed,
        HeroBlue,
        HeroBlond
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

//It will be called a lot
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif //BLACKROSE_RESOURCEIDENTIFIER_H
