#ifndef TILE_H
#define TILE_H

#include"includer.h"

class Tile
{
public:
	sf::Sprite tile;
	bool collision;
	int type;


	Tile(sf::Sprite sp);
	Tile();
	~Tile();

	void render(sf::RenderWindow* window);
};


#endif

