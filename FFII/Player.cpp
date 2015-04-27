#include "Player.h"


Player::Player()
{
	// =========================================
	// Initial party creation
	// ----------------------------------------

	// Firion
	// ----------------------------
	Character* Firion = new Character();
	// ID & default name
	Firion->ID = FIRION;
	Firion->name = "Firion";
	// Portrait
	Firion->portrait = new Sprite(t_characters, point<int>(5, 5), point<int>(28, 28));
	Firion->portrait->Scale(3.75f);
	Firion->portrait->ToggleVisibility();

	// Stats
	Firion->stats.mHP				 = 30;
	Firion->stats.cHP = Firion->stats.mHP;
	Firion->stats.mMP			   	 = 10;
	Firion->stats.cMP = Firion->stats.mMP;
	Firion->stats.Strength			 = 10;
	Firion->stats.Spirit			 = 10;
	Firion->stats.Intelligence		 = 10;
	Firion->stats.Stamina			 = 10;
	Firion->stats.Agility			 = 10;
	Firion->stats.Magic				 =  5;

	// Animations
	Firion->state.charSheet = new Sprite(t_characters, point<int>(35, 10), point<int>(18, 23));
	Firion->state.charSheet->Scale(3.75f);

	// Idle
	Firion->state.idle = new SDL_Rect();
	Firion->state.idle->x = 35;
	Firion->state.idle->y = 9;
	Firion->state.idle->w = 18;
	Firion->state.idle->h = 24;

	// Ready
	Firion->state.ready = new SDL_Rect();
	Firion->state.ready->x = 75;
	Firion->state.ready->y = 9;
	Firion->state.ready->w = 18;
	Firion->state.ready->h = 24;

	// Dead
	Firion->state.dead = new SDL_Rect();
	Firion->state.dead->x = 110;
	Firion->state.dead->y = 9;
	Firion->state.dead->w = 24;
	Firion->state.dead->h = 23;

	// Hit
	Firion->state.hit = new SDL_Rect();
	Firion->state.hit->x = 93;
	Firion->state.hit->y = 9;
	Firion->state.hit->w = 17;
	Firion->state.hit->h = 24;

	// Move
	Firion->state.move = new SDL_Rect();
	Firion->state.move->x = 53;
	Firion->state.move->y = 9;
	Firion->state.move->w = 19;
	Firion->state.move->h = 24;

	// Attack
	Firion->state.attack = new Animation(t_characters, 2, 16, point<int>(173, 9), point<int>(19, 24));
	Firion->state.attack->Scale(3.75f);
	Firion->state.attack->SetVisibility(false);

	Firion->row = R_FRONT;

	party.push_back(Firion);
	charactersList.push_back(Firion);


	// Maria
	// ----------------------------
	Character* Maria = new Character();
	// ID & default name
	Maria->ID = MARIA;
	Maria->name = "Maria";
	// Portrait
	Maria->portrait = new Sprite(t_characters, point<int>(5, 45), point<int>(28, 28));
	Maria->portrait->Scale(3.75f);
	Maria->portrait->ToggleVisibility();

	// Stats
	Maria->stats.mHP			   = 20;
	Maria->stats.cHP = Maria->stats.mHP;
	Maria->stats.mMP			   = 10;
	Maria->stats.cMP = Maria->stats.mMP;
	Maria->stats.Strength		   =  5;
	Maria->stats.Spirit			   = 10;
	Maria->stats.Intelligence      = 15;
	Maria->stats.Stamina	   	   =  5;
	Maria->stats.Agility		   = 15;
	Maria->stats.Magic			   =  5;

	// Animations
	Maria->state.charSheet = new Sprite(t_characters, point<int>(35, 50), point<int>(16, 23));
	Maria->state.charSheet->Scale(3.75f);

	// Idle
	Maria->state.idle = new SDL_Rect();
	Maria->state.idle->x = 35;
	Maria->state.idle->y = 50;
	Maria->state.idle->w = 16;
	Maria->state.idle->h = 23;

	// Ready
	Maria->state.ready = new SDL_Rect();
	Maria->state.ready->x = 75;
	Maria->state.ready->y = 50;
	Maria->state.ready->w = 16;
	Maria->state.ready->h = 23;

	// Dead
	Maria->state.dead = new SDL_Rect();
	Maria->state.dead->x = 112;
	Maria->state.dead->y = 50;
	Maria->state.dead->w = 24;
	Maria->state.dead->h = 23;

	// Hit
	Maria->state.hit = new SDL_Rect();
	Maria->state.hit->x = 93;
	Maria->state.hit->y = 50;
	Maria->state.hit->w = 18;
	Maria->state.hit->h = 23;

	// Move
	Maria->state.move = new SDL_Rect();
	Maria->state.move->x = 55;
	Maria->state.move->y = 50;
	Maria->state.move->w = 17;
	Maria->state.move->h = 23;

	// Attack
	Maria->state.attack = new Animation(t_characters, 2, 16, point<int>(174, 50), point<int>(19, 24));
	Maria->state.attack->Scale(3.75f);
	Maria->state.attack->ToggleVisibility();

	Maria->row = R_BACK;
	
	party.push_back(Maria);
	charactersList.push_back(Maria);


	// Ga�
	// ----------------------------
	Character* Ga� = new Character();

	// ID & default name
	Ga�->ID = GA�;
	Ga�->name = "Gai";

	// Portrait
	Ga�->portrait = new Sprite(t_characters, point<int>(5, 85), point<int>(28, 28));
	Ga�->portrait->Scale(3.75f);
	Ga�->portrait->ToggleVisibility();

	// Stats
	Ga�->stats.mHP				=   40;
	Ga�->stats.cHP  =	Ga�->stats.mHP;
	Ga�->stats.mMP				=   10;
	Ga�->stats.cMP  =	Ga�->stats.mMP;
	Ga�->stats.Strength			=	15;
	Ga�->stats.Spirit			=	10;
	Ga�->stats.Intelligence		=	10;
	Ga�->stats.Stamina			=	15;
	Ga�->stats.Agility			=	 5;
	Ga�->stats.Magic			=	 5;

	// Animations
	Ga�->state.charSheet = new Sprite(t_characters, point<int>(37, 88), point<int>(18, 24));
	Ga�->state.charSheet->Scale(3.75f);

	// Idle
	Ga�->state.idle = new SDL_Rect();
	Ga�->state.idle->x = 37;
	Ga�->state.idle->y = 88;
	Ga�->state.idle->w = 18;
	Ga�->state.idle->h = 24;

	// Ready
	Ga�->state.ready = new SDL_Rect();
	Ga�->state.ready->x = 75;
	Ga�->state.ready->y = 88;
	Ga�->state.ready->w = 18;
	Ga�->state.ready->h = 24;

	// Dead
	Ga�->state.dead = new SDL_Rect();
	Ga�->state.dead->x = 112;
	Ga�->state.dead->y = 88;
	Ga�->state.dead->w = 24;
	Ga�->state.dead->h = 24;

	// Hit
	Ga�->state.hit = new SDL_Rect();
	Ga�->state.hit->x = 94;
	Ga�->state.hit->y = 88;
	Ga�->state.hit->w = 18;
	Ga�->state.hit->h = 24;

	// Move
	Ga�->state.move = new SDL_Rect();
	Ga�->state.move->x = 55;
	Ga�->state.move->y = 88;
	Ga�->state.move->w = 18;
	Ga�->state.move->h = 24;

	// Attack
	Ga�->state.attack = new Animation(t_characters, 2, 16, point<int>(176, 88), point<int>(20, 24));
	Ga�->state.attack->Scale(3.75f);
	Ga�->state.attack->ToggleVisibility();

	Ga�->row = R_FRONT;

	party.push_back(Ga�);
	charactersList.push_back(Ga�);


	// Leon
	// ----------------------------
	Character* Leon = new Character();

	// ID & default name
	Leon->ID = LEON;
	Leon->name = "Leon";

	// Portrait
	Leon->portrait = new Sprite(t_characters, point<int>(5, 123), point<int>(28, 28));
	Leon->portrait->Scale(3.75f);
	Leon->portrait->ToggleVisibility();

	// Stats
	Leon->stats.mHP				 = 30;
	Leon->stats.cHP = Leon->stats.mHP;
	Leon->stats.mMP				 =  5;
	Leon->stats.cMP = Leon->stats.mMP;
	Leon->stats.Strength		 = 20;
	Leon->stats.Spirit			 = 10;
	Leon->stats.Intelligence 	 = 12;
	Leon->stats.Stamina			 = 15;
	Leon->stats.Agility			 = 20;
	Leon->stats.Magic			 = 10;

	// Animation
	Leon->state.charSheet = new Sprite(t_characters, point<int>(37, 127), point<int>(17, 24));
	Leon->state.charSheet->Scale(3.75f);

	// Idle
	Leon->state.idle = new SDL_Rect();
	Leon->state.idle->x = 37;
	Leon->state.idle->y = 127;
	Leon->state.idle->w = 17;
	Leon->state.idle->h = 24;

	// Ready
	Leon->state.ready = new SDL_Rect();
	Leon->state.ready->x = 75;
	Leon->state.ready->y = 127;
	Leon->state.ready->w = 17;
	Leon->state.ready->h = 24;

	// Dead
	Leon->state.dead = new SDL_Rect();
	Leon->state.dead->x = 111;
	Leon->state.dead->y = 127;
	Leon->state.dead->w = 24;
	Leon->state.dead->h = 24;

	// Hit
	Leon->state.hit = new SDL_Rect();
	Leon->state.hit->x = 93;
	Leon->state.hit->y = 127;
	Leon->state.hit->w = 18;
	Leon->state.hit->h = 24;

	// Move
	Leon->state.move = new SDL_Rect();
	Leon->state.move->x = 55;
	Leon->state.move->y = 127;
	Leon->state.move->w = 18;
	Leon->state.move->h = 24;

	// Attack
	Leon->state.attack = new Animation(t_characters, 2, 16, point<int>(175, 127), point<int>(20, 24));
	Leon->state.attack->Scale(3.75f);
	Leon->state.attack->ToggleVisibility();

	Leon->row = R_FRONT;

	party.push_back(Leon);
	charactersList.push_back(Leon);

	partySize = 4;
}


Player::~Player()
{
}
