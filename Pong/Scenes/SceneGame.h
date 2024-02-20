#pragma once
#include "Scene.h"

class Ball;

class SceneGame : public Scene
{
protected:
	Ball* ball = nullptr;
	bool isBallActive = false;

public:
	SceneGame(SceneIds id);
	virtual ~SceneGame();

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

