#pragma once
#include "InterfaceBuilding.h"
#include "Building.h"

class BuildingDecorator : InterfaceBuilding {
private:
	Building wrappee;
public:
	BuildingDecorator(Building wrappee);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getLevel();
	void setLevel(int l);
	void render(sf::RenderTarget* target);
};