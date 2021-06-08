#pragma once
#include "InterfaceBuilding.h"

//The decorator can be applied to any Building object, adding new properties to the latter
class BuildingDecorator : public InterfaceBuilding {
private:
	std::shared_ptr<InterfaceBuilding> wrappee;
	
public:
	
	bool getWorkingStatus() const override;
	void setWorkingStatus(bool isWorking) override;
	int getX() const override;
	void setX(int x) override;
	int getY() const override;
	void setY(int y) override;
	int getLevel() const override;
	void setLevel(int l) override;
	std::shared_ptr<InterfaceBuilding> getWrappee() const;
	void setWrappee(std::shared_ptr<InterfaceBuilding> w);
	bool setUpSprite(char* const&, int x, int y) override;
	void render(sf::RenderWindow& window) const override;
	void update(sf::Time time, Inventory* inventory) const override;
	void updateWrappee(sf::Time time, Inventory* inventory) const;
};
