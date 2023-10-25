#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include"includer.h"
#include"TileMap.h"


class MapEditor
{
public:
	TileMap* tileMap;
	sf::RectangleShape backgroundShape;
	bool showFirst;
	Tile* selectedTile;


	MapEditor();
	~MapEditor();

	void render(sf::RenderWindow* window);
	void update(const float& dt, const sf::Vector2f mousePosView,bool isCan);
	void updateInputs(const sf::Vector2f mousePosView,bool isCan);
};
#endif