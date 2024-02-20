#pragma once
#include "GameObject.h"
class Bat : public GameObject
{
protected:
	sf::RectangleShape bat;

	float speed = 500.f;

public:
	Bat(const std::string& name);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

