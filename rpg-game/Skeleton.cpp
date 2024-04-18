#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : health(100)
{
}

Skeleton::~Skeleton()
{
}


void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}


void Skeleton::Initialize()
{
    boundingBox.setOutlineColor(sf::Color::Red);
    boundingBox.setFillColor(sf::Color::Transparent);
    boundingBox.setOutlineThickness(1.0);
    
    sprite.scale(sf::Vector2f(3, 3));
    size = sf::Vector2i(64, 64);
    boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Skeleton::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "Arial.ttf font loaded." << std::endl;
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }
    else {
        std::cout << "Failed to load font" << std::endl;
    }

    if (texture.loadFromFile("Assets/Skeleton/Textures/sprite-sheet.png")) {
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(300, 100));
        int XIndex = 0;
        int YIndex = 2;


        std::cout << "Enemy texture loaded" << std::endl;
        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }
    else {
        std::cout << "Enemy texture failed to load" << std::endl;
    }
}

void Skeleton::Update(float deltaTime)
{
    if (health > 0) {

    boundingBox.setPosition(sprite.getPosition());
    healthText.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    if (health > 0) {

    window.draw(sprite);
    window.draw(boundingBox);
    window.draw(healthText);
    }
}
