#pragma once
#include "BuildingDecorator.h"
#include <SFML/Graphics.hpp>

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
void BuildingDecorator::render(sf::RenderTarget* target) {
	wrappee.render(target);
}