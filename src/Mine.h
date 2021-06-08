#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//Resources
constexpr char* mineStr = "../../resources/mine.png";


//Couche qui r�colte une ressource (output) � la vitesse de (rate) par seconde,
//et qui produit la m�me quantit� de pollution au passage

class Mine : BuildingDecorator {
	Item output; //ce que produit la mine
	double rate; //vitesse de r�colte en item/seconde
public:
	Mine(Item out, double rate, int x, int y, int level = 1);
	Mine(Item out, double rate, int x, int y, std::unique_ptr<Building> w);
	Item getItem() const;
	double getRate() const;
	void setRate(int r);
	void update(sf::Time time, Inventory* inventory) const override;
};
