#pragma once
#include "Building.h"

class BuildingDecorator : public InterfaceBuilding {
private:
	std::unique_ptr<Building> wrappee;
public:
	int getX() const override;
	void setX(int x);
	int getY() const override;
	void setY(int y);
	int getLevel() const;
	void setLevel(int l);
	Building* getWrappee() const;
	void setWrappee(std::unique_ptr<Building> w);
	bool setUpSprite(char* const&, int x, int y);
	void render(sf::RenderWindow& window) const override;
	void update(sf::Time time, Inventory* inventory) const override;
};