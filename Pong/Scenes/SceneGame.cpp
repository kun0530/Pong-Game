#include "pch.h"
#include "SceneGame.h"
#include "Ball.h"

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

	for (auto obj : gameObjects)
	{
		obj->Init();
	}
}

void SceneGame::Release()
{
	Scene::Release();

	ball = nullptr;
}

void SceneGame::Enter()
{
	Scene::Enter();
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
