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
	this->playText.setPosition(960, 0);
	this->playText.setCharacterSize(40);
	this->playText.setString("Play");

	this->saveGameText.setFont(this->font);
	this->saveGameText.setFillColor(sf::Color::White);
	this->saveGameText.setPosition(800, 0);
	this->saveGameText.setCharacterSize(40);
	this->saveGameText.setString("Save");

	this->tileMap->loadFromFile("game.txt");

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
	window->draw(this->saveGameText);

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
	if (this->saveGameText.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->tileMap->savetoFile("game.txt");
		this->saveToFile("project.txt","objects.txt");
	}

	if (this->prop != nullptr)
	{
		this->prop->update(isCan, mousePosView);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		this->selectedTile = nullptr;

	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int x = static_cast<int>(mousePosView.x / 64);
		int y = static_cast<int>(mousePosView.y / 64);
		for (size_t i = 0; i < this->tileMap->tiles.size(); i++)
		{
			int x1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().x / 64);
			int y1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().y / 64);
			if (x1 == x && y1 == y)
			{
				this->prop = this->props[i];
				return;
			}
		}
	}*/

	if (this->selectedTile != nullptr)
	{
		if (mousePosView.y < 680.f &&mousePosView.x < 1520.f && mousePosView.x > 400.f && 
			sf::Mouse::isButtonPressed(sf::Mouse::Left) && isCan&&!this->saveGameText.getGlobalBounds().contains(mousePosView))
		{
			
			int x = static_cast<int>(mousePosView.x/64);
			int y = static_cast<int>(mousePosView.y / 64);
			for (size_t i = 0; i < this->tileMap->tiles.size(); i++)
			{
				int x1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().x / 64);
				int y1 = static_cast<int>(this->tileMap->tiles[i]->tile.getPosition().y / 64);
				if (x1 == x && y1 == y)
				{
					this->prop = this->props[i];
					return;
				}
			}
			this->tileMap->tiles.push_back(new Tile(*this->selectedTile));
			this->tileMap->tiles[this->tileMap->tiles.size() - 1]->tile.setPosition(x*64,y*64);
			this->prop = new TileProp(this->selectedTile->collision, this->selectedTile->type, this->selectedTile->tile.getPosition(), "Object:" + std::to_string(objectCount));
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

void MapEditor::saveToFile(const std::string file,const std::string file2)
{
	std::ofstream file_name;

	file_name.open(file);

	if (file_name.is_open())
	{
		file_name << this->props.size()<<"\n";
		for (int i = 0; i < this->props.size(); i++)
		{
			int a = 0;
			if (this->props[i]->collision)
				a = 1;
			else
				a = 0;

			std::string name = this->props[i]->name.getString();
			std::string x = std::to_string(this->props[i]->pos.x);
			std::string y = std::to_string(this->props[i]->pos.y);

			file_name << a << " " << name << " " << x << " " << y <<" ";
				
		}

	}
	file_name.close();

	file_name.open(file2);

	if (file_name.is_open())
	{
		file_name << this->objectLists->namesofobjects.size() << "\n";

		for (int i = 0; i < this->objectLists->namesofobjects.size(); i++)
		{
			std::string name = this->objectLists->namesofobjects[i].getString();
			file_name << name << " ";
		}
	}
	file_name.close();
}

void MapEditor::loadFromFile(const std::string file,const std::string file2)
{
	std::ifstream file_name;

	file_name.open(file);

	if (file_name.is_open())
	{
		int size = 0;
		std::string name = "";
		bool collision = false;
		float x, y;

		file_name >> size;

		if (!this->props.empty())
		{
			for (int i = 0; i < this->props.size(); i++)
			{
				if (this->props[i] != nullptr)
					delete this->props[i];
			}
			this->props.clear();
		}

		this->props.resize(size);


		int index = 0;
		while (file_name >> collision >> name >> x >> y)
		{
			this->props[index] = new TileProp(collision, 0, sf::Vector2f(x, y), name);
			index++;
		}

	}
	file_name.close();

	
	file_name.open(file2);

	if (file_name.is_open())
	{
		int size = 0;
		std::string name = "";
		file_name >> size;
		if (!this->objectLists->namesofobjects.empty())
		{
			this->objectLists->namesofobjects.clear();
		}


		int index = 0;
		while (file_name >> name)
		{
			sf::Text text;
			text.setFont(this->font);
			text.setFillColor(sf::Color(255, 255, 255, 255));
			text.setPosition(50, 25 * (index + 1));
			text.setCharacterSize(20);
			text.setString(name);
			this->objectLists->namesofobjects.push_back(text);
			index++;
		}
	}
	file_name.close();
}
