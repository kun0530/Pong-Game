#include "pch.h"
#include "Bat.h"

Bat::Bat(const std::string& name) : GameObject(name)
{
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	bat.setPosition(pos);
}

void Bat::SetOrigin(Origins preset)
{
	if (preset == Origins::Custom)
	{
		preset = Origins::TL;
	}
	originPreset = preset;
	origin = Utils::SetOrigin(bat, originPreset);
}

void Bat::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	bat.setOrigin(newOrigin);
}

void Bat::Init()
{
	bat.setSize({ 100.f, 5.f });
	SetPosition({ (float)FRAMEWORK.GetWindowSize().x / 2.f,
		(float)FRAMEWORK.GetWindowSize().y - 100.f });
	bat.setFillColor(sf::Color::White);

	SetOrigin(Origins::TC);
}

void Bat::Update(float dt)
{
	float h = InputMgr::GetAxisRaw(Axis::Horizontal);
	sf::Vector2f pos = GetPosition();
	pos.x += h * speed * dt;
	SetPosition(pos);
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(bat);
}
