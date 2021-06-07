#pragma once
#include "Inventory.h"
#include <SFML/Graphics.hpp>

class InterfaceBuilding {
	virtual void update(sf::Time time, Inventory& inventory) = 0;
};