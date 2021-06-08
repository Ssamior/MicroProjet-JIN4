#pragma once
#include "Mine.h"


Mine::Mine(char* const& textureName, Item out, double rate, double pollutionRate, int x, int y, int level) :
output(out),
rate(rate),
pollutionRate(pollutionRate)
{
	auto wrappee = std::make_shared<Building>(textureName, x, y, level);
	this->setWrappee(move(wrappee));
}

Mine::Mine(Item out, double rate, std::shared_ptr<InterfaceBuilding> w) :
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

double Mine::getPollutionRate() const {
	return pollutionRate;
}

void Mine::setRate(double r) {
	rate = r;
}

void Mine::setPollutionRate(double pr) {
	pollutionRate = pr;
}

void Mine::update(sf::Time time, Inventory* inventory) const {
	if (getWrappee()->getWorkingStatus()) {
		inventory->add(getItem(), getRate() * time.asSeconds());
		inventory->add(Item::Pollution, getPollutionRate() * time.asSeconds());
		this->updateWrappee(time, inventory);
	}
}
