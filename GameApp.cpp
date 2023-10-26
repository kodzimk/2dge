#include "GameApp.h"

GameApp::GameApp(std::string name)
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Havoc");
	this->map->loadFromFile(name);
}

GameApp::~GameApp()
{
	delete this->map;
	delete this->window;
}

void GameApp::render()
{
	while (true)
	{
		window->clear();
		this->map->render(window, false);
		window->display();
	}
}

void GameApp::update()
{
	this->map->update(1.f);
}
