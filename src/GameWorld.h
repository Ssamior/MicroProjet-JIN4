#pragma once
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"
#include <vector>
#include "InterfaceBuilding.h"
#include "Inventory.h"

//Window parameters
constexpr const char* title = "My window";
constexpr int WIDTH = 1600;
constexpr int HEIGTH = 900;
constexpr int GRID_WIDTH = 32;
constexpr int GRID_HEIGTH = 18;

//Resources
constexpr char* backgroundStr = "../../resources/dirtFloor.png";



class GameWorld {
	
private:
	std::shared_ptr<sf::RenderWindow> window;
	
	Inventory inventory;
	int gridWidth = GRID_WIDTH;
	int gridHeight = GRID_HEIGTH;
	sf::Event event;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	std::vector<std::unique_ptr<InterfaceBuilding>> buildings;

	//fileMode allow the possibility to load a GameWorld from file (true) or string (false, used for tests)
	void load(char* const& string, bool fileMode = true);
	void handleBuildingClick(BuildingDecorator building);

public:

	Inventory getInventory() const;
	
	bool processEvents();
	void update(sf::Time);
	void render() const;

	GameWorld() = default;
	explicit GameWorld(char* const& xmlfile, bool fileMode = true);
};