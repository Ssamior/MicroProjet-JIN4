#include "myMain.h"
#include "GameWorld.h"
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>



const std::string background = "D:/01 - Documents/_Telecom 2eme annee/Informatique/Developpement C++/MicroprojetJIN/resources/dirtFloor.png";




int myMain()
{
    bool leaveGame = false;
    GameWorld gameWorld(background);

       
    sf::Clock clock;
    
    while (!leaveGame) {
        leaveGame = gameWorld.processEvents();
        gameWorld.update(clock.restart());
        gameWorld.render();
       
    }
    return 0;
}