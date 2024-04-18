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
    
}

void Map::Load()
{

    if (texture.loadFromFile("Assets/World/Prison/Tilesheet.png"))
    {

        totalTilesOnX = texture.getSize().x / tileWidth;
        totalTilesonY = texture.getSize().y / tileHeight;

        std::cout << "World tilesheet loaded" << std::endl;

        totalTiles = totalTilesOnX * totalTilesonY;
        tiles = new Tile[totalTiles];

        for (int y = 0; y < totalTilesonY; y++)
        {
            for (int x = 0; x < totalTilesOnX; x++) {

                int i = x + y * totalTilesOnX;

                tiles[i].id = i;
                tiles[i].position = sf::Vector2i(x * tileWidth, y * tileHeight);
            }
        }
    }
    else {
        std::cout << "Failed to load world tilesheet" << std::endl;
    }

    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 3; x++) {
            int i = x + y * 3;
            int index = mapNumbers[i];

            mapSprites[i].setTexture(texture);
            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x,
                tiles[index].position.y,
                tileWidth,
                tileHeight
            ));
            mapSprites[i].setScale(sf::Vector2f(5,5));
            mapSprites[i].setPosition(sf::Vector2f(x * 16 * 5, 100 + y * 16 * 5));
        }
    }
    
}

void Map::Update(double deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 6; i++)
    {
        window.draw(mapSprites[i]);
    }
}
