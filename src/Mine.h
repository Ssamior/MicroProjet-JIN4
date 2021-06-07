#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>


//Couche qui récolte une ressource (output) à la vitesse de (rate) par seconde,
//et qui produit la même quantité de pollution au passage

class Mine : BuildingDecorator {
	Item output; //ce que produit la mine
	double rate; //vitesse de récolte en item/seconde
public:
	Mine(Item out, double rate, int x, int y);
	Mine(Item out, double rate, int x, int y, std::unique_ptr<Building> w);
	Item getItem() const;
	int getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory& inventory);
};