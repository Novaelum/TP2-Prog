#pragma once
#include "Libraries.h"
#include "Common.h"

#define OpSc_LINE_SPACING 30

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
	bool flipper = true;
	Sprite* background;
	Sprite* cursor;
	Text* openingline;
	Text* choice[2];
};

