#include "CharacterCreation.h"


CharacterCreation::CharacterCreation()
	: timer(0)
	, p(0)
	, mode(0)
	, coordonates(0, 0) {

	currentPlayer->GetParty().at(0)->name = "Firion";
	currentPlayer->GetParty().at(1)->name = "Maria";
	currentPlayer->GetParty().at(2)->name = "Gai";
	currentPlayer->GetParty().at(3)->name = "Leon";

	background = new Sprite(t_cc_bg);

	for (int i = 0; i < 4; ++i) {
		int y = 50 + i * 140;

		// Portraits
		portraits[i] = currentPlayer->GetParty().at(i)->portrait;
		portraits[i]->SetPosition(30, y);
		portraits[i]->SetVisibility(true);
		cEngine->MoveBack(portraits[i]);

		// Names
		y += 15;
		names[i] = new Text(currentPlayer->GetParty().at(i)->name, f_ffta_55, 55, point<int>(200, y), 0, Color::WHITE, OpNone);
	}

	cursor = hand_cursor;
	cursor->SetPosition(names[p]->GetPosition().x - 65, names[p]->GetPosition().y + 20);
	cEngine->MoveBack(cursor);
	cursor->SetVisibility(true);

	info[0] = new Text("New Game", f_ffta_55, 0, point<int> (650, 5));
	info[1] = new Text("Assign names to the characters.", f_ffta_55, point<int>(545, 68), 300, Color::WHITE, OpNone);

	controls[0] = new Text("'Z' Confirm", f_ffta_55, 0, point<int>(545, 400));
	controls[1] = new Text("'X' Back", f_ffta_55, 0, point<int>(545, 440));
	controls[2] = new Text("'Enter' Done", f_ffta_55, 0, point<int>(545, 480));
	
	// Renaming grid
	GridCreate();

	// Square cursor of renaming grid
	sqaCursor = new Sprite(t_cursor_sqa);
	sqaCursor->SetVisibility(false);
	MoveSqaCursor();

	lttrU = new Sprite(t_lttr_u);
	lttrU->SetVisibility(false);
	MoveLettrU();
}

void CharacterCreation::GridCreate() {
	char* gridLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ    abcdefghijklmnopqrstuvwxyz    0123456789?!,.:\/&\_\+-";
	for (int j = 0; j < 8; ++j) {
		for (int k = 0; k < 10; ++k) {
			char l[2] = { gridLetters[0], '\0' };
			renamingGrid[j][k] = new Text(l, f_ffta_55);
			renamingGrid[j][k]->SetPosition(538 + 35 * k, 65 + 35 * j);
			renamingGrid[j][k]->ToggleVisibility();
			gridLetters++;
		}
	}
}

void CharacterCreation::GridToggle() {
	for (int j = 0; j < 8; ++j) {
		for (int k = 0; k < 10; ++k) {
			renamingGrid[j][k]->ToggleVisibility();
		}
	}
}

void CharacterCreation::GridDelete() {
	for (int j = 0; j < 8; ++j) {
		for (int k = 0; k < 10; ++k) {
			cEngine->DeleteComponent(renamingGrid[j][k]);
		}
	}
}


CharacterCreation::~CharacterCreation() {

}

