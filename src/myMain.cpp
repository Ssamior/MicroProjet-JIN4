#include "myMain.h"
#include "GameState.h"
#include <iostream>
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

bool processEvents(sf::RenderWindow& window) {
    sf::Event event;
    window.pollEvent(event);

    //Check the type of the event
    switch (event.type)
        {
            //Window closed
        case sf::Event::Closed:
            return true;
            break;

            //Key pressed
        case sf::Event::KeyPressed:
            std::cout << "Key pressed \n";
            break;

        default:
            break;
        }
    return false;
}

void  update(GameState *gameState, sf::Time timeElapsed) {

}

void render(GameState const& gameState, sf::RenderWindow& window) {
    
}

int myMain()
{
    bool leaveGame = false;
    GameState gameState; //Contains the state of the game, such as ...
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    sf::Clock clock;

    /**/
    sf::Texture texture;
    if (!texture.loadFromFile("D:/01 - Documents/_Telecom 2eme annee/Informatique/Developpement C++/MicroprojetJIN/resources/magnifiquePersonnage.png"))
    {
        std::cout << "Erreur texture\n";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
    window.display();
    
    while (!leaveGame) {
        leaveGame = processEvents(window);
        update(&gameState, clock.restart());
        render(gameState, window);
       
    }
    window.close();
    return 0;
}