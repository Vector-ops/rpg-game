#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture texture;
	Tile *tiles;

	int totalTiles;
	int tileWidth;
	int tileHeight;
	int totalTilesOnX;
	int totalTilesonY;

	int mapNumbers[6] = {
		1, 1, 1, 25, 27, 30
	};

	sf::Sprite mapSprites[6];

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

