#include "GameTile.h"

GameTile::GameTile(std::string const& textureName, float x, float y) 
{
    if (!setUpSprite(textureName)) {
        return;
    }
	position = sf::Vector2f(x, y);
}

bool GameTile::setUpSprite(std::string const& textureName) {
    if (!texture.loadFromFile(textureName, sf::IntRect(0, 0, 50, 50)))
    {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    return true;
}