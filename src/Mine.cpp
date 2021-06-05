#pragma once
#include "Mine.h"

Item Mine::getItem() {
	return output;
}
int Mine::getRate() {
	return rate;
}
void Mine::setRate(int r) {
	rate = r;
}
void Mine::update(sf::Time time, Inventory &inventory) {
	inventory.add(getItem(), getRate() * time.asSeconds());
}