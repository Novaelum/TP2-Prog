#include "CharacterCreation.h"


CharacterCreation::CharacterCreation() {
	background[0] = new Sprite(t_menubg);
	background[0]->ResizeTo(500, 600);


	for (int i = 0; i < 4; ++i) {
		int y = 30 + i * 140;

		// Portraits
		portraits[i] = currentPlayer->GetParty().at(i)->portrait;
		portraits[i]->Scale(3.75f);
		portraits[i]->SetPosition(30, y);
		portraits[i]->ToggleVisibility();
		cEngine->MoveBack(portraits[i]);

		// Names
		y += 20;
		names[i] = new Text(currentPlayer->GetParty().at(i)->name, f_finalfantasy, 16, point<int>(160, y), 0, Color::WHITE, OpNone);
	}

	cursor = hand_cursor;
	cEngine->MoveBack(cursor);
	cursor->ToggleVisibility();
}


CharacterCreation::~CharacterCreation() {

}
