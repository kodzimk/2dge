#include "MapEditor.h"

MapEditor::MapEditor()
{
	this->font.loadFromFile("res/Dosis-Light.ttf");
	this->tileMap = new TileMap();

    this->backgroundShape.setFillColor(sf::Color(100,100, 100, 200));
	this->backgroundShape.setSize(sf::Vector2f(1200.f, 384.f));
	this->backgroundShape.setPosition(320.f, 700.f);
	this->showFirst = true;
	this->selectedTile = nullptr;
	this->objectCount = 0;
	this->objectLists = new GameObjects();

	this->playText.setFont(this->font);
	this->playText.setFillColor(sf::Color::White);
	this->playText.setPosition(960, 30);
	this->playText.setCharacterSize(40);
	this->playText.setString("Play");
}

MapEditor::~MapEditor()
{
	delete this->tileMap;
	delete this->selectedTile;
}

void MapEditor::render(sf::RenderWindow* window)
{
	window->draw(this->backgroundShape);
	window->draw(this->playText);

	this->tileMap->render(window,this->showFirst);

	if (this->selectedTile != nullptr)
	{
	   this->selectedTile->render(window);
	}

	if(this->prop != nullptr)
	    this->prop->render(window);

	if (this->props.size() > 0)
		this->objectLists->render(window);


}

void MapEditor::update(const float& dt, const sf::Vector2f mousePosView,bool isCan)
{
	this->tileMap->update(dt);
	this->updateInputs(mousePosView,isCan);

	if (this->props.size() > 0)
	{
		int a = this->objectLists->update(isCan, mousePosView,this->props);
		if (a < this->props.size())
		{
			this->prop = this->props[a];
		}
	}
}

void MapEditor::updateInputs(const sf::Vector2f mousePosView,bool isCan)
{

	if (this->prop != nullptr)
	{
		this->prop->update(isCan, mousePosView);
	}

	if (this->selectedTile != nullptr)
	{
		if (mousePosView.y < 680.f &&mousePosView.x < 1520.f && mousePosView.x > 400.f && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isCan)
		{
			this->tileMap->tiles.push_back(new Tile(*this->selectedTile));
			int x = static_cast<int>(mousePosView.x/64);
			int y = static_cast<int>(mousePosView.y / 64);
			this->tileMap->tiles[this->tileMap->tiles.size() - 1]->tile.setPosition(x*64,y*64);
			this->prop = new TileProp(this->selectedTile->collision, this->selectedTile->type, this->selectedTile->tile.getPosition(), "Object: " + std::to_string(objectCount));
			props.push_back(this->prop);
			sf::Text text;
			
			text.setFont(this->font);
			text.setFillColor(sf::Color(255, 255, 255, 255));
			text.setPosition(50,25 * (objectCount +1));
			text.setCharacterSize(20);
			text.setString("Object: " + std::to_string(objectCount));

			this->objectLists->namesofobjects.push_back(text);
			objectCount++;
	    }
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		int index = 0;
		int x = static_cast<int>(mousePosView.x / 64);
		int y = static_cast<int>(mousePosView.y / 64);
		for (auto i = this->tileMap->tiles.begin();i != this->tileMap->tiles.end();i++,index++)
		{
			if ((*i) != nullptr)
			{
				int x1 = static_cast<int>((*i)->tile.getPosition().x / 64);
				int y1 = static_cast<int>((*i)->tile.getPosition().y / 64);
				if (x1 == x && y1 == y)
				{
					this->tileMap->tiles.erase(i);
					objectCount--;
					break;
				}
			}
		}

		int a = 0;
		for (auto iter = this->props.begin(); iter != this->props.end(); iter++,a++)
		{
			if (a == index)
			{
				this->props.erase(iter);
				break;
			}
		}

		a = 0;
		for (auto iter = this->objectLists->namesofobjects.begin(); iter != this->objectLists->namesofobjects.end(); iter++, a++)
		{
			if (a == index)
			{
				this->objectLists->namesofobjects.erase(iter);
				break;
			}
		}

	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->showFirst = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->showFirst = true;

	if (this->showFirst)
	{
		for (size_t i = 0; i < this->tileMap->selectSprite.size(); i++)
		{
			if (this->tileMap->selectSprite[i].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->selectedTile = new Tile(this->tileMap->selectSprite[i]);	
			}
		}
	}
	else
	{
		for (size_t i = 0; i < this->tileMap->selectSprite2.size(); i++)
		{
			if (this->tileMap->selectSprite2[i].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->selectedTile = new Tile(this->tileMap->selectSprite2[i]);
		
			}
		}
	}

	if (this->selectedTile != nullptr)
	{	
		this->selectedTile->tile.setPosition(mousePosView);
	}
}

bool MapEditor::startPlay(sf::Vector2f mouse)
{
	if (this->playText.getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	return false;
}
