//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_ENEMY_H
#define BLACKROSE_ENEMY_H


#include "Character.h"

class Enemy : public Character {
public:
    enum SkillType {
        skill1,
        skill2
    };

    enum Type {
        robotRed,
        robotGray
    };

    explicit Enemy(Type type);

    void seek();
    void patrol();
    void useSkill(SkillType type);
    virtual void die();

private:
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Shield> shield;
    Type type;

};


#endif //BLACKROSE_ENEMY_H
