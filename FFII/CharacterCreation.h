#pragma once
#include "Libraries.h"

#define NAME_MAX_SIZE 7

class CharacterCreation :
	public Component
{
public:
	CharacterCreation();
	~CharacterCreation();

	virtual void Update();
	virtual void Kill();

private:
	Sprite* portraits[4];
	Text* names[4];
	Sprite* background;

	Sprite* cursor;
	Sprite* sqaCursor;
	Sprite* lttrU;

	float timer;
	int p;

	int mode;

	Text* info[2];
	Text* controls[3];

	Text* renamingGrid[8][10];

	void ModeZero();
	void ModeOne();

	void GridCreate();
	void GridToggle();
	void GridDelete();

	void MoveSqaCursor();
	void MoveLettrU();

	std::string tempName;

	point<int> coordonates;

	void DeleteAll();
};

