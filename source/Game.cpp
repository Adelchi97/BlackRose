//
// Created by Elena Faillace on 22/06/2018.
//

#include "../include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1600, 1600), "BlackRose", sf::Style::Default)), mFont(),
               mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0), world(nullptr) {
    loadTextures();
    world = std::make_shared<World>(mWindow,textureHolder);

    //sets the icon
    sf::Image icon;

    if(!icon.loadFromFile("Media/Icon.png"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //set the font and text on screen
    //TODO is it necessary?
    sf::Font font;
    mFont.loadFromFile("Media/Digitalism.ttf");
    mStatisticsText.setFont(mFont);

    mStatisticsText.setPosition(5.f,5.f);
    mStatisticsText.setCharacterSize(50);
    mStatisticsText.setString("Ammo: ");
    //mStatisticsText.setString("Ammo: " + std::to_string(world->player->rangedWeapon->projectilesCounter));

}

void Game::run() {
    sf::Clock clock;
    sf::Clock shootingClock;
    sf::Time shootingTime = shootingClock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //mWindow->setFramerateLimit(60);

    while (mWindow->isOpen()) {

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        //If rendering is slow, it may happen that processEvents() and update() are called multiple times before one render()
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(shootingClock);
            update(elapsedTime);
        }

        //frame of the game
        render();
    }
}

void Game::render() {
    mWindow->clear();

    world->draw();
    mWindow->draw(mStatisticsText);

/*
    int size = throphies->listAchievements.size();

    for(int i=0; i<size; i++)
        mWindow->draw(throphies->listAchievements[i]->mStatisticsText);
*/
    mWindow->display();
}

void Game::processEvents(sf::Clock& shootingClock) {

    sf::Event event;
    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            case sf::Event::KeyPressed:
                world->handlePlayerInput(event.key.code, true, shootingClock);
                break;
            case sf::Event::KeyReleased:
                world->handlePlayerInput(event.key.code, false, shootingClock);
                break;
            default:
                break;
        }
    }

}

void Game::update(sf::Time deltaTime) {
    world->update(deltaTime);
}

void Game::updateStatistics(sf::Time elapsedTime) {
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;

    if(mStatisticsUpdateTime >= sf::seconds(1.f)) {
        mStatisticsText.setString("Frames / Second = " + std::to_string(mStatisticsNumFrames) + "\n" +
                                  "Time / Update = " + std::to_string(mStatisticsUpdateTime.asMicroseconds() /
                                                                mStatisticsNumFrames) + "us");
        mStatisticsUpdateTime -= sf::seconds(1.f);
        mStatisticsNumFrames = 0;
    }

}

void Game::loadTextures() {

    textureHolder.load(Textures::RobotRed,"Media/Characters/Robot/red.png");
    textureHolder.load(Textures::RobotGray,"Media/Characters/Robot/gray.png");
    textureHolder.load(Textures::HeroBlond,"Media/Characters/People/blond.png");
    textureHolder.load(Textures::HeroBlue,"Media/Characters/People/blue.png");
    textureHolder.load(Textures::HeroWhite,"Media/Characters/People/white.png");
    textureHolder.load(Textures::HeroGray,"Media/Characters/People/gray.png");
    textureHolder.load(Textures::StarLord,"Media/Characters/People/starlord_mask.png");

    textureHolder.load(Textures::ShootingEnergy,"Media/Objects/shootingEnergy.png");
    textureHolder.load(Textures::energyShooter,"Media/Objects/energyShooter.png");
    textureHolder.load(Textures::redProjectile,"Media/Objects/redProjectile.png");

    textureHolder.load(Textures::healPack,"Media/Objects/whiteHealPack.png");

    textureHolder.load(Textures::labTile, "Media/Tiles/CustomLabTile.png");
    textureHolder.load(Textures::woodTile, "Media/Tiles/CustomWoodTile.png");
    textureHolder.load(Textures::metalTile, "Media/Tiles/metalTile.png");
    textureHolder.load(Textures::cementTile, "Media/Tiles/CustomCementTile.png");


    textureHolder.load(Textures::metalWall, "Media/Walls/CustomMetalWall.png");

    textureHolder.load(Textures::baseTile, "Media/Tiles/CustomBaseTile.png");

}