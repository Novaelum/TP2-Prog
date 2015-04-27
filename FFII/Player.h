#pragma once
#include "Sprite.h"
#include "Animation.h"
#include "ResourcesIDs.h"

enum Row {
	R_FRONT,
	R_BACK
};

enum CharacterID {
	FIRION,
	MARIA,
	GAÏ,
	LEON
};

enum CharAction {
	CA_Idle,
	CA_MovingForward,
	CA_MovingBack,
	CA_Attacking,
	CA_Hit,
	CA_Dead,
	CA_Fleeing
};

struct BattleState {
	CharAction action;
	CharAction nextAction;
	Sprite* charSheet;
	SDL_Rect* idle;
	SDL_Rect* ready;
	SDL_Rect* hit;
	SDL_Rect* dead;
	SDL_Rect* move;
	Animation* attack;
	float currentTime = 0;
	bool isReady = false;
	bool isFleeing = false;
	bool isAttacking = false;
	bool changed = false;
	int target;
};

class Player
{
	struct CharStats {
		int mHP;
		int cHP;
		int mMP;
		int cMP;
		int Strength;
		int Spirit;
		int Intelligence;
		int Stamina;
		int Agility;
		int Magic;
	};

	struct Character {
		CharacterID ID;
		std::string name;
		Sprite* portrait;
		CharStats stats;
		BattleState state;
		int row;
	};

public:
	Player();
	~Player();

	// Getter
	std::vector<Character*> GetParty()		{ return party; }
	std::vector<Character*> GetCharList()	{ return charactersList; }
	int GetPartySize()						{ return partySize; }


private:
	// Active characters in combat and on the world
	std::vector<Character*> party;

	int partySize;

	// List of all acquired characters by the player
	std::vector<Character*> charactersList;
};
