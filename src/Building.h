#pragma once
#include "InterfaceBuilding.h"
#include <string>

class Building : InterfaceBuilding {
private:
	int level;
	int x;
	int y;
	//Sprite image;// à ajouter quand on aura la classe Sprite
public:
	Building(int x, int y, std::string image);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getLevel();
	void setLevel(int l);
	void render(sf::RenderTarget* target);
};