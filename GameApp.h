#ifndef GAMEAPP_H
#define GAMEAPP_H

#include"includer.h"
#include"TileMap.h"

class GameApp
{
public:
	sf::RenderWindow* window;
	TileMap* map;

	GameApp(std::string name);
	~GameApp();

	void render();
	void update();
};
#endif // !GAMEAPP_H


