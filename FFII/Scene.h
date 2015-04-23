#pragma once
#include "Component.h"
#include "Engine.h"
class Scene:
	public Component
{
public:
	Scene();
	~Scene();

	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();
};

