#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include"includer.h"
#include"TileMap.h"
#include"TileProp.h"
#include"GameObjects.h"

class MapEditor
{
public:
	sf::Font font;
	TileProp* prop;
	TileMap* tileMap;
	sf::RectangleShape backgroundShape;
	bool showFirst;
	Tile* selectedTile;
	int objectCount;
	std::vector<TileProp*> props;
	GameObjects* objectLists;
	sf::Text playText;
	sf::Text saveGameText;
	sf::Text tilesSelect;
	sf::Text playerSelect;
	bool showTiles, showSprites;

	MapEditor();
	~MapEditor();

	void render(sf::RenderWindow* window);
	void update(const float& dt, const sf::Vector2f mousePosView,bool isCan);
	void updateInputs(const sf::Vector2f mousePosView,bool isCan);
	bool startPlay(sf::Vector2f mouse);
	void saveToFile(const std::string file, const std::string file2);
	void loadFromFile(const std::string file, const std::string file2);
	void updateTextInputs(bool isCan, sf::Vector2f mousePosView);
};
#endif
