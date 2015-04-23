#include "Player.h"


Player::Player()
{
	// =========================================
	// Initial party creation
	// ----------------------------------------

	// Firion
	Character* Firion = new Character();
	Firion->ID = FIRION;
	Firion->name = "Firion";
	Firion->portrait = new Sprite(t_characters, point<int>(5, 5), point<int>(28, 28));
	Firion->portrait->ToggleVisibility();
	party.push_back(Firion);
	charactersList.push_back(Firion);

	// Maria
	Character* Maria = new Character();
	Maria->ID = MARIA;
	Maria->name = "Maria";
	Maria->portrait = new Sprite(t_characters, point<int>(5, 45), point<int>(28, 28));
	Maria->portrait->ToggleVisibility();
	party.push_back(Maria);
	charactersList.push_back(Maria);

	// Gaï
	Character* Gaï = new Character();
	Gaï->ID = GAÏ;
	Gaï->name = "Gai";
	Gaï->portrait = new Sprite(t_characters, point<int>(5, 85), point<int>(28, 28));
	Gaï->portrait->ToggleVisibility();
	party.push_back(Gaï);
	charactersList.push_back(Gaï);

	// Leon
	Character* Leon = new Character();
	Leon->ID = LEON;
	Leon->name = "Leon";
	Leon->portrait = new Sprite(t_characters, point<int>(5, 123), point<int>(28, 28));
	Leon->portrait->ToggleVisibility();
	party.push_back(Leon);
	charactersList.push_back(Leon);
}


Player::~Player()
{
}
