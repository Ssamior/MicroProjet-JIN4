#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//Couche qui consomme une ressource (input) à la vitesse (rate) 
//pour permettre à la couche inférieure de fonctionner

class Consumer : public BuildingDecorator {
	Item input; //ce que produit la mine
	double rate; //vitesse de récolte en item/seconde
public:
	Consumer(char* const& textureName, Item out, double rate, int x, int y, int level = 1);
	Consumer(Item out, double rate, std::unique_ptr<Building> w);
	Item getItem() const;
	double getRate() const;
	void setRate(double r);
	void update(sf::Time time, Inventory* inventory) const override;
};