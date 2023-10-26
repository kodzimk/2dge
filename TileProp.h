#ifndef TILEPROP_H
#define TILEPROP_H

#include "includer.h"
#include"Tile.h"


class TileProp
{
public:
	sf::RectangleShape shape;
	sf::RectangleShape informShape;
	sf::Text informText;
	sf::Font font;
	sf::RectangleShape nameShape;
	sf::Text name;
	sf::Text collisionText;
	sf::Text setTextCollision;
	sf::Text postext;
	bool clickedOnTextName;
	std::string a;
	sf::Text type;

	TileProp(bool collision,int type,sf::Vector2f pos,std::string name);
	~TileProp();

	void update(bool isCan,Tile* tile);
	void render(sf::RenderWindow* window);
};
#endif 

