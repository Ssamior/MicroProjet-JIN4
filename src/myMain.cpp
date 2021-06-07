#include "myMain.h"
#include "GameWorld.h"
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>

constexpr char* xmlfile = "D:/01 - Documents/_Telecom 2eme annee/Informatique/Developpement C++/MicroprojetJIN/resources/map.xml";




int myMain()
{
    bool leaveGame = false;
    GameWorld gameWorld(xmlfile);

       
    sf::Clock clock;
    
    while (!leaveGame) {
        leaveGame = gameWorld.processEvents();
        gameWorld.update(clock.restart());
        gameWorld.render();
       
    }
    return 0;
}