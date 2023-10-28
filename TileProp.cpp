#include "TileProp.h"

TileProp::TileProp(bool collision,int type,sf::Vector2f poss,std::string name)
{

	this->clickedOnTextName = false;
	this->font.loadFromFile("res/Dosis-Light.ttf");

	this->shape.setFillColor(sf::Color(50, 50, 50, 255));
	this->shape.setSize(sf::Vector2f(400.f, 1080.f));
	this->shape.setPosition(1520.f, 0);

	this->shape1.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape1.setSize(sf::Vector2f(400.f, 2.f));
	this->shape1.setPosition(1520.f, 180.f);

	this->shape2.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape2.setSize(sf::Vector2f(400.f, 2.f));
	this->shape2.setPosition(1520.f, 250.f);

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

	this->inform.setFont(this->font);
	this->inform.setFillColor(sf::Color(255, 255, 255, 255));
	this->inform.setPosition(1520.f, 200.f);
	this->inform.setCharacterSize(20);
	this->inform.setString("Collision and type");

	this->collision = collision;

	this->name.setFont(this->font);
	this->name.setFillColor(sf::Color(255, 255, 255, 255));
	this->name.setPosition(1650, 100);
	this->name.setCharacterSize(30);
	this->name.setString(name);

	this->collisionText.setFont(this->font);
	this->collisionText.setFillColor(sf::Color(255, 255, 255, 255));
	this->collisionText.setPosition(1550,300.f);
	this->collisionText.setCharacterSize(30);
	this->collisionText.setString("Collision: ");

	this->setTextCollision.setFont(this->font);
	this->setTextCollision.setFillColor(sf::Color(255, 255, 255, 255));
	this->setTextCollision.setPosition(1650, 300.f);
	this->setTextCollision.setCharacterSize(30);
	
	if(collision)
	this->setTextCollision.setString("true");
	else
	this->setTextCollision.setString("false");

	this->type.setFont(this->font);
	this->type.setFillColor(sf::Color(255, 255, 255, 255));
	this->type.setPosition(1550, 350);
	this->type.setCharacterSize(30);
	this->type.setString("Position: ");

	this->postext.setFont(this->font);
	this->postext.setFillColor(sf::Color(255, 255, 255, 255));
	this->postext.setPosition(1650, 350.f);
	this->postext.setCharacterSize(30);
	this->postext.setString("X: " + std::to_string(int(poss.x)) + " Y: " +std::to_string(int(poss.y)));
	this->pos = poss;
}

TileProp::TileProp()
{
	this->clickedOnTextName = false;
	this->font.loadFromFile("res/Dosis-Light.ttf");

	this->shape.setFillColor(sf::Color(50, 50, 50, 255));
	this->shape.setSize(sf::Vector2f(400.f, 1080.f));
	this->shape.setPosition(1520.f, 0);

	this->shape1.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape1.setSize(sf::Vector2f(400.f, 2.f));
	this->shape1.setPosition(1520.f, 180.f);

	this->shape2.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape2.setSize(sf::Vector2f(400.f, 2.f));
	this->shape2.setPosition(1520.f, 250.f);

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

	this->inform.setFont(this->font);
	this->inform.setFillColor(sf::Color(255, 255, 255, 255));
	this->inform.setPosition(1520.f, 200.f);
	this->inform.setCharacterSize(20);
	this->inform.setString("Collision and type");

	this->collision = collision;

	this->name.setFont(this->font);
	this->name.setFillColor(sf::Color(255, 255, 255, 255));
	this->name.setPosition(1650, 100);
	this->name.setCharacterSize(30);
	this->name.setString("name");

	this->collisionText.setFont(this->font);
	this->collisionText.setFillColor(sf::Color(255, 255, 255, 255));
	this->collisionText.setPosition(1550, 300.f);
	this->collisionText.setCharacterSize(30);
	this->collisionText.setString("Collision: ");

	this->setTextCollision.setFont(this->font);
	this->setTextCollision.setFillColor(sf::Color(255, 255, 255, 255));
	this->setTextCollision.setPosition(1650, 300.f);
	this->setTextCollision.setCharacterSize(30);

	if (collision)
		this->setTextCollision.setString("true");
	else
		this->setTextCollision.setString("false");

	this->type.setFont(this->font);
	this->type.setFillColor(sf::Color(255, 255, 255, 255));
	this->type.setPosition(1550, 350);
	this->type.setCharacterSize(30);
	this->type.setString("Position: ");

	this->postext.setFont(this->font);
	this->postext.setFillColor(sf::Color(255, 255, 255, 255));
	this->postext.setPosition(1650, 350.f);
	this->postext.setCharacterSize(30);
	this->postext.setString(" ");
}

