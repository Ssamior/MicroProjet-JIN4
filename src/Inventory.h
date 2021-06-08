#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const std::vector<std::string> items = {"Iron", "Stone", "Coal", "Wood", "Pollution", "NotAnItem"};
enum Item { Iron = 0, Stone = 1, Coal = 2, Wood = 3, Pollution = 4, End = 5};

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