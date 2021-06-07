#pragma once
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"
#include <vector>
#include "GameTile.h"
#include "Inventory.h"

//Window parameters
constexpr const char* title = "My window";
constexpr int WIDTH = 1600;
constexpr int HEIGTH = 900;
constexpr int GRID_WIDTH = 32;
constexpr int GRID_HEIGTH = 18;

//Resources
constexpr char* backgroundStr = "D:/01 - Documents/_Telecom 2eme annee/Informatique/Developpement C++/MicroprojetJIN/resources/dirtFloor.png";
constexpr char* mineStr = "D:/01 - Documents/_Telecom 2eme annee/Informatique/Developpement C++/MicroprojetJIN/resources/mine.png";


class GameWorld {
	
private:
	std::shared_ptr<sf::RenderWindow> window;
	//tiles is a 2D vector consisting of GRID_HEIGTH rows and GRID_WIDTH columns
	std::vector<std::vector<GameTile*>> tiles = 
		std::vector<std::vector<GameTile*>>(GRID_HEIGTH, std::vector<GameTile*>(GRID_WIDTH));
	Inventory inventory;
	int gridWidth = GRID_WIDTH;
	int gridHeight = GRID_HEIGTH;
	sf::Event event;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	void load(char* const&);
	//On peut ajouter ici des éléments comme vector<vector> npcPositions...

public:

	std::shared_ptr<sf::RenderWindow> getWindow() const; //temp
	bool processEvents();
	void update(sf::Time);
	void render() const;

	GameWorld() = default;
	explicit GameWorld(char* const& xmlfile);
};