#pragma once
#include "BuildingDecorator.h"

int BuildingDecorator::getX() {
	return wrappee.getX();
}
void BuildingDecorator::setX(int x) {
	wrappee.setX(x);
}
int BuildingDecorator::getY() {
	return wrappee.getY();
}
void BuildingDecorator::setY(int y) {
	wrappee.setY(y);
}
int BuildingDecorator::getLevel() {
	return wrappee.getLevel();
}
void BuildingDecorator::setLevel(int l) {
	wrappee.setLevel(l);
}
void BuildingDecorator::display() {
	wrappee.display();
}