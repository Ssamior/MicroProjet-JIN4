#include "myMain.h"
#include "GameWorld.h"
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>

int myMain()
{
    bool leaveGame = false;
    GameWorld gameWorld("../../resources/map.xml");

       
    sf::Clock clock;
    
    //Main loop
    while (!leaveGame) {
        leaveGame = gameWorld.processEvents();
        //Passing elapsed time since last loop as parameter
        gameWorld.update(clock.restart());
        gameWorld.render();
       
    }
    return 0;
}