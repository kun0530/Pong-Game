#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
protected:
	sf::CircleShape ball;

	sf::Vector2f direction = { 0.f, 0.f };
	float speed = 0.f;

	bool isDead = false;
	bool isBoundBat = false;

	sf::FloatRect windowBounds;

public:
	Ball(const std::string& name = "");

	void Fire(sf::Vector2f dir, float spd);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window);
};

