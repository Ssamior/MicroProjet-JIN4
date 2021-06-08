#pragma once
#include <Consumer.h>

Consumer::Consumer(Item in, double rate, int x, int y) {
	auto wrappee = std::make_unique<Building>(x, y);
	this->setWrappee(move(wrappee));
	this->input = in;
	this->rate = rate;
}

Consumer::Consumer(Item in, double rate, int x, int y, std::unique_ptr<Building> w) {
	auto wrappee = std::make_unique<Building>(x, y);
	this->setWrappee(move(wrappee));
	this->input = in;
	this->rate = rate;
	this->setWrappee(move(w));
}

Item Consumer::getItem() const {
	return input;
}
int Consumer::getRate() const {
	return rate;
}
void Consumer::setRate(int r) {
	rate = r;
}
void Consumer::update(sf::Time time, Inventory& inventory) {
	if (inventory.getQuant(getItem()) >= getRate() * time.asSeconds()) {
		inventory.add(getItem(), -getRate() * time.asSeconds());
		updateWrappee(time, inventory);
	}
}