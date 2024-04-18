#include "Map.h"
#include <iostream>


Map::Map():
    tileWidth(16),
    tileHeight(16),
    totalTilesOnX(0),
    totalTilesonY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
    if (texture.loadFromFile("Assets/World/Prison/Tilesheet.png"))
    {
        totalTilesOnX = texture.getSize().x / tileWidth;
        totalTilesonY = texture.getSize().y / tileHeight;

        std::cout << "World tilesheet loaded" << std::endl;

        for (size_t i = 0; i < 10; i++) 
        {
            sprites[i].setTexture(texture);
            sprites[i].setTextureRect(sf::IntRect(i * tileWidth, 4 * tileHeight, tileWidth, tileHeight));
            sprites[i].setScale(sf::Vector2f(5, 5));
            sprites[i].setPosition(sf::Vector2f(100 + i * tileWidth * 5, 100));
        }
    }
    else {
        std::cout << "Failed to load world tilesheet" << std::endl;
    }
}

void Map::Load()
{
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++)
    {
        window.draw(sprites[i]);
    }
}
