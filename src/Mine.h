#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include "Building.h"
#include <SFML/Graphics.hpp>


//Produce a resource (output) at a given rate and pollution

class Mine : public BuildingDecorator {
	Item output;
	double rate;
	double pollutionRate;
public:
	Mine(char* const& textureName, Item out, double rate, double pollutionRate, int x, int y, int level = 1);
	Mine(Item out, double rate, std::shared_ptr<InterfaceBuilding> w);
	Item getItem() const;
	double getRate() const;
	double getPollutionRate() const;
	void setRate(double r);
	void setPollutionRate(double pr);
	void update(sf::Time time, Inventory* inventory) const override;
};
