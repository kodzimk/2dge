#ifndef  PLAYER_H
#define PLAYER_H

#include"includer.h"
#include"Tile.h"


class Player
{
public:
	sf::Texture texture;
	sf::Sprite player;
	sf::Vector2f scale;
	float animations;
	float speed;

	Player();
	~Player();

	void update(const float& dt,bool isCan);
	void render(sf::RenderWindow* window);
	void updateAnimations(bool isCan, const float& dt);
	bool isCanMove(std::vector<Tile*> tiles);
}; 
#endif // ! PLAYER_H

