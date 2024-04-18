#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture texture;
	sf::Sprite sprites[10];	

	int tileWidth;
	int tileHeight;
	int totalTilesOnX;
	int totalTilesonY;


public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

