#pragma once
#include "Libraries.h"
class CharacterCreation :
	public Component
{
public:
	CharacterCreation();
	~CharacterCreation();

private:
	Sprite* portraits[4];
	Text* names[4];
	Sprite* background[6];
	Sprite* cursor;
};

