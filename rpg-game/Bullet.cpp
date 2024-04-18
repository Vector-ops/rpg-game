#include "Bullet.h"
#include "Math.h"

Bullet::Bullet():
	speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f &position,const sf::Vector2f &target, float speed)
{
	m_speed = speed;
	rectangleShape.setSize(sf::Vector2f(30, 10));
	rectangleShape.setPosition(position);
	direction = Math::NormalizeVector(target - position);
}

void Bullet::Load()
{
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * m_speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
