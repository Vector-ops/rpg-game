#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/sprite-sheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 100));
        int XIndex = 0;
        int YIndex = 2;


        std::cout << "Enemy texture loaded" << std::endl;
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Enemy texture failed to load" << std::endl;
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
