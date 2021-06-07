#pragma once
#include "InterfaceBuilding.h"
#include "Building.h"

class BuildingDecorator : InterfaceBuilding {
private:
	std::unique_ptr<Building> wrappee;
public:
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getLevel() const;
	void setLevel(int l);
	Building* getWrappee() const;
	void setWrappee(std::unique_ptr<Building> w);
};