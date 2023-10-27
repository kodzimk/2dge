#include "GameEngine.h"

GameEngine::GameEngine()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Havoc");
	this->mapEditor = new MapEditor();
	this->dt = 0.f;
	this->keytime = 0.f;
	this->keytimeMax = 10.f;
	this->mousePosView = sf::Vector2f();
	this->path = "game.txt";
}

GameEngine::~GameEngine()
{
	delete this->mapEditor;
}

void GameEngine::render()
{
	window->clear();
	this->mapEditor->render(window);
	window->display();
}

void GameEngine::update()
{
		this->updateKeyTime();
		this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));
		this->mapEditor->update(1.f, this->mousePosView, this->getKeyTime());
}

void GameEngine::updateKeyTime()
{
	this->dt = this->clock.restart().asSeconds();

	if (this->keytime < this->keytimeMax)
		this->keytime += 100.f * this->dt;
}

const bool GameEngine::getKeyTime()
{
	if (this->keytime > this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}

	return false;
}

bool GameEngine::startGame()
{
	return this->mapEditor->startPlay(this->mousePosView);
}

