#pragma once
#include <Consumer.h>

Consumer::Consumer(char* const& textureName, Item in, double rate, int x, int y, int level) :
	input(in),
	rate(rate)
{
	auto wrappee = std::make_unique<Building>(textureName, x, y, level);
	this->setWrappee(move(wrappee));
}

Consumer::Consumer(Item in, double rate, std::shared_ptr<InterfaceBuilding> w) :
	input(in),
	rate(rate)
{
	this->setWrappee(w);
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
	//If we do not have enough resources to consume
	if (inventory->getQuant(getItem()) < getRate() * time.asSeconds()) {
		//We cannot work
		getWrappee()->setWorkingStatus(false);
	}
	//Enough resources
	else {
		//If we can work
		if (getWrappee()->getWorkingStatus()) {
			//Work : other decorators did not block
			inventory->add(getItem(), -getRate() * time.asSeconds());
			updateWrappee(time, inventory);
		}
		
		else {
			//Declare that we are ready to work because we have resources
			getWrappee()->setWorkingStatus(true);
		}
	}
}