#include "Building.h"
#include <SFML/Graphics.hpp>

Building::Building(int x, int y) :
	x(x), y(y)
{
	
}

int Building::getX() const {
	return x;
}
void Building::setX(int x) {
	this->x = x;
}
int Building::getY() const {
	return y;
}
void Building::setY(int y) {
	this->y = y;
}
int Building::getLevel() const {
	return level;
}
void Building::setLevel(int l) {
	this->level = level;
}
void Building::update(sf::Time time, Inventory& inventory) {

}