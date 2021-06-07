#pragma once
#include <SFML/Graphics.hpp>
#include "Building.h"

class GameTile {

public:
	sf::Texture texture;
	sf::Sprite sprite;
	std::unique_ptr<InterfaceBuilding> building;

	GameTile() = default;
	GameTile(char* const&, std::unique_ptr<InterfaceBuilding> building, int x, int y);
	bool setUpSprite(char* const&, int x, int y);
	void render(sf::RenderWindow& window) const;
};