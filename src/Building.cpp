#include "Building.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

//constructor
Building::Building(char* const& textureName, int x, int y, int level) :
	x(x),
	y(y),
	level(level)
{
	if (!setUpSprite(textureName, x*50, y*50)) {
		return;
	}
}

//Checking if any decorator is preventing the building to consume and produce resources
bool Building::getWorkingStatus() const {
	return isWorking;
}
//Updates can come from any decorator apllied to the building
void Building::setWorkingStatus(bool isWorkingBool) {
	isWorking = isWorkingBool;
}
//Initializing the building's sprite
bool Building::setUpSprite(char* const& textureName, int xSprite, int ySprite) {
	if (!texture.loadFromFile(textureName, sf::IntRect(0, 0, 50, 50)))
	{
		return false;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition((float)xSprite, (float)ySprite);
	return true;
}

int Building::getX() const {
	return x;
}
void Building::setX(int x1) {
	x = x1;
}
int Building::getY() const {
	return y;
}
void Building::setY(int y1) {
	y = y1;
}
int Building::getLevel() const {
	return level;
}
void Building::setLevel(int level1) {
	level = level1;
}

void Building::render(sf::RenderWindow& window) const {
	window.draw(sprite);
}

void Building::update(sf::Time time, Inventory* inventory) const {
	//empty function
}
