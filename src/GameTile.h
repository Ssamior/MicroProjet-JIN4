#pragma once
#include <SFML/Graphics.hpp>

class GameTile {

public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;

	GameTile() = default;
	GameTile(std::string const&, float, float);
	bool setUpSprite(std::string const&);
};