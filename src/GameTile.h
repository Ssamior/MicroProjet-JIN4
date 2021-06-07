#pragma once
#include <SFML/Graphics.hpp>
#include "Building.h"

class GameTile {

public:
	sf::Texture texture;
	sf::Sprite sprite;
	std::unique_ptr<Building> building;

	GameTile() = default;
	GameTile(std::string const&, std::unique_ptr<Building> building);
	bool setUpSprite(std::string const&);
};