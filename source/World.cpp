//

// Created by Elena Faillace on 07/07/2018.
//

#include "../include/World.h"


World::World(std::shared_ptr <sf::RenderWindow> window, const TextureHolder &textures): window(window), textures
        (textures), player(new PlayerCharacter(PlayerCharacter::blondHero,textures, window->getSize())),
                           rangedWeapon(new RangedWeapon(textures,RangedWeapon::Type::energyShooter)), map(new ProceduralMap
                                                                                                      (textures,
                                                                                   Tile::BackGroundType::baseFloor)) {

    createEnemies();

    createWeapons();
    /*
    int z;
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            z = j+i*25;
            if(map->tileMap[z]->backGround == Tile::metalWall)
            wallArray.emplace_back(z);
        }
    }
    */
}


void World::createEnemies() {
    for(int i=0; i<5; i++) {
        std::shared_ptr<Character> enemy = characterFactory.createCharacter(Character::enemy, Enemy::Type::robotGray, textures,
                sf::Vector2u(800,800));
        characterArray.emplace_back(enemy);
        //enemyArray.emplace_back(std::make_shared<Enemy>(textures, window->getSize()));
        enemyArray[i]->setPosition(generateRandom(800), generateRandom(800));
    }
}

void World::createWeapons() {
    //TODO the weapon lasts 25 seconds on the ground. make it permanent
    rangedWeapon->addProjectile(50);
    int a,b;
    do{
        a = generateRandom(800);
        b = generateRandom(800);
        rangedWeapon->setPosition(sf::Vector2f(a, b));
    }
    while (map->tileMap[b/32+(a/32)*25]->backGround != Tile::labFloor);

    //rangedWeapon->setPosition(sf::Vector2f(generateRandom(800),generateRandom(800)));
    rangedWeapon->update();
    collectableObject.emplace_back(rangedWeapon);
}

void World::update(sf::Time dt) {

    player->update(dt);
    updateEnemies();
    updateProjectiles();
    updateObjects();
    checkCollision();
    updateTextureDisplayed();

}

void World::updateTextureDisplayed() {
    int counter = 0;
    for ( auto iter = textureDisplayArray.begin(); iter != textureDisplayArray.end(); iter++ ) {
        textureDisplayArray[ counter ]->update();
        counter++;
    }
}

