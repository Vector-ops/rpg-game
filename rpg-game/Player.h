#pragma once

#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;
	std::vector<Bullet> bullets;
	float fireRateTimer;
	int maxFireRate;
	float playerSpeed;

	sf::RectangleShape boundingBox;
	
	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(Skeleton &skeleton, float deltaTime, sf::Vector2f &mousePosition);
	void Draw(sf::RenderWindow& window);
};