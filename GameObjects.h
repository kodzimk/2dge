#ifndef GAMEOBJECTS_H
#define GAMEOBJECT_H

#include"TileProp.h"
#include"includer.h"

class GameObjects
{
public:
	sf::RectangleShape shape;
	std::vector<sf::Text> namesofobjects;


	GameObjects();
	~GameObjects();

	void render(sf::RenderWindow* window);
	int update(bool isCan,sf::Vector2f pos, std::vector<TileProp*> prop);
};
#endif // !1

