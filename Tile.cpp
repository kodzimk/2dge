#include "Tile.h"

Tile::Tile(sf::Sprite spite)
{
	this->tile = spite;
}

Tile::~Tile()
{

}

void Tile::render(sf::RenderWindow* window)
{
	window->draw(this->tile);
}
