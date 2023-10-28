#ifndef GAMEAPP_H
#define GAMEAPP_H

#include"includer.h"
#include"Player.h"
#include"TileMap.h"

class GameApp
{
public:
	sf::RenderWindow* window;
	TileMap* map;
	Player* player;
	float dt;
	float keyTime;
	float keyTimeMax;
	sf::Clock clock;

	GameApp();
	~GameApp();

	void render();
	void update();
	void updateKeyTime();
	
	const bool getKeyTime();
};
#endif // !GAMEAPP_H


