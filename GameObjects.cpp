#include "GameObjects.h"

GameObjects::GameObjects()
{
	this->shape.setFillColor(sf::Color(50, 50, 50, 255));
	this->shape.setSize(sf::Vector2f(400.f, 1080.f));
	this->shape.setPosition(0, 0);
}

GameObjects::~GameObjects()
{

}

void GameObjects::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
	for (int i = 0; i < this->namesofobjects.size(); i++)
	{
		window->draw(this->namesofobjects.at(i));
	}
}

int GameObjects::update(bool isCan,sf::Vector2f mousePos,std::vector<TileProp*> prop)
{

	for (int i = 0; i < this->namesofobjects.size(); i++)
	{
		this->namesofobjects[i].setString(prop[i]->name.getString());
		if (this->namesofobjects[i].getGlobalBounds().contains(mousePos) && isCan && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			return i;
		}
	}
	return -1;
}