TileProp::TileProp(sf::Vector2f pos, sf::Vector2f scale, std::string name, float speed)
{
	this->collision = false;
	this->pos = pos;
	this->scale = scale;
	this->clickedOnTextName = false;
	this->font.loadFromFile("res/Dosis-Light.ttf");

	this->shape.setFillColor(sf::Color(50, 50, 50, 255));
	this->shape.setSize(sf::Vector2f(400.f, 1080.f));
	this->shape.setPosition(1520.f, 0);

	this->shape1.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape1.setSize(sf::Vector2f(400.f, 2.f));
	this->shape1.setPosition(1520.f, 180.f);

	this->shape2.setFillColor(sf::Color(0, 0, 0, 255));
	this->shape2.setSize(sf::Vector2f(400.f, 2.f));
	this->shape2.setPosition(1520.f, 250.f);

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

	this->inform.setFont(this->font);
	this->inform.setFillColor(sf::Color(255, 255, 255, 255));
	this->inform.setPosition(1520.f, 200.f);
	this->inform.setCharacterSize(20);
	this->inform.setString("Collision and type");

	this->collision = collision;

	this->name.setFont(this->font);
	this->name.setFillColor(sf::Color(255, 255, 255, 255));
	this->name.setPosition(1650, 100);
	this->name.setCharacterSize(30);
	this->name.setString(name);

	this->collisionText.setFont(this->font);
	this->collisionText.setFillColor(sf::Color(255, 255, 255, 255));
	this->collisionText.setPosition(1550, 300.f);
	this->collisionText.setCharacterSize(30);
	this->collisionText.setString("Scale: ");

	this->scaleText.setFont(this->font);
	this->scaleText.setFillColor(sf::Color(255, 255, 255, 255));
	this->scaleText.setPosition(1650, 300.f);
	this->scaleText.setCharacterSize(30);
	this->scaleText.setString("X: " + std::to_string(int(scale.x)) + " Y: "+std::to_string(int(scale.y)));

	this->setTextCollision.setFont(this->font);
	this->setTextCollision.setFillColor(sf::Color(255, 255, 255, 255));
	this->setTextCollision.setPosition(1550, 400.f);
	this->setTextCollision.setCharacterSize(30);
	this->setTextCollision.setString("Speed: ");

	this->speedText.setFont(this->font);
	this->speedText.setFillColor(sf::Color(255, 255, 255, 255));
	this->speedText.setPosition(1650, 400.f);
	this->speedText.setCharacterSize(30);
	this->speedText.setString(std::to_string(speed));

	this->type.setFont(this->font);
	this->type.setFillColor(sf::Color(255, 255, 255, 255));
	this->type.setPosition(1550, 350);
	this->type.setCharacterSize(30);
	this->type.setString("Position: ");

	this->postext.setFont(this->font);
	this->postext.setFillColor(sf::Color(255, 255, 255, 255));
	this->postext.setPosition(1650, 350.f);
	this->postext.setCharacterSize(30);
	this->postext.setString("X: " + std::to_string(int(pos.x)) + " Y: " +std::to_string(int(pos.y)));
}

TileProp::~TileProp()
{

}

void TileProp::update(bool isCan,sf::Vector2f mousePos)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&this->name.getGlobalBounds().contains(mousePos) && isCan)
	{
		this->clickedOnTextName = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->setTextCollision.getGlobalBounds().contains(mousePos) && isCan)
	{
		this->collision = !this->collision;

		if (this->collision)
			this->setTextCollision.setString("true");
		else
			this->setTextCollision.setString("false");
	}
}



void TileProp::render(sf::RenderWindow* window)
{
	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		this->clickedOnTextName = false;

		while (window->pollEvent(event))
		{
			switch (event.type) {
			
			case sf::Event::TextEntered:
				if (this->clickedOnTextName)
				{
					if (event.text.unicode != 8)
						a += (char)event.text.unicode;
					else
					{
						if (a.size() > 0)
							a.pop_back();
					}
				}
				break;
			}
		}

		if (a.size() > 0)
		{
			this->name.setString(a);
		}
	
	

	window->draw(this->shape);
	window->draw(this->shape1);
	window->draw(this->shape2);
	if (this->scaleText.getFont() != NULL)
	{
		window->draw(this->scaleText);
		window->draw(this->speedText);
	}

	window->draw(this->inform);
	window->draw(this->informShape);
	window->draw(this->nameShape);
	window->draw(this->informText);
	window->draw(this->name);
	window->draw(this->collisionText);
	window->draw(this->setTextCollision);
	window->draw(this->type);
	window->draw(this->postext);
}

