#include "TileProp.h"

TileProp::TileProp(bool collision, int type, sf::Vector2f poss,std::string name)
{
	this->font.loadFromFile("res/Dosis-Light.ttf");

	this->shape.setFillColor(sf::Color(50, 50, 50, 255));
	this->shape.setSize(sf::Vector2f(400.f, 1080.f));
	this->shape.setPosition(1520.f, 0);

	this->informShape.setFillColor(sf::Color(20, 20, 20, 255));
	this->informShape.setSize(sf::Vector2f(100.f, 50.f));
	this->informShape.setPosition(1520.f, 0);


	this->nameShape.setFillColor(sf::Color(20, 20, 20, 255));
	this->nameShape.setSize(sf::Vector2f(200.f, 50.f));
	this->nameShape.setPosition(1600.f, 100);

	this->informText.setFont(this->font);
	this->informText.setFillColor(sf::Color(255, 255, 255, 255));
	this->informText.setPosition(1530, 10);
	this->informText.setCharacterSize(20);
	this->informText.setString("Inspector");

	this->name.setFont(this->font);
	this->name.setFillColor(sf::Color(255, 255, 255, 255));
	this->name.setPosition(1650, 100);
	this->name.setCharacterSize(30);
	this->name.setString(name);

	this->collisionText.setFont(this->font);
	this->collisionText.setFillColor(sf::Color(255, 255, 255, 255));
	this->collisionText.setPosition(1650,160);
	this->collisionText.setCharacterSize(30);
	this->collisionText.setString("Collision: ");

	this->setTextCollision.setFont(this->font);
	this->setTextCollision.setFillColor(sf::Color(255, 255, 255, 255));
	this->setTextCollision.setPosition(1700, 160);
	this->setTextCollision.setCharacterSize(30);
	
	if(collision)
	this->setTextCollision.setString("true");
	else
	this->setTextCollision.setString("false");

	this->type.setFont(this->font);
	this->type.setFillColor(sf::Color(255, 255, 255, 255));
	this->type.setPosition(1650, 200);
	this->type.setCharacterSize(30);
	this->type.setString("Position: ");

	this->postext.setFont(this->font);
	this->postext.setFillColor(sf::Color(255, 255, 255, 255));
	this->postext.setPosition(1650, 250);
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
	sf::Event event;


	while (window->pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::TextEntered:
			std::cout << (char)event.text.unicode << std::endl;
			a += (char)event.text.unicode;
			break;
			
		}
	}

	if(a.size() > 1)
	this->name.setString(a);
	

	window->draw(this->shape);
	window->draw(this->informShape);
	window->draw(this->nameShape);
	window->draw(this->informText);
	window->draw(this->name);
	window->draw(this->collisionText);
	window->draw(this->setTextCollision);
	window->draw(this->type);
	window->draw(this->postext);
}
