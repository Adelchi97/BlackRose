//
// Created by Ludovico on 11/06/2018.
//
#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer() {
    tx.loadFromFile( "Eksword8bit.png" );


    mSprite.setTexture(tx);
    sf::Vector2u size = tx.getSize();
    mSprite.setOrigin(size.x / 2, size.y / 2);

    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
};

void Game::run() {
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::update() {
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= 1.f;
    if (mIsMovingDown)
        movement.y += 1.f;
    if (mIsMovingLeft)
        movement.x -= 1.f;
    if (mIsMovingRight)
        movement.x += 1.f;
    mSprite.move(movement);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::processEvents() {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    handlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    handlePlayerInput(event.key.code, false);
                    break;
                case sf::Event::Closed:
                    mWindow.close();
                    break;
            }
        }
}



void Game::render()
{
    mWindow.clear();
    mWindow.draw(mSprite);
    mWindow.display();
}