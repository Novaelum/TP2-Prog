#include "OpeningScene.h"
#include "Libraries.h"


OpeningScene::OpeningScene()
	: activated(false)
	, timer(0) {
	background = new Sprite("images/openingscreen.jpg");
	cursor = hand_cursor;
	cEngine->MoveBack(cursor);
	cAudio->PlayMusic("musics/openingtheme.mp3");
	cAudio->SetMusicVolume(40);
	openingline = new Text("Push enter to begin", f_mainfont, 18, point<int>(300, 415), 0, Color::BLACK, OpFadeIn);
	cursor->ToggleVisibility();
	cursor->SetPosition(280, 415);
	for (int i = 0; i < 2; i++) {
		int y = 415 + i * OpSc_LINE_SPACING;
		choice[i] = new Text("", f_finalfantasy, 22, point<int>(350, y), 0, Color::BLACK, OpNone);
	}
}

OpeningScene::~OpeningScene() {
}

void OpeningScene::Update() {
	if (!activated) {
		if ((ThisKeyReleased(SDL_SCANCODE_RETURN)) || (ThisKeyPressed(SDL_SCANCODE_Z))) {
			cAudio->PlaySound(s_cursor_m);
			activated = true;
			openingline->SetText("");
			cursor->ToggleVisibility();
			choice[0]->SetText("New Game");
			choice[1]->SetText("Load Game");
		}
	}
	else {
		timer += DTime;
		if ((ThisKeyReleased(SDL_SCANCODE_RETURN)) || (ThisKeyPressed(SDL_SCANCODE_Z))) {
			if (flipper) {
				cAudio->PlaySound(s_cursor_m);
				cEngine->DeleteComponent(this);
				cEngine->DeleteComponent(background);
				cEngine->DeleteComponent(choice[0]);
				cEngine->DeleteComponent(choice[1]);
				cursor->ToggleVisibility();
				new CharacterCreation();
				return;
			}
			else {
				if (false) // TODO: Add variable checking if a game has been saved
					printf("Load game"); // TODO: Load the actual save
				else
					cAudio->PlaySound(s_cursor_e);
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_UP) || ThisKeyHeld(SDL_SCANCODE_UP)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				if (!choice[1]->TextNotSet()) {
					flipper = !flipper;
					if (cursor->GetPosition().y == choice[0]->GetPosition().y) {
						cursor->MoveBy(0, OpSc_LINE_SPACING);
					}
					else {
						cursor->MoveBy(0, -OpSc_LINE_SPACING);
					}
				}
			}
		}
		else if (ThisKeyPressed(SDL_SCANCODE_DOWN) || ThisKeyHeld(SDL_SCANCODE_DOWN)) {
			if (timer >= 0.08f) {
				timer = 0;
				cAudio->PlaySound(s_cursor_m);
				if (!choice[1]->TextNotSet()) {
					flipper = !flipper;
					if (cursor->GetPosition().y == choice[1]->GetPosition().y) {
						cursor->MoveBy(0, -OpSc_LINE_SPACING);
					}
					else {
						cursor->MoveBy(0, OpSc_LINE_SPACING);
					}
				}
			}
		}
	}
}

void OpeningScene::Kill() {
	delete this;
}
