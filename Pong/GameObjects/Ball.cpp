#include "pch.h"
#include "Ball.h"

Ball::Ball(const std::string& name) : GameObject(name)
{
}

void Ball::Fire(sf::Vector2f dir, float spd)
{
	direction = dir;
	speed = spd;
	isDead = false;
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	ball.setPosition(pos);
}

void Ball::SetOrigin(Origins preset)
{
	if (preset == Origins::Custom)
	{
		preset = Origins::TL;
	}
	originPreset = preset;
	origin = Utils::SetOrigin(ball, originPreset);
}

void Ball::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	ball.setOrigin(newOrigin);
}

void Ball::Init()
{
	ball.setRadius(10.f);
	SetPosition({ FRAMEWORK.GetWindowSize().x / 2.f,
		FRAMEWORK.GetWindowSize().y / 2.f });
	ball.setFillColor(sf::Color::White);
	SetOrigin(Origins::BC);
}

void Ball::Update(float dt)
{
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
