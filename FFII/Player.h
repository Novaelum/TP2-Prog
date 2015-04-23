#pragma once
#include "Sprite.h"
#include "Animation.h"
#include "ResourcesIDs.h"

enum characterID {
	FIRION,
	MARIA,
	GAÏ,
	LEON
};

class Player
{
	struct Character {
		characterID ID;
		std::string name;
		Sprite* portrait;
		Animation* animations;
	};

public:
	Player();
	~Player();

	// Getter
	std::vector<Character*> GetParty() { return party; }
	std::vector<Character*> GetCharList() { return charactersList; }


private:
	// Active characters in combat and on the world
	std::vector<Character*> party;

	// List of all acquired characters by the player
	std::vector<Character*> charactersList;
};
