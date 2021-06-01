#include"Circle.h"
#include <iostream>
#include <fstream>

Circle::Circle(pugi::xml_node node) : Shape(node){
	r = node.attribute("r").as_int();
	color = node.attribute("color").value();
} ;

Circle::Circle(std::string lab, int xcoord, int ycoord, int ray, std::string col) : Shape(lab, xcoord, ycoord) {
	r = ray;
	color = col;
}

int Circle::getr()const {
	return r;
};

std::string Circle::getcolor()const {
	return color;
};

void Circle::print(std::ostream& os, int& compteur, int xabs, int yabs, sf::RenderWindow& window)const {
	os << "#" << compteur << " : Circle \"" << getlabel() << "\" / absolute=(" << getx()+xabs << "," 
		<< gety()+yabs << ") / relative=(" << getx() << "," << gety() << ") / r=" << getr()
		<< " / color=\"" << getcolor() << "\"\n";
	sf::CircleShape shape(getr(), 200);
	if (color.compare("Black") == 0) {
		shape.setFillColor(sf::Color::Black);
	}
	if (color.compare("Magenta") == 0) {
		shape.setFillColor(sf::Color::Magenta);
	}
	if (color.compare("Red") == 0) {
		shape.setFillColor(sf::Color::Red);
	}
	shape.setPosition(500 - getr() +getx() + xabs, 500 -(getr() + gety() + yabs));
	window.draw(shape);
	compteur++;
};

void Circle::reach(int input, int& compteur, Shape*& result, Group*& parent) {
	if (input == compteur) {
		result = (Shape*)this;
	}
	compteur++;
}

void Circle::action(int numact, Group*& parent) {
	if (numact == 1) {
		std::string color = "";
		std::cout << "Quelle couleur ? (Black, Red, Magenta)";
		std::cin >> color;
		std::cout << "\n";
		this->color = color;
	}
	if (numact == 2) {
		parent->add(move(copy()));
	}
	if (numact == 3) {
		int x = 0;
		int y = 0;
		std::cout << "Coordonee x de la translation ?\n";
		std::cin >> x;
		std::cout << "\n";
		std::cout << "Coordonee y de la translation ?\n";
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

std::unique_ptr<Shape> Circle::copy()const {
	auto c = std::make_unique<Circle>(getlabel(), getx(), gety(), getr(), getcolor());
	return move(c);
}

void Circle::save(std::ofstream& file, int depth)const {
	std::string tabs = "";
	for (int i = 0; i < depth; i++) {
		tabs += "    ";
	}
	file << tabs << "<Circle label=\"" << getlabel() << "\" x=\"" << getx()
		<< "\" y=\"" << gety() << "\"r=\"" << getr() << "\" color=\""
		<< getcolor() << "\"/>\n";
}