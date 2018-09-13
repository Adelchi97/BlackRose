//
// Created by Elena Faillace on 07/07/2018.
//

#include "../../include/Characters/Enemy.h"
/*
Textures::ID toTextureID(Enemy::Type type) {
    switch(type) {
        case Enemy::Type::robotGray:
            return Textures::RobotGray;
        case Enemy::Type::robotRed:
            return Textures::RobotRed;
    }
}
Enemy::Enemy(Type type, const TextureHolder& textures, sf::Vector2u windowSize) : type(type), textures
        (textures),
         isMovingDown(false), isMovingUp(false), isMovingLeft(false), isMovingRight(false), active(true) {
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;
    changeDirectionTime = generateRandom(200);
    speed = 2;
    if(type == robotRed)
        hp = 40;
    else if(type == robotGray)
        hp = 20;
    hpMax = hp;
    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}
Enemy::Enemy(const TextureHolder &textures, sf::Vector2u windowSize): textures(textures), isMovingDown(false),
          isMovingUp(false), isMovingLeft(false), isMovingRight(false), active(true) {
    setRandomType();
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;
    changeDirectionTime = 100;
    speed = 2;
    if(type==robotRed)
        hp = 20, attackDamage = 20;
    else if(type==robotGray)
        hp = 40, attackDamage = 10;
    hpMax = hp;
    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    std::mt19937 mt(rd());
    distribution = std::uniform_real_distribution<>(0.f,800.f);
    position.x = distribution(mt);
    position.y = distribution(mt);
    rect.setPosition(position);
}
int Enemy::getAttackDamage() {
    if(attackClock.getElapsedTime().asSeconds() > .5) {
        std::cout << "GOT HIT!" << std::endl;
        attackClock.restart();
        return attackDamage;
    }
    else return 0;
}
void Enemy::setRandomType() {
    int rand = generateRandom(2);
    if(rand==1)
        type = Type::robotRed;
    if(rand==2)
        type = Type ::robotGray;
}
void Enemy::update() {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();
    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
    //change direction every x frames
    if(counterDirection==0) {
        changeDirection();
        changeDirectionTime = generateRandom(200);
    }
    counterDirection = (counterDirection+1)%changeDirectionTime;
    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
        setDirection(UP);
    }
    if(isMovingDown) {
        movements.y+=speed;
        setDirection(Enemy::DOWN);
    }
    if(isMovingRight) {
        movements.x+=speed;
        setDirection(Enemy::RIGHT);
    }
    if(isMovingLeft) {
        movements.x-=speed;
        setDirection(Enemy::LEFT);
    }
    if(hp<=0)
        active = false;
   Character::update();
    //setPositionMovement(movements  *dt.asSeconds() );
}
void Enemy::changeDirection() {
    isMovingUp = false;
    isMovingRight = false;
    isMovingLeft = false;
    isMovingDown = false;
    int randDirection{0};
    switch(dir){
        // #1
        case Direction::UP:{
           do{
                randDirection = generateRandom(4);
            } while(randDirection == 1);
            break;
        }
        // #2
        case Direction::DOWN:{
            do{
                randDirection = generateRandom(4);
            } while(randDirection == 2);
            break;
        }
        // #3
        case Direction::LEFT:{
            do{
                randDirection = generateRandom(4);
            } while(randDirection == 3);
            break;
        }
        // #4
        case Direction::RIGHT:{
            do{
                randDirection = generateRandom(4);
            } while(randDirection == 4);
            break;
        }
    }
    dir = (Direction)randDirection;
    if (dir == UP) {isMovingUp = true;}
    if (dir == RIGHT) {isMovingRight = true;}
    if (dir == DOWN) {isMovingDown = true;}
    if (dir == LEFT) {isMovingLeft = true;}
}
void Enemy::setPositionMovement(const sf::Vector2f &movement) {
    rect.move(movement);
    if((rect.getPosition().x)+32>windowSize.x) {
        rect.setPosition(windowSize.x - 32, rect.getPosition().y);
        changeDirection();
    }
    else if(rect.getPosition().x<0) {
        rect.setPosition(0, rect.getPosition().y);
        changeDirection();
    }
    if((rect.getPosition().y)+32>windowSize.y) {
        rect.setPosition(rect.getPosition().x, windowSize.y - 32);
        changeDirection();
    }
    else if(rect.getPosition().y<0) {
        rect.setPosition(rect.getPosition().x, 0);
        changeDirection();
    }
}
void Enemy::setPosition(float x, float y) {
    rect.move(x,y);
}
void Enemy::setPosition() {
}
const sf::Sprite &Enemy::getSprite() {
    return Entity::getSprite();
}
void Enemy::setDirection(Enemy::Direction direction) {
    switch(direction) {
        case UP:
            this->direction = up;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
            break;
        case DOWN:
            this->direction = down;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
            break;
        case LEFT:
            this->direction = left;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
            break;
        case RIGHT:
            this->direction = right;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
            break;
    }
}
void Enemy::seek() {
}
void Enemy::patrol() {
}
void Enemy::useSkill(Enemy::SkillType type) {
}
void Enemy::die() {
}
*/

