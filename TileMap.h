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
	sf::Sprite sp;

	TileMap();
	~TileMap();

	void update(const float& dt);
	void render(sf::RenderWindow* window,bool showFirst);
	void savetoFile(std::string name);
	void loadFromFile(const std::string name);
	void renderGame(sf::RenderWindow* window);
};


#endif // !1

