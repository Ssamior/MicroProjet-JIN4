#include <iostream>
#include "Inventory.h"

Inventory::Inventory() {
	//Loading the font used to display the inventory
	if (!font.loadFromFile("../../resources/arial.ttf"))
	{
		//Error
		std::cout << "Error while loading inventory font";
		return;
	}
}

int Inventory::getQuant(int item) const {
	return (int)round(content[item]);
}

sf::Font Inventory::getFont() const {
	return font;
}

void Inventory::add(int item, double quant) {
	content[item] += quant;
}

void Inventory::render(sf::RenderWindow& window) const {
	sf::Text text;
	std::string str = "";
	for (int item = Item::Ingot; item != Item::End; item++)
	{
		str.append(items[item] + " : " + std::to_string(getQuant(item)) + "\n");
	}
	text.setFont(font);
	text.setString(str);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(24);

	window.draw(text);
}

