#include "GameApp.h"

GameApp::GameApp(std::string name)
{
	this->map->loadFromFile(name);
}

GameApp::~GameApp()
{
	delete this->map;
}

void GameApp::render(sf::RenderWindow* window)
{
	this->map->render(window,false);
}

void GameApp::update()
{
	this->map->update(1.f);
}
