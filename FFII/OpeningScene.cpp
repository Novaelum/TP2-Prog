#include "OpeningScene.h"
#include "Libraries.h"


OpeningScene::OpeningScene()
	: activated(false)
	, timer(0) {
	background = new Sprite("images/openingscreen.jpg");
	cAudio->PlayMusic("musics/openingtheme.mp3");
	cAudio->SetMusicVolume(40);
	openingline = new Text("Push enter to begin", f_mainfont, 18, point<int>(300, 415), 0, Color::BLACK, OpFadeIn);
	cursor = new Sprite(t_cursor);
	cursor->ToggleVisibility();
	cursor->SetPosition(280, 415);
	for (int i = 0; i < 2; i++) {
		int y = 415 + i * OpSc_LINE_SPACING;
		choice[i] = new Text("", f_finalfantasy, 22, point<int>(350, y), 0, Color::BLACK, OpNone);
	}
}

OpeningScene::~OpeningScene() {
	delete background;
	delete openingline;
	for (int i = 0; i < 2; i++) {
		delete choice[i];
	}
}

void OpeningScene::Update() {
	if (!activated) {
		if ((ThisKeyReleased(SDL_SCANCODE_RETURN)) || (ThisKeyPressed(SDL_SCANCODE_Z))) {
			cAudio->PlaySound(s_cursor_m);
			activated = true;
			openingline->SetText("");
			cursor->ToggleVisibility();
			choice[0]->SetText("NEW GAME");
			choice[1]->SetText("LOAD GAME");
		}
	}
	else {
		timer += DTime;
		if (ThisKeyPressed(SDL_SCANCODE_Z)) {
			if (flipper) {
				printf("new game");
			}
			else {
				if (true) // TODO: Add variable checking if a game has been saved
					cAudio->PlaySound(s_cursor_e);
					printf("Load game");
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
