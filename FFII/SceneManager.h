#pragma once
#include "Scene.h"
#include "ScenesList.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

private:
	Scene* currentScene;
};

