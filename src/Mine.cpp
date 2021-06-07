#pragma once
#include "Mine.h"

Mine::Mine(Item out, double rate, int x, int y, int level) :
output(out),
rate(rate)
{
	auto wrappee = std::make_unique<Building>(mineStr, x, y, level);
	setWrappee(move(wrappee));
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
void Mine::update(sf::Time time, Inventory* inventory) const {
	inventory->add(getItem(), getRate() * time.asSeconds());
}