#include "GameApp.h"

GameApp::GameApp()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Havoc");
	this->map = new TileMap();
	this->map->loadFromFile("game.txt", "upTile.txt");
	this->player = new Player();
	this->keyTime = 0.f;
	this->dt = 0.f;
	this->keyTimeMax = 10.f;
}

GameApp::~GameApp()
{
	delete this->player;
	delete this->map;
	delete this->window;
}

void GameApp::render()
{
		window->clear();
		this->map->renderGame(window);
		this->player->render(window);
		window->display();
}

void GameApp::update()
{
	this->player->update(this->dt,this->getKeyTime(),this->map->tiles);
	this->map->update(1.f);
}

void GameApp::updateKeyTime()
{
	this->dt = this->clock.restart().asSeconds();

	if (this->keyTime < this->keyTimeMax)
		this->keyTime += 100.f * this->dt;
}

const bool GameApp::getKeyTime()
{
	if (this->keyTime > this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}

	return false;
}
