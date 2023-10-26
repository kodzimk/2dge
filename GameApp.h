#ifndef GAMEAPP_H
#define GAMEAPP_H

#include"includer.h"
#include"TileMap.h"

class GameApp
{
public:
	TileMap* map;

	GameApp(std::string name);
	~GameApp();

	void render(sf::RenderWindow* window);
	void update();
};
#endif // !GAMEAPP_H


