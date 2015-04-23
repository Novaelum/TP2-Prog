#pragma once
#include "Sprite.h"
#include "Text.h"

#define OpSc_LINE_SPACING 30

class OpeningScene:
	public Component
{
public:
	OpeningScene();
	~OpeningScene();

	virtual void Update();
	virtual void Kill();

private:
	float timer;
	bool activated;
	bool flipper = true;
	Sprite* background;
	Sprite* cursor;
	Text* openingline;
	Text* choice[2];
};