void CharacterCreation::Update() {
	timer += DTime;
	// Mode 0, choosing character to rename
	if (mode == 0) {
		if (ThisKeyPressed(SDL_SCANCODE_UP) || ThisKeyHeld(SDL_SCANCODE_UP) || ThisKeyPressed(SDL_SCANCODE_LEFT) || ThisKeyHeld(SDL_SCANCODE_LEFT)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				p--;
				if (p < 0) {
					p = 3;
				}
				cursor->SetPosition(names[p]->GetPosition().x - 65, names[p]->GetPosition().y + 20);
			}
		}
		else if (ThisKeyPressed(SDL_SCANCODE_DOWN) || ThisKeyHeld(SDL_SCANCODE_DOWN) || ThisKeyPressed(SDL_SCANCODE_RIGHT) || ThisKeyHeld(SDL_SCANCODE_RIGHT)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				p++;
				if (p > 3) {
					p = 0;
				}
				cursor->SetPosition(names[p]->GetPosition().x - 65, names[p]->GetPosition().y + 20);
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_Z)) {
			cAudio->PlaySound(s_cursor_m);
			ModeOne();
			MoveLettrU();
			tempName = names[p]->GetText();
		}
		if (ThisKeyPressed(SDL_SCANCODE_X)) {
			cAudio->PlaySound(s_cursor_b);
			DeleteAll();
			new OpeningScene();
		}
		if (ThisKeyPressed(SDL_SCANCODE_RETURN)) {
			cAudio->PlaySound(s_cursor_m);
			DeleteAll();
			new BattleScene();
		}
	}
	// Mode one, renaming
	else {
		if (ThisKeyPressed(SDL_SCANCODE_UP) || ThisKeyHeld(SDL_SCANCODE_UP)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				coordonates.y--;
				if (coordonates.y < 0) {
					coordonates.y = 7;
				}
				MoveSqaCursor();
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_DOWN) || ThisKeyHeld(SDL_SCANCODE_DOWN)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				coordonates.y++;
				if (coordonates.y > 7) {
					coordonates.y = 0;
				}
				MoveSqaCursor();
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_LEFT) || ThisKeyHeld(SDL_SCANCODE_LEFT)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				coordonates.x--;
				if (coordonates.x < 0) {
					coordonates.x = 9;
				}
				MoveSqaCursor();
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_RIGHT) || ThisKeyHeld(SDL_SCANCODE_RIGHT)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				coordonates.x++;
				if (coordonates.x > 9) {
					coordonates.x = 0;
				}
				MoveSqaCursor();
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_X)) {
			if (tempName.size() > 0) {
				cAudio->PlaySound(s_cursor_b);
				tempName.pop_back();
				names[p]->SetText(tempName.c_str());
				MoveLettrU();
			}
			else {
				cAudio->PlaySound(s_cursor_e);
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_Z)) {
			if (tempName.size() < NAME_MAX_SIZE) {
				cAudio->PlaySound(s_cursor_m);
				tempName.append(renamingGrid[coordonates.y][coordonates.x]->GetText());
				names[p]->SetText(tempName.c_str());
				MoveLettrU();
			}
			else {
				cAudio->PlaySound(s_cursor_e);
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_RETURN)) {
			if (tempName.size() > 0) {
				ModeZero();
				currentPlayer->GetParty().at(p)->name = tempName;
			}
			else {
				cAudio->PlaySound(s_cursor_e);
			}
		}
	}
}

void CharacterCreation::DeleteAll() {
	cursor->SetVisibility(false);
	GridDelete();
	cEngine->DeleteComponent(background);
	for (int i = 0; i < 2; ++i) {
		cEngine->DeleteComponent(info[i]);
	}
	for (int i = 0; i < 3; ++i) {
		cEngine->DeleteComponent(controls[i]);
	}
	for (int i = 0; i < 4; ++i) {
		cEngine->DeleteComponent(names[i]);
	}
	for (int i = 0; i < 4; ++i) {
		portraits[i]->ToggleVisibility();
	}
	cEngine->DeleteComponent(sqaCursor);
	cEngine->DeleteComponent(lttrU);
	cEngine->DeleteComponent(this);
}

void CharacterCreation::Kill() {
	delete this;
}
 
void CharacterCreation::ModeZero() {
	mode = 0;
	info[0]->SetText("New Game");
	info[1]->ToggleVisibility();
	cursor->ToggleVisibility();
	sqaCursor->ToggleVisibility();
	lttrU->ToggleVisibility();
	GridToggle();
	coordonates = { 0, 0 };
	MoveSqaCursor();
}

void CharacterCreation::ModeOne() {
	mode = 1;
	info[0]->SetText("Enter name.");
	info[1]->ToggleVisibility();
	cursor->ToggleVisibility();
	sqaCursor->ToggleVisibility();
	lttrU->ToggleVisibility();
	GridToggle();
}

void CharacterCreation::MoveSqaCursor() {
	sqaCursor->SetPosition(renamingGrid[coordonates.y][coordonates.x]->GetPosition().x - 10, renamingGrid[coordonates.y][coordonates.x]->GetPosition().y + 15);
}

void CharacterCreation::MoveLettrU() {
	int w, h;
	TTF_SizeText(Fonts->Get(f_ffta_55), names[p]->GetText().c_str(), &w, &h);
	lttrU->SetPosition(names[p]->GetPosition().x + w, names[p]->GetPosition().y + 47);
}
