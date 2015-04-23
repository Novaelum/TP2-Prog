#pragma once
#include "Engine.h"
#include "Player.h"

#define cGame Game::GetInstance()
#define currentPlayer cGame->GetPlayer()
#define hand_cursor cGame->GetCursor()

class Game
{
#pragma region SINGLETON
public:
	static Game* GetInstance()
	{
		if (!instance)
		{
			instance = new Game();
		}
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Game();
	~Game();

	static Game* instance;
#pragma endregion

public:
	// Getters
	Player* GetPlayer() { return player; }
	Sprite* GetCursor() { return cursor; }

private:
	Player* player;
	Sprite* cursor;
	
};
