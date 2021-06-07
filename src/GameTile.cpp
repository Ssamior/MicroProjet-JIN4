#include "GameTile.h"

GameTile::GameTile(std::string const& textureName, std::unique_ptr<Building> building) :
    building(std::move(building))
{
    if (!setUpSprite(textureName)) {
        return;
    }
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