#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include"includer.h"
#include"MapEditor.h"
#include"GameApp.h"

class GameEngine
{
public:
	sf::RenderWindow* window;
	std::string path;
	std::string filePath;
	MapEditor* mapEditor;
	sf::Clock clock;
	float dt;
	float keytime;
	sf::Vector2f mousePosView;
	float keytimeMax;
	GameApp* game;


	GameEngine();
	~GameEngine();

	void render();
	void update();
	void updateKeyTime();
	const bool getKeyTime();
	
};

#endif

