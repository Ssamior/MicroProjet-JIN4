#pragma once
#include "BuildingDecorator.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

int BuildingDecorator::getX() const {
	return wrappee->getX();
}
void BuildingDecorator::setX(int x) {
	wrappee->setX(x);
}
int BuildingDecorator::getY() const {
	return wrappee->getY();
}
void BuildingDecorator::setY(int y) {
	wrappee->setY(y);
}
int BuildingDecorator::getLevel() const {
	return wrappee->getLevel();
}
void BuildingDecorator::setLevel(int l) {
	wrappee->setLevel(l);
}
Building* BuildingDecorator::getWrappee() const {
	return this->wrappee.get();
}
void BuildingDecorator::setWrappee(std::unique_ptr<Building> w) {
	this->wrappee = move(w);
}

bool BuildingDecorator::setUpSprite(char* const& textureName, int xSprite, int ySprite) {
	return this->wrappee->setUpSprite(textureName, xSprite, ySprite);
}

void BuildingDecorator::render(sf::RenderWindow& window) const {
	this->wrappee->render(window);
}

void BuildingDecorator::update(sf::Time time, Inventory* inventory) const {
	this->wrappee->update(time, inventory);
}

void BuildingDecorator::updateWrappee(sf::Time time, Inventory& inventory) {
	wrappee->update(time, inventory);
