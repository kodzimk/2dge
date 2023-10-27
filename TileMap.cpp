#include "TileMap.h"

TileMap::TileMap()
{
	this->tileSheet1.loadFromFile("res/Textures/TILESHEET1.png");

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
	sp.setTexture(this->tileSheet1);

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
}

TileMap::~TileMap()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		    delete this->tiles[i];
	}
	for (int i = 0; i < upTiles.size(); i++)
	{
		delete this->upTiles[i];
	}
}

void TileMap::update(const float& dt)
{
}

void TileMap::render(sf::RenderWindow* window,bool showFirst, bool showTextures)
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
			if (this->tiles[i] != nullptr)
			{
				this->tiles[i]->render(window);
			}
	}
	for (size_t i = 0; i < this->upTiles.size(); i++)
	{
		if (this->upTiles[i] != nullptr)
		{
			this->upTiles[i]->render(window);
		}
	}

	if (showTextures)
	{
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
}

std::string btos(bool x)
{
	if (x)
		return "1";
	return "0";
}

void TileMap::savetoFile(std::string path,std::string path2)
{
	std::ofstream file;
	file.open(path);

	if (file.is_open())
	{

		file << this->tiles.size()<<"\n";

		for (size_t i = 0; i < this->tiles.size(); i++)
		{
			if (this->tiles[i] != nullptr)
			{
				std::string left = std::to_string(this->tiles[i]->tile.getTextureRect().left);
				std::string top = std::to_string(this->tiles[i]->tile.getTextureRect().top);
				std::string collision = btos(this->tiles[i]->collision);

				file << this->tiles[i]->tile.getPosition().x << " " << this->tiles[i]->tile.getPosition().y<<" "<<left<<" "<<top<<" "<<collision<<" ";
			}

		}
	}
	else
	{
		std::cout << "Prectedgsc" << std::endl;
	}

	file.close();

	file.open(path2);

	if (file.is_open())
	{
		file << this->upTiles.size() << "\n";

		for (size_t i = 0; i < this->upTiles.size(); i++)
		{
			if (this->upTiles[i] != nullptr)
			{
				std::string left = std::to_string(this->upTiles[i]->tile.getTextureRect().left);
				std::string top = std::to_string(this->upTiles[i]->tile.getTextureRect().top);
				std::string collision = btos(this->upTiles[i]->collision);

				file << this->upTiles[i]->tile.getPosition().x << " " << this->upTiles[i]->tile.getPosition().y << " " << left << " " << top << " " << collision << " ";
			}

		}
	}
	file.close();
}

void TileMap::loadFromFile(const std::string path, std::string path2)
{
	std::ifstream file;

	file.open(path);


	if (file.is_open())
	{

		int size = 0;
		int left = 0;
		int top = 0;
		float x, y;
		bool collision = false;
		file >> size;

		if (!this->tiles.empty())
		{
			for (int i = 0; i < this->tiles.size(); i++)
			{
				if (this->tiles[i] != nullptr)
					delete this->tiles[i];
			}
			this->tiles.clear();
		}


		this->tiles.resize(size,new Tile());

		for (size_t i = 0; i < size; i++)
		{
			this->tiles[i] = new Tile();
		}
         
		int i = 0;
		while(file >> x >> y >> left >> top>>collision )
		{
			this->tiles[i]->tile.setTexture(this->tileSheet1);
			this->tiles[i]->tile.setTextureRect(sf::IntRect(left, top, 64, 64));
			this->tiles[i]->tile.setPosition(x, y);
			this->tiles[i]->collision = collision;
			i++;
		}
	}
	else
	{
		std::cout << "kakakkakakakak" << std::endl;
	}

	file.close();

	file.open(path2);

	if (file.is_open())
	{
		int size = 0;
		int left = 0;
		int top = 0;
		float x, y;
		bool collision = false;
		file >> size;

		if (!this->upTiles.empty())
		{
			for (int i = 0; i < this->upTiles.size(); i++)
			{
				if (this->tiles[i] != nullptr)
					delete this->upTiles[i];
			}
			this->upTiles.clear();
		}


		this->upTiles.resize(size, new Tile());

		for (size_t i = 0; i < size; i++)
		{
			this->upTiles[i] = new Tile();
		}

		int i = 0;
		while (file >> x >> y >> left >> top >> collision)
		{
			this->upTiles[i]->tile.setTexture(this->tileSheet1);
			this->upTiles[i]->tile.setTextureRect(sf::IntRect(left, top, 64, 64));
			this->upTiles[i]->tile.setPosition(x, y);
			this->upTiles[i]->collision = collision;
			i++;
		}
	}
	file.close();
}

void TileMap::renderGame(sf::RenderWindow* window)
{
	for (int i = 0; i < this->tiles.size(); i++)
	{
		if (this->tiles[i] != nullptr)
		{
			this->tiles[i]->render(window);
		}
	}

}
