#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	sf::RectangleShape boundingBox;

	sf::Vector2i size;

public:
	sf::Sprite sprite;

public:
	Skeleton();
	~Skeleton();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

