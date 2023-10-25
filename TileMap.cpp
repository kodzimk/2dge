#include "TileMap.h"

TileMap::TileMap()
{
	this->tileSheet1.loadFromFile("res/Textures/TILESHEET1.png");
	//this->tiles.resize(100); 
	
    sf::Sprite sprite;
	for (size_t i = 0; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			sprite.setTexture(this->tileSheet1);
			sprite.setTextureRect(sf::IntRect(64 * i, 64 * j, 64, 64));
			sprite.setPosition(j * 64 + 600.f, i * 64+700.f);
			this->selectSprite.push_back(sprite);
		}
	}

	for (size_t i = 6; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			sprite.setTexture(this->tileSheet1);
			sprite.setTextureRect(sf::IntRect(64 * i, 64 * j, 64, 64));
			sprite.setPosition(j* 64 + 600.f, (i - 6) * 64 + 700.f);
			this->selectSprite2.push_back(sprite);
		}
	}
	

	//for (int i = 0; i < this->tiles.size(); i++)
	//{
	//	this->tiles[i].resize(100);
	//	for (int j = 0; j < this->tiles[i].size(); j++)
	//	{
	//		this->tiles[i][j] = nullptr;
	//	}
	//}
}

TileMap::~TileMap()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		    delete this->tiles[i];
	}
}

void TileMap::update(const float& dt)
{
}

void TileMap::render(sf::RenderWindow* window,bool showFirst)
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
			if (this->tiles[i] != nullptr)
			{
				this->tiles[i]->render(window);
			}
	}

	if (showFirst)
	{
		for (int i = 0; i < this->selectSprite.size(); i++)
		{
			window->draw(this->selectSprite[i]);

		}
	}
	else
	{

		for (int i = 0; i < this->selectSprite2.size(); i++)
		{
			window->draw(this->selectSprite2[i]);
		}
	}
}