Textures::ID toTextureID(Enemy::SubType type) {
    switch(type) {
        case Enemy::SubType::robotGray:
            return Textures::RobotGray;
        case Enemy::SubType::robotRed:
            return Textures::RobotRed;
    }
}

Enemy::Enemy(SubType subType, const TextureHolder& textures, sf::Vector2u windowSize) : textures
        (textures), isMovingDown(false), isMovingUp(false), isMovingLeft(false), isMovingRight(false), active(true) {

    this->subType = subType;
    typeCharacter = enemy;
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    changeDirectionTime = generateRandom(200);
    speed = 2;
    if(subType == robotRed)
        hp = 40;
    else if(subType == robotGray)
        hp = 20;

    hpMax = hp;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(toTextureID(subType));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

/*
Enemy::Enemy(const TextureHolder &textures, sf::Vector2u windowSize): textures(textures), isMovingDown(false),
                                                                      isMovingUp(false), isMovingLeft(false), isMovingRight(false), active(true) {

    setRandomType();

    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    changeDirectionTime = 100;
    speed = 2;
    if(type==robotRed)
        hp = 20, attackDamage = 20;
    else if(type==robotGray)
        hp = 40, attackDamage = 10;

    hpMax = hp;
    typeCharacter = Character::Type::enemy;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));

    std::mt19937 mt(rd());
    distribution = std::uniform_real_distribution<>(0.f,800.f);
    position.x = distribution(mt);
    position.y = distribution(mt);
    rect.setPosition(position);
}
*/

int Enemy::getAttackDamage() {
    if(attackClock.getElapsedTime().asSeconds() > .5) {
        std::cout << "GOT HIT!" << std::endl;
        attackClock.restart();
        return attackDamage;
    }
    else return 0;
}
void Enemy::setRandomType() {
    int rand = generateRandom(2);
    if(rand==1)
        subType = Enemy::SubType::robotRed;
    if(rand==2)
        subType = Enemy::SubType::robotGray;
}

void Enemy::update() {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }

    //change direction every x frames
    if(counterDirection==0) {
        changeDirection();
        changeDirectionTime = generateRandom(200);
    }
    counterDirection = (counterDirection+1)%changeDirectionTime;

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speed;
        setDirection(Enemy::up);
    }
    if(isMovingDown) {
        movements.y+=speed;
        setDirection(Enemy::down);
    }
    if(isMovingRight) {
        movements.x+=speed;
        setDirection(Enemy::right);
    }
    if(isMovingLeft) {
        movements.x-=speed;
        setDirection(Enemy::left);
    }

    if(hp<=0)
        active = false;

    Character::update();

    setPositionMovement(movements /* *dt.asSeconds()*/);

}

void Enemy::changeDirection() {
    isMovingUp= false;
    isMovingDown= false;
    isMovingLeft= false;
    isMovingRight= false;
    int randDirection = generateRandom(4);
    if(randDirection==1) isMovingUp=true;
    if(randDirection==2) isMovingDown=true;
    if(randDirection==3) isMovingLeft=true;
    if(randDirection==4) isMovingRight=true;
}

void Enemy::setPositionMovement(const sf::Vector2f &movement) {
    rect.move(movement);

    if((rect.getPosition().x)+32>windowSize.x) {
        rect.setPosition(windowSize.x - 32, rect.getPosition().y);
        changeDirection();
    }
    else if(rect.getPosition().x<0) {
        rect.setPosition(0, rect.getPosition().y);
        changeDirection();
    }
    if((rect.getPosition().y)+32>windowSize.y) {
        rect.setPosition(rect.getPosition().x, windowSize.y - 32);
        changeDirection();
    }
    else if(rect.getPosition().y<0) {
        rect.setPosition(rect.getPosition().x, 0);
        changeDirection();
    }

}

void Enemy::setPosition(float x, float y) {
    rect.move(x,y);
}

void Enemy::setPosition(sf::Vector2f &movement) {
    Character::setPosition(movement);
    //checkWorldBounds();
}

const sf::Sprite &Enemy::getSprite() {
    return Entity::getSprite();
}


void Enemy::setDirection(Enemy::Direction direction) {
    switch(direction) {
        case up:
            this->direction = up;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
            break;
        case down:
            this->direction = down;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
            break;
        case left:
            this->direction = left;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
            break;
        case right:
            this->direction = right;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
            break;
    }
}

void Enemy::seek() {

}

void Enemy::patrol() {

}

void Enemy::useSkill(Enemy::SkillType type) {

}

void Enemy::die() {

}