#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include"includer.h"
#include"MapEditor.h"

class GameEngine
{
public:
	sf::RenderWindow* window;
	MapEditor* mapEditor;
	sf::Clock clock;
	float dt;
	float keytime;
	sf::Vector2f mousePosView;
	float keytimeMax;


	GameEngine();
	~GameEngine();

	void render();
	void update();
	void updateKeyTime();
	const bool getKeyTime();
};

#endif

