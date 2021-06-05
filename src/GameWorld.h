#pragma once
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"
#include <vector>
#include "GameTile.h"

constexpr const char* title = "My window";

constexpr int WIDTH = 1600;
constexpr int HEIGTH = 900;
constexpr int GRID_WIDTH = 32;
constexpr int GRID_HEIGTH = 18;


class GameWorld {
	
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::vector < std::vector<GameTile*>> tiles;
	int gridWidth = GRID_WIDTH;
	int gridHeight = GRID_HEIGTH;
	sf::Event event;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	void setUpTiles();
	//On peut ajouter ici des éléments comme vector<vector> npcPositions...

public:

	std::shared_ptr<sf::RenderWindow> getWindow() const; //temp
	bool processEvents();
	void update(sf::Time);
	void render() const;

	GameWorld() = default;
	GameWorld(std::string const& bgTexture);
};