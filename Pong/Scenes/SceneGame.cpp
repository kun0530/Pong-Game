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

	gameOverMsg = new TextGo("GameOver Message UI");
	gameOverMsg->Set(fontResMgr.Get("fonts/DS-DIGI.ttf"),
		"", 50, sf::Color::Red);
	gameOverMsg->SetActive(false);
	gameOverMsg->SetOrigin(Origins::MC);
	gameOverMsg->SetPosition({ (float)FRAMEWORK.GetWindowSize().x / 2.f,
		(float)FRAMEWORK.GetWindowSize().y / 2.f });
	AddGo(gameOverMsg);

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
	gameOverMsg = nullptr;
}

void SceneGame::Enter()
{
	Scene::Enter();

	score = 0;
	lives = 3;
	isGameOver = false;
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

	ball->SetBatBounds(bat->GetBatBounds());

	if (lives == 0)
	{
		isGameOver = true;
		gameOverMsg->SetString("Game Over! Your Score: " + std::to_string(score));
		gameOverMsg->SetActive(true);
	}
	if (isGameOver && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		isGameOver = false;
		gameOverMsg->SetActive(false);
		lives = 3;
		score = 0;
		infoUi->SetString("Score: " + std::to_string(score) + " / Lives: " + std::to_string(lives));
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
