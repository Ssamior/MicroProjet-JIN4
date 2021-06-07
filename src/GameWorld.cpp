#include "GameWorld.h"
#include <iostream>
#include "pugixml.hpp"


GameWorld::GameWorld(char* const& xmlfile)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGTH), title, sf::Style::Close | sf::Style::Titlebar);
    
    //Background texture
    if (!backgroundTexture.loadFromFile(backgroundStr, sf::IntRect(0, 0, 1600, 900)))
    {
        return;
    }
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);

    this->load(xmlfile);
}


void GameWorld::load(char* const& string) {
    //Setting up tiles
    tiles.clear();
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(string);
    if (!result) {
        //Error
        std::cout << "Loading error ... \n";
        return;
    }

    //Loading each object
    for (auto child : doc.children()) {
        std::string name = child.name();

        if (name.compare("Inventory") == 0) {
            //Fill inventory
            int i = 0;
            for (auto it = child.attributes().begin(); it != child.attributes().end(); it++) {
                inventory.add(i,it->as_int());
                i++;
            }
            std::cout << inventory.getQuant(Item::Coal) << "\n";
        }


        else if (name.compare("Mine") == 0) {
            //Create Mine according to parameters
            //std::unique_ptr mine = make_unique<Mine>(parameters);
            int x = child.attribute("x").as_int();
            int y = child.attribute("y").as_int();
            //Create GameTile associated with Mine
            
            //GameTile tile = GameTile(mineStr, std::move(mine));
            //tiles[x][y] = tile;
        }
    }
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
