#include "GameWorld.h"
#include <iostream>

GameWorld::GameWorld(std::string const& bgTexture) 
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGTH), title, sf::Style::Close | sf::Style::Titlebar);
    
    //Background texture
    if (!backgroundTexture.loadFromFile(bgTexture, sf::IntRect(0, 0, 1600, 900)))
    {
        return;
    }
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);
}


void GameWorld::setUpTiles() {
    tiles.clear();
    
}

std::shared_ptr<sf::RenderWindow> GameWorld::getWindow() const { //TEMP
    return window;
}

bool GameWorld::processEvents() {
 
    window->pollEvent(event);

    //Check the type of the event
    switch (event.type)
    {
        //Window closed
    case sf::Event::Closed:
        window->close();
        return true;
        break;

        //Key pressed
    case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            window->close();
            return true;
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
    return false;
}

void  GameWorld::update(sf::Time timeElapsed) {
    //updating
}

void GameWorld::render() const {
    window->clear();
    window->draw(background);

    //rendering

    window->display();
}
