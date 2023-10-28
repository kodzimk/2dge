#include "Player.h"

Player::Player()
{
    this->texture.loadFromFile("res/Textures/PLAYER_SHEET2.png");
    this->player.setTexture(this->texture);
    this->player.setTextureRect(sf::IntRect(0, 0, 64, 64));

    this->player.setPosition(400.f, 800.f);
    this->speed = 0.5f;
    this->scale = this->player.getScale();
    this->animations = 0;

}

Player::~Player()
{

}

void Player::update(const float& dt, bool isCan)
{
	this->updateAnimations(isCan, dt);
}

void Player::render(sf::RenderWindow* window)
{
    window->draw(this->player);
}

void Player::updateAnimations(bool isCan,const float& dt)
{
	bool isIdle = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isCan)
	{
		if (this->animations < 12)
			this->animations = 12;
		isIdle = false;
		this->animations += dt * 10.f;
		if (animations >= 15)animations -= 3;
		this->player.setTextureRect(sf::IntRect(64 * int(animations), 64, 64, 64));
		this->player.move(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isCan)
	{
		if (this->animations < 4)
			this->animations = 4;
		isIdle = false;
		this->animations += dt * 10.f;
		if (animations >= 7) animations -= 3;
		this->player.setTextureRect(sf::IntRect(64 * int(animations), 64, 64, 64));
		this->player.move(-0.05, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !isCan)
	{
		if (this->animations < 8)
			this->animations = 8;
		isIdle = false;
		this->animations += dt * 10.f;
		if (animations >= 11)animations -= 3;
		this->player.setTextureRect(sf::IntRect(64 * int(animations), 64, 64, 64));
		this->player.move(0.05, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isCan)
	{
		isIdle = false;
		this->animations += dt * 10.f;
		if (animations > 3)animations -= 3;
		this->player.setTextureRect(sf::IntRect(64 * int(animations), 64, 64, 64));
		this->player.move(0, 0.05);
	}
	if (isIdle)
	{
		this->animations += dt * 10.f;
		if (animations >= 7)animations -= 3;
		this->player.setTextureRect(sf::IntRect(64 * int(animations), 0, 64, 64));
	}
}

bool Player::isCanMove(std::vector<Tile*> tiles)
{
    for (size_t i = 0; i < tiles.size(); i++)
    {
        if (tiles[i]->collision == true&&tiles[i]->tile.getGlobalBounds().intersects(this->player.getGlobalBounds())) {
            return false;
        }
    }
    return true;
}
