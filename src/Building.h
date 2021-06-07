#pragma once
#include "InterfaceBuilding.h"
#include <string>
#include <SFML/Graphics.hpp>

class Building : InterfaceBuilding {
private:
	int x;
	int y;
	int level = 1;
public:
	Building(int x, int y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getLevel() const;
	void setLevel(int l);
	void update(sf::Time time, Inventory& inventory);
};