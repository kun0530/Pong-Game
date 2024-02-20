#include "pch.h"
#include "SceneGame.h"
#include "Ball.h"
#include "Bat.h"

SceneGame::SceneGame(SceneIds id) : Scene(id)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	ball = new Ball("Ball");
	AddGo(ball);

	bat = new Bat("Bat");
	AddGo(bat);

	for (auto obj : gameObjects)
	{
		obj->Init();
	}
}

void SceneGame::Release()
{
	Scene::Release();

	ball = nullptr;
	bat = nullptr;
}

void SceneGame::Enter()
{
	Scene::Enter();

	score = 0;
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (!isBallActive)
	{
		ball->SetPosition(bat->GetPosition());
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ball->Fire({ 1.f, -1.f }, 1000.f);
			isBallActive = true;
		}
	}

	if (ball->IsDead())
	{
		isBallActive = false;
		ball->Fire({ 0.f, 0.f }, 0.f);
	}
	else if (ball->IsBoundBat())
	{
		score += 100;
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
