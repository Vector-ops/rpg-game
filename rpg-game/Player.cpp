#include "Player.h"
#include "Math.h"
#include <iostream>

Player::Player() :
    playerSpeed(1.0f),
    maxFireRate(100),
    fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    boundingBox.setOutlineColor(sf::Color::Blue);
    boundingBox.setFillColor(sf::Color::Transparent);
    boundingBox.setOutlineThickness(1.0);

    sprite.scale(sf::Vector2f(3, 3));
    size = sf::Vector2i(64, 64);
    boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/sprite-sheet.png"))
    {
        int XIndex = 0;
        int YIndex = 0;

        std::cout << "Player image loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        
        sprite.setPosition(sf::Vector2f(900, 500));
    }
    else {
        std::cout << "Player image failed to load" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton, float deltaTime, sf::Vector2f &mousePosition)
{

    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed  * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);

    // bullet

    fireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {
        bullets.push_back(Bullet());
        int i = bullets.size() - 1;
        bullets[i].Initialize(sprite.getPosition(), mousePosition, 0.5f);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update(deltaTime);
        
        if (skeleton.health > 0){
        if (Math::CheckRectCollision(bullets[i].GetGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
            skeleton.ChangeHealth(-10);
            bullets.erase(bullets.begin() + i);
        }
        }
    }

    boundingBox.setPosition(sprite.getPosition());


}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(boundingBox);
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(window);
    }

}