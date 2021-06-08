#pragma once
#include "Mine.h"

Mine::Mine(Item out, double rate, int x, int y) :
output(out),
rate(rate)
{
	auto wrappee = std::make_unique<Building>(x, y);
	this->setWrappee(move(wrappee));
}

Mine::Mine(Item out, double rate, int x, int y, std::unique_ptr<Building> w) :
output(out),
rate(rate)
{
	this->setWrappee(move(w));
}

Item Mine::getItem() const {
	return output;
}

double Mine::getRate() const {
	return rate;
}

void Mine::setRate(int r) {
	rate = r;
}
void Mine::update(sf::Time time, Inventory* inventory) {
	inventory->add(getItem(), getRate() * time.asSeconds());
	inventory->add(Item::Pollution, getRate() * time.asSeconds());
	updateWrappee(time, inventory);
}
