#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//Couche qui consomme une ressource (input) � la vitesse (rate) 
//pour permettre � la couche inf�rieure de fonctionner

class Consumer : BuildingDecorator {
	Item input; //ce que produit la mine
	double rate; //vitesse de r�colte en item/seconde
public:
	Consumer(Item out, double rate, int x, int y);
	Consumer(Item out, double rate, int x, int y, std::unique_ptr<Building> w);
	Item getItem() const;
	int getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory& inventory);
};