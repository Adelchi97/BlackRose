//
// Created by Elena Faillace on 22/06/2018.
//

#include "../include/Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(800, 800), "BlackRose", sf::Style::Default)), mFont(),
               mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0), isMovingDown(false), isMovingUp(false),
               isMovingLeft(false), isMovingRight(false), world(mWindow,textureHolder) {
               mStatisticsText(), mStatisticsUpdateTime(), mStatisticsNumFrames(0), world(nullptr) {

    loadTextures();
    world.reset(new World(mWindow,textureHolder));

    //sets the icon
    sf::Image icon;
    if(!icon.loadFromFile("Media/Icon.png"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    /*
    //Statistics text
    mFont.loadFromFile("Media/Sansation.ttf");
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(50);
    //mStatisticsText.setColor(sf::Color::Cyan);
    mStatisticsText.setString("Hello");
     */

}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    loadTextures();

    while (mWindow->isOpen()) {

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        //DOMANDA: se processEvents o update poi sono lenti non rischio di non stampare mai il risultato?
        //If rendering is slow, it may happen that processEvents() and update() are called multiple times before one render()
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
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

    mWindow->display();
}

void Game::processEvents() {

    sf::Event event;
    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                world->handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                world->handlePlayerInput(event.key.code, false);
                break;
            default:
                break;
        }
    }

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        isMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        isMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        isMovingRight = isPressed;
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

    textureHolder.load(Textures::RobotRed,"Media/Characters/Robot/red/redRobot.png");
    textureHolder.load(Textures::RobotGray,"Media/Characters/Robot/gray/grayRobot.png");
    textureHolder.load(Textures::RobotRed,"Media/Characters/Robot/red.png");
    textureHolder.load(Textures::RobotGray,"Media/Characters/Robot/gray.png");
    textureHolder.load(Textures::HeroBlond,"Media/Characters/People/blond.png");
    textureHolder.load(Textures::HeroBlue,"Media/Characters/People/blue.png");

    /*
    textureHolder.load(Textures::RobotGray, "Media/Characters/Robot/gray/tile009.png");
    textureHolder.load(Textures::RobotRed, "Media/Characters/Robot/red/tile009.png");
    textureHolder.load(Textures::Floor, "Media/Tiles/lab/tile000.png");
     */
}