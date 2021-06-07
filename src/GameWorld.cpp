#include "GameWorld.h"
#include <iostream>


GameWorld::GameWorld(char* const& xmlfile, bool fileMode)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGTH), title, sf::Style::Close | sf::Style::Titlebar);
    
    this->load(xmlfile, fileMode);
    //Background texture
    if (!backgroundTexture.loadFromFile(backgroundStr, sf::IntRect(0, 0, 1600, 900)))
    {
        return;
    }
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);
}


void GameWorld::load(char* const& string, bool fileMode) {
    //Setting up tiles
    tiles.clear();
    pugi::xml_document doc;
    pugi::xml_parse_result result;
    if (fileMode) { //Load from a file
        result = doc.load_file(string);
    }
    else { //Load from a string
        std::string str = string; //cast to std::string
        result = doc.load_string(str.c_str());
    }
    
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

Inventory GameWorld::getInventory() const {
    return this->inventory;
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
    inventory.render(*window);


    window->display();
}
