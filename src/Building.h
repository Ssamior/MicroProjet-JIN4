#pragma once
#include "InterfaceBuilding.h"
#include <string>
#include <SFML/Graphics.hpp>

class Building : public InterfaceBuilding {
private:
	int x;
	int y;
	int level;
	bool isWorking = true;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Building(char* const& textureName, int x, int y, int level = 1);

	bool getWorkingStatus() const override;
	void setWorkingStatus(bool isWorking) override;
	int getX() const override;
	void setX(int x) override;
	int getY() const override;
	void setY(int y) override;
	int getLevel() const override;
	void setLevel(int l) override;

	bool setUpSprite(char* const&, int x, int y) override;
	void render(sf::RenderWindow& window) const override;
	void update(sf::Time time, Inventory* inventory) const override;
};
