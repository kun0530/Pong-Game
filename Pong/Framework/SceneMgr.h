#pragma once
#include "Singleton.h"

class Scene;

enum class SceneIds
{
	None = -1, SceneDev1, SceneDev2, SCENE_GAME, Count,
};

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::SCENE_GAME;
	SceneIds currentScene = startScene;

	SceneMgr() = default;
	virtual ~SceneMgr();

public:
	void Init();
	void Release();

	void ChangeScene(SceneIds id);

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;
};

#define SCENE_MGR (SceneMgr::Instance())