#include <iostream>
#include "GameWorld.h"
#include "Mine.h"


GameWorld::GameWorld(char* const& xmlfile, bool fileMode)
{
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGTH), title, sf::Style::Close | sf::Style::Titlebar);
    
    this->load(xmlfile, fileMode);
    //Background texture
    if (!backgroundTexture.loadFromFile(backgroundStr, sf::IntRect(0, 0, 1600, 900))) { return; }
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture);
}


void GameWorld::load(char* const& string, bool fileMode) {
    //First load the UI with buttons
    //supprButton
    auto it = std::find_if(UI.begin(), UI.end(), [&supprButtonName = "supprButton"](UIElement const& obj){return obj.name == supprButtonName; });
    if (it != UI.end()) {
        //Loading texture and apllying it to sprite
        if (!it->texture.loadFromFile("../../resources/supprButton.png")) { return; }
        it->texture.setSmooth(true);
        it->sprite.setTexture(it->texture);
        it->sprite.setColor(sf::Color(255, 255, 255, 50));
        it->sprite.setPosition(1550, 0);
    }

    //Then load the map
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
        std::cout << "Error while loading GameWorld map... \n";
        return;
    }

    //Loading each object
    buildings.clear();
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
            int x = child.attribute("x").as_int();
            int y = child.attribute("y").as_int();
            //Create Mine according to parameters
            auto mine = std::make_shared<Mine>(
                (Item)child.attribute("item").as_int(),
                child.attribute("rate").as_double(),
                x,
                y,
                child.attribute("level").as_int()
                );
            
            //Create GameTile associated with Mine
            buildings.push_back(mine);
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

    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            //Right click
            int x = event.mouseButton.x - event.mouseButton.x % 50;
            int y = event.mouseButton.y - event.mouseButton.y % 50;
            //Checking if we are clicking on a building
            for (int i = 0; i < buildings.size(); i++) {
                if (buildings[i]->getX() == x/50 && buildings[i]->getY() == y/50) {
                    handleBuildingClick(buildings[i]);
                }
            }

            //Checking if we are clicking on UI
            for (int i = 0; i < UI.size(); i++) {
                //If we desactivate the button
                if (UI[i].isActive && UI[i].sprite.getGlobalBounds().contains((float)x, (float)y)) {
                    isGlobalUIActive = false;
                    UI[i].isActive = !UI[i].isActive;
                    UI[i].sprite.setColor(sf::Color(255, 255, 255, 50));
                }
                //If no other UI elements are in use and we click on the button
                else if (!isGlobalUIActive && UI[i].sprite.getGlobalBounds().contains((float)x, (float)y)) {
                    isGlobalUIActive = true;
                    UI[i].isActive = !UI[i].isActive;
                    UI[i].sprite.setColor(sf::Color::White);
                }
            }
        }
        //Pause the input processing, else one mouse press activates the button too much times
        _sleep(250);
        break;
        //Key pressed
    case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
            window->close();
            return true;
            break;
        case sf::Keyboard::I:
            showInventory = !showInventory;
            break;
        case sf::Keyboard::U:
            showUI = !showUI;
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

void GameWorld::handleBuildingClick(std::shared_ptr<InterfaceBuilding> building) {
    //Supress mode
    if (UI[0].isActive) {
        /*for (auto& it : buildings) {
            if (building->getX() == it->getX() && building->getY() == it->getY()) {
                buildings.erase(std::remove(buildings.begin(), buildings.end(), *it));
                break;
            }
        }*/

        auto it = std::find_if(buildings.begin(), buildings.end(), [X = building->getX(), Y = building->getY()](std::shared_ptr<InterfaceBuilding>& obj) { return (obj->getX() == X && obj->getY() == Y); });

        if (it != buildings.end()) {
            auto retval = std::move(*it);
            buildings.erase(it);
            auto finalval = std::move(retval);
        }
    }
}

void  GameWorld::update(sf::Time timeElapsed) {
    for (int i = 0; i < buildings.size(); i++) {
        buildings[i]->update(timeElapsed, &inventory);
    }
}

void GameWorld::render() const {
    window->clear();
    window->draw(background);
    
    //Buildings rendering
    for (int i = 0; i < buildings.size(); i++) {
        buildings[i]->render(*window);
    }
    //Inventory rendering
    if (showInventory) {
        inventory.render(*window);
    }
    //UI rendering
    if (showUI) {
        for (int i = 0; i < UI.size(); i++) {
            window->draw(UI[i].sprite);
        }
    }
    window->display();
}
