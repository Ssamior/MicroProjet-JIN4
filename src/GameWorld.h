#pragma once
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"
#include <vector>
#include "InterfaceBuilding.h"
#include "BuildingDecorator.h"
#include "Inventory.h"
#include "Mine.h"
#include "Consumer.h"

//Window parameters
constexpr const char* title = "My window";
constexpr int WIDTH = 1600;
constexpr int HEIGHT = 900;
constexpr int GRID_WIDTH = 32;
constexpr int GRID_HEIGHT = 18;

//Resources
constexpr int POLLUTION_MAX = 500;
constexpr char* backgroundStr = "../../resources/dirtFloor.png";
constexpr char* supprButtonStr = "../../resources/supprButton.png";
constexpr char* tree0Str = "../../resources/tree0.png";
constexpr char* tree1Str = "../../resources/tree1.png";
constexpr char* mineStr = "../../resources/mine.png";
constexpr char* ironMineStr = "../../resources/ironMine.png";
constexpr char* coalMineStr = "../../resources/coalMine.png";
constexpr char* stoneMineStr = "../../resources/mine.png";
constexpr char* woodMineStr = "../../resources/mine.png";



class UIElement {
public:
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isActive = false;

	UIElement(std::string const& name, sf::Texture const& texture, sf::Sprite const& sprite) :
		name(name), texture(texture), sprite(sprite) {
	}
};

class GameWorld {
	
private:
	std::shared_ptr<sf::RenderWindow> window;
	
	Inventory inventory;
	bool showInventory = false;
	bool showUI = true;
	bool isGlobalUIActive = false;
	bool isLost = false;
	int gridWidth = GRID_WIDTH;
	int gridHeight = GRID_HEIGHT;
	sf::Event event;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	std::vector<std::shared_ptr<InterfaceBuilding>> buildings;
	std::vector<UIElement> UI = { 
		UIElement("supprButton",sf::Texture(),sf::Sprite()),
		UIElement("ironMineButton",sf::Texture(),sf::Sprite()),
		UIElement("coalMineButton",sf::Texture(),sf::Sprite()),
		UIElement("stoneMineButton",sf::Texture(),sf::Sprite()),
		UIElement("woodMineButton",sf::Texture(),sf::Sprite())
	};

	//fileMode allow the possibility to load a GameWorld from file (true) or string (false, used for tests)
	void load(char* const& string, bool fileMode = true);
	void handleClick(int x, int y);

public:

	Inventory getInventory() const;
	
	bool processEvents();
	void update(sf::Time);
	void render() const;

	GameWorld() = default;
	explicit GameWorld(char* const& xmlfile, bool fileMode = true);
};