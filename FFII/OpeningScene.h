#pragma once
#include "Libraries.h"
#include "Common.h"

class OpeningScene:
	public Component
{
public:
	OpeningScene();
	~OpeningScene();

	virtual void Update();

private:
	Sprite* background;
	TextAnim* dialog;
};