void World::updateObjects() {
    if(!collectableObject.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            collectableObject[ counter ]->update();

            if ( collectableObject[ counter ]->counterLifeTime < 0 ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            collectableObject.erase(collectableObject.begin() + deleted);
    }
}

void World::checkCollision() {

    //Projectiles and Enemiesx
    collisionProjectiles();
    collisionPlayerEnemy();
    //Wall
    collisionPlayerWall();
    collisionEnemyWall();
}

void World::collisionPlayerWall() {
    //character collision with walls
    int xPosChar = player->rect.getPosition().x;
    int yPosChar = player->rect.getPosition().y;
    int aCell = xPosChar/32;
    int bCell = yPosChar/32;
    //wall on right
    if(map->tileMap[bCell+((xPosChar+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && player->isMovingRight)
        player->rect.setPosition(xPosChar-2,yPosChar);
    //wall on left
    else if(map->tileMap[bCell+((xPosChar-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && player->isMovingLeft)
        player->rect.setPosition(xPosChar+2,yPosChar);

    //wall on bot
    if(map->tileMap[(yPosChar+16)/32+aCell*25]->backGround == Tile::BackGroundType::metalWall && player->isMovingDown)
        player->rect.setPosition(xPosChar,yPosChar-2);
    //wall on top
    else if(map->tileMap[(yPosChar-16)/32+aCell*25]->backGround == Tile::BackGroundType::metalWall && player->isMovingUp)
        player->rect.setPosition(xPosChar,yPosChar+2);
    //DIAGONAL collisions
    //right top
    if(map->tileMap[(yPosChar-16)/32+((xPosChar+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (player->isMovingUp && player->isMovingRight))
        player->rect.setPosition(xPosChar-2,yPosChar+2);
    //left top
    if(map->tileMap[(yPosChar-16)/32+((xPosChar-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (player->isMovingUp && player->isMovingLeft))
        player->rect.setPosition(xPosChar+2,yPosChar+2);
    //right bot
    if(map->tileMap[(yPosChar+16)/32+((xPosChar+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (player->isMovingDown && player->isMovingRight))
        player->rect.setPosition(xPosChar-2,yPosChar-2);
    //left bot
    if(map->tileMap[(yPosChar+16)/32+((xPosChar-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (player->isMovingDown && player->isMovingLeft))
        player->rect.setPosition(xPosChar+2,yPosChar-2);

}

/*
void World::collisionEnemyWall() {
    int xPosEnemy, yPosEnemy;
    int numEnemy = enemyArray.size();

    for (int i=0; i<numEnemy; i++) {
        xPosEnemy = enemyArray[i]->rect.getPosition().x;
        yPosEnemy = enemyArray[i]->rect.getPosition().y;
        for(int j=0; j<wallArray.size(); j++){
            if(enemyArray[i]->isMovingUp || enemyArray[i]->isMovingRight || enemyArray[i]->isMovingDown || enemyArray[i]->isMovingLeft){
                if( enemyArray[i]->rect.getGlobalBounds().intersects(map->tileMap[j]->rect.getGlobalBounds())){
                    enemyArray[i]->changeDirection();
                }
            }
        }
    }
}

*/

void World::collisionEnemyWall() {
    int xPosEnemy, yPosEnemy;
    int numEnemy = enemyArray.size();

    for (int i=0; i<numEnemy; i++){
        xPosEnemy = (enemyArray[i]->rect.getPosition().x);
        yPosEnemy = (enemyArray[i]->rect.getPosition().y);

        //wall on right
        if(map->tileMap[yPosEnemy/32+((xPosEnemy+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && enemyArray[i]->isMovingRight) {
            //enemyArray[i]->rect.setPosition(xPosEnemy - 2, yPosEnemy);
            enemyArray[i]->changeDirection();
        }
        //wall on left
        else if(map->tileMap[yPosEnemy/32+((xPosEnemy-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && enemyArray[i]->isMovingLeft){
            //enemyArray[i]->rect.setPosition(xPosEnemy+2,yPosEnemy);
            enemyArray[i]->changeDirection();
        }

        //wall on bottom
        if(map->tileMap[((yPosEnemy+16)/32)+(xPosEnemy/32)*25]->backGround == Tile::BackGroundType::metalWall && enemyArray[i]->isMovingDown){
            //enemyArray[i]->rect.setPosition(xPosEnemy,yPosEnemy-2);
            enemyArray[i]->changeDirection();
        }
            //wall on top
        else if(map->tileMap[(yPosEnemy-16)/32+(xPosEnemy/32)*25]->backGround == Tile::BackGroundType::metalWall && enemyArray[i]->isMovingUp){
            //enemyArray[i]->rect.setPosition(xPosEnemy,yPosEnemy+2);
            enemyArray[i]->changeDirection();
        }
        //DIAGONAL collisions
        //right top
        if(map->tileMap[(yPosEnemy-16)/32+((xPosEnemy+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (enemyArray[i]->isMovingUp && enemyArray[i]->isMovingRight)){
            //enemyArray[i]->rect.setPosition(xPosEnemy-2,yPosEnemy+2);
            enemyArray[i]->changeDirection();
        }
        //left top
        if(map->tileMap[(yPosEnemy-16)/32+((xPosEnemy-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (enemyArray[i]->isMovingUp && enemyArray[i]->isMovingLeft)){
            //enemyArray[i]->rect.setPosition(xPosEnemy+2,yPosEnemy+2);
            enemyArray[i]->changeDirection();
        }
        //right bot
        if(map->tileMap[(yPosEnemy+16)/32+((xPosEnemy+16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (enemyArray[i]->isMovingDown && enemyArray[i]->isMovingRight)){
            //enemyArray[i]->rect.setPosition(xPosEnemy-2,yPosEnemy-2);
            enemyArray[i]->changeDirection();
        }
        //left bot (yPosChar+16)/32+((xPosChar+16)/32)*25
        if(map->tileMap[(yPosEnemy+16)/32+((xPosEnemy-16)/32)*25]->backGround == Tile::BackGroundType::metalWall && (enemyArray[i]->isMovingDown && enemyArray[i]->isMovingLeft)){
            //enemyArray[i]->rect.setPosition(xPosEnemy+2,yPosEnemy-2);
            enemyArray[i]->changeDirection();
        }
    }
}

void World::collisionPlayerEnemy() {
    //Enemies and Player
    int counterEnemy = 0;
    for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
        if ( player->rect.getGlobalBounds().intersects(enemyArray[counterEnemy]->rect.getGlobalBounds())) {
            player->display();
            player->hp -= enemyArray[counterEnemy]->getAttackDamage();
        }
        counterEnemy++;
    }
}

void World::collisionProjectiles() {
    if(!projectileArray.empty() && !enemyArray.empty()) {
        int counterProjectiles = 0;
        //go through all projectiles
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            int counterEnemy = 0;
            //go through all enemies
            for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
                if ( projectileArray[ counterProjectiles ]->rect.getGlobalBounds().
                        intersects(enemyArray[ counterEnemy ]->rect.getGlobalBounds())) {
                    std::cout << "Collision!" << std::endl;
                    enemyArray[counterEnemy]->display();
                    enemyArray[counterEnemy]->hp -= projectileArray[counterProjectiles]->attackDamage;
                    projectileArray[counterProjectiles]->active = false;
                }
                counterEnemy++;
            }
            counterProjectiles++;
        }
    }
}

void World::updateEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            enemyArray[ counter ]->update();

            if ( !enemyArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            enemyArray.erase(enemyArray.begin() + deleted);
    }
}

void World::updateProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            projectileArray[ counter ]->update();

            if ( !projectileArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            projectileArray.erase(projectileArray.begin() + deleted);
    }
}

void World::draw() {
    window->setView(window->getDefaultView());
    drawMap();

    drawProjectiles();
    drawObjects();
    drawEnemies();
    drawPlayer();

    drawTextDisplayed();
}

void World::drawPlayer() {
    if(!player->dead) {
        window->draw(player->getSprite());
        if(player->barDisplayed) {
            window->draw(player->bar);
            window->draw(player->lifeBar);
        }
    }
}

void World::drawTextDisplayed() {
    if(!textureDisplayArray.empty()) {
        int counter = 0;
        for ( auto iter = textureDisplayArray.begin(); iter != textureDisplayArray.end(); iter++ ) {
                window->draw(textureDisplayArray[ counter ]->text);
            counter++;
        }
    }
}

void World::drawObjects() {
    if(!collectableObject.empty()) {
        int counter = 0;
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if(!collectableObject[counter]->equipped)
                window->draw(collectableObject[ counter ]->getSprite());
            counter++;
        }
    }
}

void World::drawMap() {
    for(int i=0; i<25*25; i++) {
        window->draw(map->tileMap[i]->sprite);
    }
}

void World::drawEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            window->draw(enemyArray[counter]->getSprite());
            if(enemyArray[counter]->barDisplayed) {
                window->draw(enemyArray[counter]->bar);
                window->draw(enemyArray[counter]->lifeBar);
            }
            counter++;
        }
    }
}

void World::handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock) {
    if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
        player->isMovingUp = isPressed;
    else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
        player->isMovingDown = isPressed;
    else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
        player->isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
        player->isMovingRight = isPressed;
    else if (key == sf::Keyboard::Q)
        checkCollection();
    else if (key == sf::Keyboard::Space && isPressed) {
        if(shootingClock.getElapsedTime().asSeconds() >= 0.2) {
            useWeapon();
            shootingClock.restart();
        }
    }
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}

void World::checkCollection() {
    if(!collectableObject.empty()) {
        int counterObject = 0;
        //go through all objects
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if ( collectableObject[ counterObject ]->rect.getGlobalBounds().
                    intersects(player->rect.getGlobalBounds())) {
                std::cout << "collecting object" << std::endl;
                player->interactWithObject(collectableObject[ counterObject ]);
            }
            counterObject++;
        }
    }
}

//gets the projectile back in the array of the world and sets the right position
void World::useWeapon() {
    if(player->shoot()) {
        projectileArray.emplace_back(std::make_shared<Projectile>(textures));
        projectileArray.back()->setPosition(player->rect.getPosition(), player->direction);
        projectileArray.back()->range = player->rangedWeapon->range;
    } else
        std::cout<<"non puo sparare "<<std::endl;
}

void World::drawProjectiles() {
    if(!projectileArray.empty()) {
        int counter = 0;
        for ( auto iter = projectileArray.begin(); iter != projectileArray.end(); iter++ ) {
            window->draw(projectileArray[ counter ]->getSprite());
            counter++;
        }
    }
}
