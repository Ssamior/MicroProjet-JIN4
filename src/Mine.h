#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

class Mine : BuildingDecorator {
	Item output; //ce que produit la mine
	double rate; //vitesse de récolte en item/seconde
public:
	Item getItem() const;
	int getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory& inventory);
};