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
}

MapEditor::~MapEditor()
{
	delete this->tileMap;
	delete this->selectedTile;
}

void MapEditor::render(sf::RenderWindow* window)
{
	window->draw(this->backgroundShape);

	this->tileMap->render(window,this->showFirst);
	if (this->selectedTile != nullptr)
	{
	   this->selectedTile->render(window);
	}
	if(this->prop != nullptr)
	    this->prop->render(window);
}

void MapEditor::update(const float& dt, const sf::Vector2f mousePosView,bool isCan)
{
	this->tileMap->update(dt);
	this->updateInputs(mousePosView,isCan);
}

void MapEditor::updateInputs(const sf::Vector2f mousePosView,bool isCan)
{
	if (this->selectedTile != nullptr)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isCan)
		{
			this->tileMap->tiles.push_back(new Tile(*this->selectedTile));
			int x = static_cast<int>(mousePosView.x/64);
			int y = static_cast<int>(mousePosView.y / 64);
			this->tileMap->tiles[this->tileMap->tiles.size() - 1]->tile.setPosition(x*64,y*64);
			this->prop = new TileProp(this->selectedTile->collision, this->selectedTile->type, this->selectedTile->tile.getPosition(), "Object: " + std::to_string(objectCount));
			props.push_back(this->prop);
			objectCount++;
	    }
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		int x = static_cast<int>(mousePosView.x / 64);
		int y = static_cast<int>(mousePosView.y / 64);
		for (int i = 0; i < this->tileMap->tiles.size();i++)
		{
			if (this->tileMap->tiles[i] != nullptr)
			{
				int x1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().x / 64);
				int y1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().y / 64);
				if (x1 == x && y1 == y)
				{
					this->tileMap->tiles[i] = nullptr;
				}
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
