#pragma once
#include "Mine.h"

Item Mine::getItem() const {
	return output;
}
int Mine::getRate() const {
	return rate;
}
void Mine::setRate(int r) {
	rate = r;
}
void Mine::update(sf::Time time, Inventory &inventory) {
	inventory.add(getItem(), getRate() * time.asSeconds());
}