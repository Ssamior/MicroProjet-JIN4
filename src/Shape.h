#pragma once
#include<string>
#include "pugixml.hpp"
#include <vector>
#include <memory>
#include <ostream>
#include <SFML/Graphics.hpp>

class Group;

struct absoluteCoord {
	std::string label;
	int x=-1;
	int y=-1;
	std::vector <absoluteCoord*> members;
	absoluteCoord();
};

class Shape {
private:
	std::string label;
	int x;
	int y;
public:
	virtual ~Shape() = default;
	Shape(pugi::xml_node node);
	Shape(std::string lab, int xcoord, int ycoord);
	std::string getlabel() const;
	int getx() const;
	int gety() const;
	void incx(int val);
	void incy(int val);
	virtual void computeAbsoluteAux(absoluteCoord& abs, int coordx, int coordy) const;
	virtual void print(std::ostream& os, int& compteur, int xrel, int yrel, sf::RenderWindow& window)const = 0;
	virtual void reach(int input, int& compteur, Shape*& result, Group*& parent) = 0;
	virtual void action(int numact, Group*& parent) = 0;
	virtual std::unique_ptr<Shape> copy()const = 0;
	virtual void save(std::ofstream& file, int depth)const = 0;
};