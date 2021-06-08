#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include "Building.h"
#include <SFML/Graphics.hpp>

//Use a resource (input) at a given rate
class Consumer : public BuildingDecorator {
	Item input;
	double rate;
public:
	Consumer(char* const& textureName, Item out, double rate, int x, int y, int level = 1);
	Consumer(Item out, double rate, std::shared_ptr<InterfaceBuilding> w);
	Item getItem() const;
	double getRate() const;
	void setRate(double r);
	void update(sf::Time time, Inventory* inventory) const override;
};