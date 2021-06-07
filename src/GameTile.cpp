#include "GameTile.h"
#include "InterfaceBuilding.h"

GameTile::GameTile(char* const& textureName, std::unique_ptr<InterfaceBuilding> building, int x, int y) :
    building(std::move(building))
{
    if (!setUpSprite(textureName, x, y)) {
        return;
    }
}

bool GameTile::setUpSprite(char* const& textureName, int x, int y) {
    if (!texture.loadFromFile(textureName, sf::IntRect(0, 0, 50, 50)))
    {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition((float)x, (float)y);
    return true;
}

void GameTile::render(sf::RenderWindow& window) const {
    window.draw(sprite);
}