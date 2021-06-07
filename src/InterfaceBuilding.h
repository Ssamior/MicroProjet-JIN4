#pragma once
#include "Inventory.h"
#include <SFML/Graphics.hpp>

class InterfaceBuilding {
public:
	virtual ~InterfaceBuilding() = default;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual void render(sf::RenderWindow& window) const = 0;
	virtual void update(sf::Time time, Inventory* inventory) const = 0;
};