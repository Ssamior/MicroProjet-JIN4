#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//Couche qui consomme une ressource (input) à la vitesse (rate) 
//pour permettre à la couche inférieure de fonctionner

class Consumer : BuildingDecorator {
	Item input; //ce que produit la mine
	double rate; //vitesse de récolte en item/seconde
public:
	Consumer(Item out, double rate, int x, int y);
	Consumer(Item out, double rate, int x, int y, std::unique_ptr<Building> w);
	Item getItem() const;
	int getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory& inventory);
};