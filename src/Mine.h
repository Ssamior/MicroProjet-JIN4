#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//Resources
constexpr char* mineStr = "../../resources/mine.png";

class Mine : public BuildingDecorator {
	Item output; //ce que produit la mine
	double rate; //vitesse de récolte en item/seconde
public:
	Mine(Item out, double rate, int x, int y, int level = 1);
	Item getItem() const;
	double getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory* inventory) const override;
};