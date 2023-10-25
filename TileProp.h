#ifndef TILEPROP_H
#define TILEPROP_H

#include "includer.h"
#include"Tile.h"


class TileProp
{
public:
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text nameText;
	sf::Text name;
	sf::Text collisionText;
	sf::Text setTextCollision;
	sf::Text postext;
	sf::Text type;

	TileProp(bool collision,int type,sf::Vector2f pos,std::string name, sf::Font& font);
	~TileProp();

	void update(bool isCan,Tile* tile);
	void render(sf::RenderWindow* window);
};
#endif 

