#include "Group.h"
#include <iostream>
#include <fstream>

Group::Group(pugi::xml_node node) : Shape(node)
{
	for (auto child : node.children()) {
		std::string type = child.name();
		if (type.compare("Circle") == 0) {
			auto c = std::make_unique<Circle>(child);
			members.push_back(move(c));
		}
		else {
			auto g = std::make_unique<Group>(child);
			members.push_back(move(g));
		}
	}
}

Group::Group(std::string lab, int xcoord, int ycoord) : Shape(lab, xcoord, ycoord) {

}

std::unique_ptr<Shape>const& Group::getmember(int indice) const {
	return members[indice];
}

void Group::add(std::unique_ptr<Shape> elem) {
	members.push_back(move(elem));
}

//fonction auxiliaire qui permet de calculer les coordonées en partant des x et y passés en arguments
void Group::computeAbsoluteAux(absoluteCoord& abs, int coordx, int coordy) const {
	Shape::computeAbsoluteAux(abs, coordx, coordy);
	for (auto& const pShape : members) {
		auto pAbs = new absoluteCoord();
		(*pShape).computeAbsoluteAux(*pAbs, abs.x, abs.y);
		abs.members.push_back(pAbs);
	}
}

void Group::computeAbsolute(absoluteCoord& abs) const {
	computeAbsoluteAux(abs, 0, 0);
}

void Group::print(std::ostream& os, int& compteur, int xabs, int yabs, sf::RenderWindow& window)const {
	os << "#" << compteur << " : Group \"" << getlabel() << "\" / absolute=(" << getx()+xabs << "," 
		<< gety()+yabs << ") / relative=(" << getx() << "," << gety() << ")\n";
	compteur++;
	for(auto& const shape : members) {
		shape->print(os, compteur, xabs+getx(), yabs+gety(), window);
	}
}

void Group::reach(int input, int& compteur, Shape*& result, Group*& parent) {
	if (input == compteur) {
		result = (Shape*) this;
	}
	compteur++;
	parent = this;
	for (auto& const shape : members) {
		if(compteur <= input){
			shape->reach(input, compteur, result, parent);
		}
	}
}

void Group::action(int numact, Group*& parent) {
	if (numact == 1) {
		std::cout << "Impossible de changer la couleur d'un groupe";
	}
	if (numact == 2) {
		parent->add(move(copy()));
	}
	if (numact == 3) {
		int x = 0;
		int y = 0;
		std::cout << "Coordonée x de la translation ?\n";
		std::cin >> x;
		std::cout << "\n";
		std::cout << "Coordonée y de la translation ?\n";
		std::cin >> y;
		std::cout << "\n";
		incx(x);
		incy(y);
	}
	if (numact == 4) {
		std::string nomfic;
		std::cout << "Nom du fichier ?\n";
		std::cin >> nomfic;
		std::cout << "\n";
		std::ofstream file;
		file.open(nomfic);
		file << "<?xml version=\"1.0\"?>\n";
		save(file, 0);
	}
}

std::unique_ptr<Shape> Group::copy()const {
	auto g = std::make_unique<Group>(getlabel(), getx(), gety());
	for (auto& const shape : members) {
		g->add(move(shape->copy()));
	}
	return move(g);
}

void Group::save(std::ofstream& file, int depth)const {
	std::string tabs = "";
	for (int i = 0; i < depth; i++) {
		tabs += "    ";
	}
	file << tabs << "<Group label=\"" << getlabel() << "\" x=\"" << getx()
		<< "\" y=\"" << gety() << "\"/>\n";
	for (auto& const shape : members) {
		shape->save(file, depth + 1);
	}
	file << tabs << "</Group>\n";
}