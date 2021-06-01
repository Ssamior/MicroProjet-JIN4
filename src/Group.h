#pragma once
#include "Shape.h"
#include "Circle.h"


class Group : public Shape {
private:
	std::vector<std::unique_ptr<Shape>> members;
public:
	Group(pugi::xml_node node);
	Group(std::string lab, int xcoord, int ycoord);
	std::unique_ptr<Shape>const& getmember(int indice) const;
	void add(std::unique_ptr<Shape> elem);
	void computeAbsoluteAux(absoluteCoord& abs, int coordx, int coordy) const override;
	void computeAbsolute(absoluteCoord& abs) const;
	void print(std::ostream& os, int& compteur, int xabs, int yabs, sf::RenderWindow& window)const override;
	void reach(int input, int& compteur, Shape*& result, Group*& parent)override;
	void action(int numact, Group*& parent) override;
	std::unique_ptr<Shape> copy()const override;
	void save(std::ofstream& file, int depth)const override;
};