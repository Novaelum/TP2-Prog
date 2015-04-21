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
	float timer;
	bool activated;
	Sprite* background;
	Sprite* cursor;
	Text* openingline;
	Text* choice[2];
};

