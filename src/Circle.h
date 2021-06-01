#pragma once
#include "pugixml.hpp"
#include <string>
#include <vector>
#include "Group.h"
#include "Shape.h"

class Circle : public Shape {
private:
	int r;
	std::string color;
public:
	Circle(pugi::xml_node node);
	Circle(std::string lab, int xcoord, int ycoord, int ray, std::string col);
	int getr()const;
	std::string getcolor()const;
	void print(std::ostream& os, int& compteur, int xabs, int yabs, sf::RenderWindow& window)const override;
	void reach(int input, int& compteur, Shape*& result, Group*& parent) override;
	void action(int numact, Group*& parent) override;
	std::unique_ptr<Shape> copy()const override;
	void save(std::ofstream& file, int depth)const override;
};