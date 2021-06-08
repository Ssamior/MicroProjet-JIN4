#pragma once
#include "Inventory.h"
#include <SFML/Graphics.hpp>

class InterfaceBuilding {
public:
	virtual ~InterfaceBuilding() = default;

	virtual bool getWorkingStatus() const = 0;
	virtual void setWorkingStatus(bool isWorking) = 0;
	virtual int getX() const = 0;
	virtual void setX(int x) = 0;
	virtual int getY() const = 0;
	virtual void setY(int y) = 0;
	virtual int getLevel() const = 0;
	virtual void setLevel(int l) = 0;

	virtual bool setUpSprite(char* const&, int x, int y) = 0;
	virtual void render(sf::RenderWindow& window) const  = 0;
	virtual void update(sf::Time time, Inventory* inventory) const = 0;
};
