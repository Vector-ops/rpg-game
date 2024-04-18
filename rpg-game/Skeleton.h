#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	sf::RectangleShape boundingBox;
	sf::Vector2i size;
	sf::Text healthText;
	sf::Font font;

public:
	sf::Sprite sprite;
	int health;

public:
	Skeleton();
	~Skeleton();
	void ChangeHealth(int hp);
	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

