#include "Shape.h"
#include <iostream>

absoluteCoord::absoluteCoord() {
}

Shape::Shape(pugi::xml_node node) {
	label = node.attribute("label").value();
	x = node.attribute("x").as_int();
	y = node.attribute("y").as_int();
}

Shape::Shape(std::string lab, int xcoord, int ycoord) {
	label = lab;
	x = xcoord;
	y = ycoord;
}

std::string Shape::getlabel() const {
	return label;
};

int Shape::getx() const {
	return x;
};

int Shape::gety() const {
	return y;
};

void Shape::incx(int val) {
	x += val;
}

void Shape::incy(int val) {
	y += val;
}

void Shape::computeAbsoluteAux(absoluteCoord& abs, int coordx, int coordy) const {
	abs.label = getlabel();
	abs.x = coordx + getx();
	abs.y = coordy + gety();
}