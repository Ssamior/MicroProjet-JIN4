#pragma once
#include "BuildingDecorator.h"

class Mine : BuildingDecorator {
	Item out; //ce que produit la mine
	int rate; //vitesse de récolte en item/heure
public:
	Item getItem();
	int getRate();
	void setRate(int r);
};