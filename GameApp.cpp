#include "GameApp.h"

GameApp::GameApp()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Havoc");
	this->map = new TileMap();
	this->map->loadFromFile("game.txt","upTile.txt");
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
		this->map->renderGame(window);
		window->display();
	}
}

void GameApp::update()
{
	this->map->update(1.f);
}
