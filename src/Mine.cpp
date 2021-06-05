#pragma once
#include "Mine.h"

Item Mine::getItem() {
	return out;
}
int Mine::getRate() {
	return rate;
}
void Mine::setRate(int r) {
	rate = r;
}