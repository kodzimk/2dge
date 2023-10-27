#ifndef TILEMAP_H
#define TILEMAP_H

#include"includer.h"
#include"Tile.h"


class TileMap
{
public:
	std::vector<Tile*> tiles;
	sf::Texture tileSheet1;
	std::vector<sf::Sprite>selectSprite;
	std::vector<sf::Sprite>selectSprite2;
	std::vector<Tile*> upTiles;
	sf::Sprite sp;
	

	TileMap();
	~TileMap();

	void update(const float& dt);
	void render(sf::RenderWindow* window,bool showFirst,bool showTextures);
	void savetoFile(std::string name, std::string path2);
	void loadFromFile(const std::string name, std::string path2);
	void renderGame(sf::RenderWindow* window);
};


#endif // !1

