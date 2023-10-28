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
	sf::RectangleShape shape1;
	sf::RectangleShape shape2;
	sf::Text inform;
	sf::Text name;
	sf::Text collisionText;
	sf::Text scaleText;
	sf::Text speedText;
	sf::Text setTextCollision;
	sf::Text postext;
	bool collision;
	bool clickedOnTextName;
	std::string a;
	sf::Vector2f pos;
	sf::Text type;
	sf::Vector2f scale;

	TileProp(bool collision,int type,sf::Vector2f pos,std::string name);
	TileProp();
	TileProp(sf::Vector2f pos,sf::Vector2f scale,std::string name,float speed);
	~TileProp();


	void update(bool isCan,sf::Vector2f ops);
	void render(sf::RenderWindow* window);

};
#endif 

