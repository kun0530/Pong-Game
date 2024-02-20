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

void Ball::SetBatBounds(const sf::FloatRect& batBounds)
{
	this->batBounds = batBounds;
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
		FRAMEWORK.GetWindowSize().y - 100.f });
	ball.setFillColor(sf::Color::White);
	SetOrigin(Origins::BC);

	windowBounds = { { 0.f, 0.f },
		{ (float)FRAMEWORK.GetWindowSize().x, (float)FRAMEWORK.GetWindowSize().y } };
}

void Ball::Update(float dt)
{
	isBoundBat = false;

	sf::Vector2f prevPos = GetPosition();
	sf::Vector2f pos = prevPos;
	pos += direction * speed * dt;
	SetPosition(pos);



	// ball苞 window 面倒 贸府
	const sf::FloatRect& ballBounds = ball.getGlobalBounds();
	float ballTop = ballBounds.top;
	float ballBottom = ballBounds.top + ballBounds.height;
	float ballLeft = ballBounds.left;
	float ballRight = ballBounds.left + ballBounds.width;

	float windowTop = windowBounds.top;
	float windowBottom = windowBounds.top + windowBounds.height;
	float windowLeft = windowBounds.left;
	float windowRight = windowBounds.left + windowBounds.width;

	if (ballTop < windowTop)
	{
		direction.y *= -1.f;
		SetPosition(prevPos);
	}
	if (ballLeft < windowLeft || ballRight > windowRight)
	{
		direction.x *= -1.f;
		SetPosition(prevPos);
	}

	if (ballBottom > windowBottom)
	{
		isDead = true;
	}



	// ball苞 bat狼 面倒 贸府
	float batTop = batBounds.top;
	float batBottom = batBounds.top + batBounds.height;
	float batLeft = batBounds.left;
	float batRight = batBounds.left + batBounds.width;

	if (ballBounds.intersects(batBounds))
	{
		if (!isBatCollision)
		{
			isBatCollision = true;
			isBoundBat = true;

			if (ballBottom > batTop || ballTop < batBottom)
			{
				direction.y *= -1.f;
			}

			if (ballLeft > batRight || ballRight < batLeft)
			{
				direction.x *= -1.f;
			}
		}
	}
	else
	{
		isBatCollision = false;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
