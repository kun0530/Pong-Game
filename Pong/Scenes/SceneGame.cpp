#include "pch.h"
#include "SceneGame.h"
#include "Ball.h"
#include "Bat.h"
#include "TextGo.h"

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

	RES_MGR_FONT.Load("fonts/DS-DIGI.ttf");
	infoUi = new TextGo("Info UI");
	infoUi->Set(fontResMgr.Get("fonts/DS-DIGI.ttf"),
		"Score: " + std::to_string(score) + " / Lives: " + std::to_string(lives),
		50,
		sf::Color::White);
	AddGo(infoUi);

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
	infoUi = nullptr;
}

void SceneGame::Enter()
{
	Scene::Enter();

	score = 0;
	lives = 3;
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
	else
	{
		if (ball->IsDead())
		{
			lives -= 1;
			isBallActive = false;
			ball->Fire({ 0.f, 0.f }, 0.f);
		}
		else if (ball->IsBoundBat())
		{
			score += 100;
		}
		infoUi->SetString("Score: " + std::to_string(score) + " / Lives: " + std::to_string(lives));
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
