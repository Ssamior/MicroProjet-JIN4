#pragma once
#include <Consumer.h>

Consumer::Consumer(char* const& textureName, Item in, double rate, int x, int y, int level) :
	input(in),
	rate(rate)
{
	auto wrappee = std::make_unique<Building>(textureName, x, y, level);
	this->setWrappee(move(wrappee));
}

Consumer::Consumer(Item in, double rate, std::unique_ptr<Building> w) :
	input(in),
	rate(rate)
{
	this->setWrappee(move(w));
}

Item Consumer::getItem() const {
	return input;
}
double Consumer::getRate() const {
	return rate;
}
void Consumer::setRate(double r) {
	rate = r;
}
void Consumer::update(sf::Time time, Inventory* inventory) const {
	if (inventory->getQuant(getItem()) >= getRate() * time.asSeconds()) {
		inventory->add(getItem(), -getRate() * time.asSeconds());
		updateWrappee(time, inventory);
	}
}