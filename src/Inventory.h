#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const std::vector<std::string> items = {"Iron", "Salt", "Coal", "Pollution", "NotAnItem"};
enum Item { Iron = 0, Salt = 1, Coal = 2, Pollution = 3, End = 4};

class Inventory {
private:
	std::vector<double> content = std::vector<double>(Item::End);
	sf::Font font;
public:
	int getQuant(int item) const;
	void add(int item, double quant);
	void render(sf::RenderWindow& window) const;

	Inventory();
};