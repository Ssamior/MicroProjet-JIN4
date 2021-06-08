#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const std::vector<std::string> items = {"Ingot", "Iron", "Stone", "Coal", "Wood", "Pollution", "NotAnItem"};
enum Item { Ingot = 0, Iron = 1, Stone = 2, Coal = 3, Wood = 4, Pollution = 5, End = 6};

//This class is used as a global inventory for the player
class Inventory {
private:
	std::vector<double> content = std::vector<double>(Item::End);
	sf::Font font;
public:
	int getQuant(int item) const;
	sf::Font getFont() const;
	void add(int item, double quant);
	void render(sf::RenderWindow& window) const;

	Inventory();
};