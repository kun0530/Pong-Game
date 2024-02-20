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
	bool isBatCollision = false;

	sf::FloatRect windowBounds;
	sf::FloatRect batBounds;
public:
	Ball(const std::string& name = "");

	void Fire(sf::Vector2f dir, float spd);

	bool IsDead() const { return isDead; }
	bool IsBoundBat() const { return isBoundBat; }

	void SetBatBounds(const sf::FloatRect& batBounds);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window);
};

