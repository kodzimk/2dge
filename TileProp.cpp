#include "TileProp.h"

TileProp::TileProp(bool collision, int type, sf::Vector2f poss,std::string name,sf::Font& font)
{

	this->font.loadFromFile("res/Dosis-Light.ttf");

	this->shape.setFillColor(sf::Color(100, 100, 100, 200));
	this->shape.setSize(sf::Vector2f(300.f, 1080.f));
	this->shape.setPosition(1620.f, 0);

	this->nameText.setFont(this->font);
	this->nameText.setFillColor(sf::Color(255,255,255,255));
	this->nameText.setPosition(1700, 100);
	this->nameText.setCharacterSize(30);
	this->nameText.setString("Name: ");

	this->name.setFont(this->font);
	this->name.setFillColor(sf::Color(255, 255, 255, 255));
	this->name.setPosition(1800, 100);
	this->name.setCharacterSize(30);
	this->name.setString(name);

	this->collisionText.setFont(this->font);
	this->collisionText.setFillColor(sf::Color(255, 255, 255, 255));
	this->collisionText.setPosition(1700,160);
	this->collisionText.setCharacterSize(30);
	this->collisionText.setString("Collision: ");

	this->setTextCollision.setFont(this->font);
	this->setTextCollision.setFillColor(sf::Color(255, 255, 255, 255));
	this->setTextCollision.setPosition(1810, 160);
	this->setTextCollision.setCharacterSize(30);
	
	if(collision)
	this->setTextCollision.setString("true");
	else
	this->setTextCollision.setString("false");

	this->type.setFont(this->font);
	this->type.setFillColor(sf::Color(255, 255, 255, 255));
	this->type.setPosition(1700, 200);
	this->type.setCharacterSize(30);
	this->type.setString("Position: ");

	this->postext.setFont(this->font);
	this->postext.setFillColor(sf::Color(255, 255, 255, 255));
	this->postext.setPosition(1700, 250);
	this->postext.setCharacterSize(30);
	this->postext.setString("X: " + std::to_string(int(poss.x)) + " Y: " +std::to_string(int(poss.y)));
}

TileProp::~TileProp()
{
}

void TileProp::update(bool isCan, Tile* tile)
{

}

void TileProp::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
	window->draw(this->nameText);
	window->draw(this->name);
	window->draw(this->collisionText);
	window->draw(this->setTextCollision);
	window->draw(this->type);
	window->draw(this->postext);
}
