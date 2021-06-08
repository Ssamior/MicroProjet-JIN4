#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>


//Couche qui recolte une ressource (output) a la vitesse de (rate) par seconde,
//et qui produit la meme quantite de pollution au passage

class Mine : public BuildingDecorator {
	Item output; //ce que produit la mine
	double rate; //vitesse de recolte en item/seconde
	double pollutionRate; //vitesse de recolte en pollution/seconde
public:
	Mine(char* const& textureName, Item out, double rate, double pollutionRate, int x, int y, int level = 1);
	Mine(Item out, double rate, std::unique_ptr<Building> w);
	Item getItem() const;
	double getRate() const;
	double getPollutionRate() const;
	void setRate(double r);
	void setPollutionRate(double pr);
	void update(sf::Time time, Inventory* inventory) const override;
};
