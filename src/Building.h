#pragma once
#include "InterfaceBuilding.h"
#include <string>
#include <SFML/Graphics.hpp>

class Building : public InterfaceBuilding {
private:
	int x;
	int y;
	int level;
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	Building(char* const& textureName, int x, int y, int level = 1);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getLevel() const;
	void setLevel(int l);

	bool setUpSprite(char* const&, int x, int y);
	void render(sf::RenderWindow& window) const override;
	void update(sf::Time time, Inventory* inventory) const override;
};