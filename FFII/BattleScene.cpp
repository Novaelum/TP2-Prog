#include "BattleScene.h"


BattleScene::BattleScene()
	: background(new Sprite(t_battle_bg, point<int>(22, 15), point<int>(240, 128)))
	, bar(new Sprite(t_battle_bar))
	, choicesBg(new Sprite(t_battle_chs_bg))
	, chc(0)
	, currentChar(0)
	, battleMode(BM_Action)
	, target(0)
	, actionDone(true)
	, enemyAttackDone(false)
	, enemyAttackComplete(false)
	, deadCount(0)
{
	cAudio->PlayMusic(m_battle_1);
	background->ResizeTo(900, 450);
	bar->SetPosition(0, 450);
	choicesBg->SetPosition(150, 450);

	for (int i = 0; i < 4; ++i) {
		enemies[i] = new Sprite(t_bestiary, point<int>(290, 680), point<int>(42, 42));
		enemies[i]->Scale(3.75f);
	}

	enemies[0]->SetPosition(100, 100);
	enemies[1]->SetPosition(225, 100);
	enemies[2]->SetPosition(100, 225);
	enemies[3]->SetPosition(225, 225);

	enemiesNames = new Text("Black Knight   4", f_ffta_55);
	enemiesNames->SetPosition(15, 445);

	cEngine->MoveBack(choicesBg);

	for (int i = 0; i < currentPlayer->GetPartySize(); ++i) {
		int x = 660 + i * 30;
		int y = 150 + i * 65;
		if (currentPlayer->GetParty().at(i)->row == R_BACK) {
			x += 30;
		}
		party[i] = currentPlayer->GetParty().at(i)->state;
		party[i].charSheet->SetVisibility(true);
		party[i].charSheet->SetPosition(x, y);
		cEngine->MoveBack(party[i].charSheet);
		cEngine->MoveBack(party[i].attack);
	}

	choices[0] = new Text("Attack", f_ffta_55);
	choices[0]->SetPosition(270, 445);
	choices[1] = new Text("Magic", f_ffta_55);
	choices[1]->SetPosition(270, 475);
	choices[2] = new Text("Items", f_ffta_55);
	choices[2]->SetPosition(270, 505);
	choices[3] = new Text("Flee", f_ffta_55);
	choices[3]->SetPosition(270, 535);

	cursor = hand_cursor;
	cursor->ToggleVisibility();
	cursor->SetPosition(choices[0]->GetPosition().x - 80, choices[0]->GetPosition().y + 20);
	cEngine->MoveBack(cursor);

	party[0].charSheet->SetPosition(630, 150);
	party[0].action = CA_MovingForward;

	for (int i = 0; i < currentPlayer->GetPartySize(); ++i) {
		int y = 445 + i * 30;
		names[i] = new Text(currentPlayer->GetParty().at(i)->name, f_ffta_55, 55, point<int>(405, y), 0, Color::WHITE, OpNone);
		currentHP[i] = new Text(std::to_string(currentPlayer->GetParty().at(i)->stats.cHP) + "\/", f_ffta_55, 55, point<int>(575, y), 0, Color::WHITE, OpNone);
		maxHP[i] = new Text(std::to_string(currentPlayer->GetParty().at(i)->stats.mHP), f_ffta_55, 55, point<int>(705, y), 0, Color::WHITE, OpNone);
		currentMP[i] = new Text(std::to_string(currentPlayer->GetParty().at(i)->stats.cMP), f_ffta_55, 55, point<int>(835, y), 0, Color::WHITE, OpNone);
	}
}


BattleScene::~BattleScene() {

}

void BattleScene::Update() {
	switch(battleMode) {
	case(BM_Action): {
		if (ThisKeyPressed(SDL_SCANCODE_UP)) {
			cAudio->PlaySound(s_cursor_m);
			chc--;
			if (chc < 0) {
				chc = 3;
			}
			cursor->SetPosition(choices[chc]->GetPosition().x - 80, choices[chc]->GetPosition().y + 20);
		}
		if (ThisKeyPressed(SDL_SCANCODE_DOWN)) {
			cAudio->PlaySound(s_cursor_m);
			chc++;
			if (chc > 3) {
				chc = 0;
			}
			cursor->SetPosition(choices[chc]->GetPosition().x - 80, choices[chc]->GetPosition().y + 20);
		}
		if (ThisKeyPressed(SDL_SCANCODE_Z)) {
			int cC = currentChar;
			switch (chc) {
				// Attack
			case(0) :
				cAudio->PlaySound(s_cursor_m);
				battleMode = BM_Targetting;
				cursor->SetPosition(enemies[target]->GetPosition().x + enemies[target]->GetSize().x, enemies[target]->GetPosition().y + enemies[target]->GetSize().y / 2);
				cursor->Flip(flip_h);
				break;
				// Magic
			case(1) :
				cAudio->PlaySound(s_cursor_e);
				break;
				// Items;
			case(2) :
				cAudio->PlaySound(s_cursor_e);
				break;
				// Flee
			case(3) :
				cAudio->PlaySound(s_cursor_m);
				party[currentChar].isFleeing = true;
				party[currentChar].isReady = true;
				MovingB(currentChar);
				currentChar++;
				break;
			}
			if (currentChar == currentPlayer->GetPartySize()) {
				currentChar = 0;
				battleMode = BM_Acting;
				FlipMode();
			}
			else if (cC != currentChar) {
				MovingF(currentChar);
			}
		}
		if (ThisKeyPressed(SDL_SCANCODE_X)) {
			if (currentChar - 1 < 0) {
				cAudio->PlaySound(s_cursor_e);
			}
			else {
				cAudio->PlaySound(s_cursor_b);
				MovingB(currentChar);
				currentChar--;
				if (party[currentChar].action == CA_Fleeing) {
					party[currentChar].isFleeing = false;
					party[currentChar].charSheet->Flip(flip_n);
				}
				party[currentChar].isReady = false;
				MovingF(currentChar);
			}
		}
		break;
	}
	case(BM_Targetting) : {
		if (ThisKeyPressed(SDL_SCANCODE_DOWN) || ThisKeyPressed(SDL_SCANCODE_UP)) {
			cAudio->PlaySound(s_cursor_m);
			switch (target) {
			case(0) :
				target += 2;
				break;
			case(1) :
				target += 2;
				break;
			case(2) :
				target -= 2;
				break;
			case(3) :
				target -= 2;
				break;
			}
			cursor->SetPosition(enemies[target]->GetPosition().x + enemies[target]->GetSize().x, enemies[target]->GetPosition().y + enemies[target]->GetSize().y / 2);
		}
		if (ThisKeyPressed(SDL_SCANCODE_RIGHT) || ThisKeyPressed(SDL_SCANCODE_LEFT)) {
			cAudio->PlaySound(s_cursor_m);
			switch (target) {
			case(0) :
				target++;
				break;
			case(1) :
				target--;
				break;
			case(2) :
				target++;
				break;
			case(3) :
				target--;
				break;
			}
			cursor->SetPosition(enemies[target]->GetPosition().x + enemies[target]->GetSize().x, enemies[target]->GetPosition().y + enemies[target]->GetSize().y / 2);
		}
		if (ThisKeyPressed(SDL_SCANCODE_X)) {
			cAudio->PlaySound(s_cursor_b);
			battleMode = BM_Action;
			cursor->SetPosition(choices[chc]->GetPosition().x - 80, choices[chc]->GetPosition().y + 20);
			cursor->Flip(flip_n);
			break;
		}
		if (ThisKeyPressed(SDL_SCANCODE_Z)) {
			cAudio->PlaySound(s_cursor_m);
			MovingB(currentChar);
			battleMode = BM_Action;
			party[currentChar].isReady = true;
			party[currentChar].nextAction = CA_Attacking;
			party[currentChar].target = target;
			cursor->SetPosition(choices[chc]->GetPosition().x - 80, choices[chc]->GetPosition().y + 20);
			cursor->Flip(flip_n);
			currentChar++;
			if (currentChar == currentPlayer->GetPartySize()) {
				currentChar = 0;
				battleMode = BM_Acting;
				FlipMode();
			}
			else {
				MovingF(currentChar);
			}
			break;
		}
		break;
	}
	case(BM_Acting) : {
		if (actionDone) {
			if (party[currentChar].action != CA_Fleeing) {
				switch (party[currentChar].nextAction) {
					case(CA_Attacking) : {
						MovingF(currentChar);
						actionDone = false;
						party[currentChar].isAttacking = true;
					}
				}
			}
			else {
				party[currentChar].isFleeing = false;
				party[currentChar].charSheet->Flip(flip_n);
				party[currentChar].action = CA_Idle;
				party[currentChar].changed = true;
				party[currentChar].isReady = false;
				currentChar++;
				actionDone = true;
				if (currentChar > 3) {
					currentChar = 0;
					battleMode = BM_Enemy;
				}
			}
		}
		else {
			if (party[currentChar].action == CA_Idle) {
				party[currentChar].isReady = false;
				currentChar++;
				actionDone = true;
				
				if (currentChar > 3) {
					currentChar = 0;
					battleMode = BM_Enemy;
				}
			}
		}
		break;
	}
	case(BM_Enemy) : {
		if (!enemyAttackDone) {
			enemyAttackComplete = false;
			enemyAttackDone = true;
			int eTarget;
			switch (currentChar) {
			case(0) :
				eTarget = 1;
				break;
			case(1) :
				eTarget = 2;
				break;
			case(2) :
				eTarget = 0;
				break;
			case(3) :
				eTarget = 3;
				break;
			}
			int damage = rand() % 700 + 600;
			AttackPlayer(eTarget, damage);
		}
		else {
			if (enemyAttackComplete) {
				currentChar++;
				enemyAttackDone = false;
				if (currentChar > 3) {
					currentChar = 0;
					battleMode = BM_Action;
					FlipMode();
				}
			}
		}
		break;
	}
	}
	for (int i = 0; i < currentPlayer->GetPartySize(); ++i) {
		switch (party[i].action) {
			if (party[i].changed) {
				party[i].changed = false;
		case(CA_Idle) :
			if (!party[i].isReady) {
				party[i].charSheet->SetSrcFrame(party[i].idle);
				party[i].charSheet->ResizeTo(party[i].idle->w, party[i].idle->h);
				party[i].charSheet->Scale(3.75f);
			}
			else {
				party[i].charSheet->SetSrcFrame(party[i].ready);
				party[i].charSheet->ResizeTo(party[i].ready->w, party[i].ready->h);
				party[i].charSheet->Scale(3.75f);
			}
			break;
		case(CA_Dead) :
			party[i].charSheet->SetSrcFrame(party[i].dead);
			party[i].charSheet->ResizeTo(party[i].dead->w, party[i].dead->h);
			party[i].charSheet->Scale(3.75f);
			break;
			}
		case(CA_MovingForward) :
			party[i].currentTime += DTime;
			if (party[i].currentTime >= 1.0f / 20) {
				party[i].charSheet->SetSrcFrame(party[i].idle);
				party[i].charSheet->ResizeTo(party[i].idle->w, party[i].idle->h);
				party[i].charSheet->Scale(3.75f);
				party[i].charSheet->SetPosition(party[i].charSheet->GetPosition().x - 30, party[i].charSheet->GetPosition().y);
				party[i].currentTime = 0;
				if (!party[i].isAttacking) {
					party[i].action = CA_Idle;
					party[i].changed = true;
				}
				else {
					party[i].action = CA_Attacking;
					party[i].charSheet->ToggleVisibility();
					party[i].attack->ToggleVisibility();
					party[i].attack->SetPosition(party[i].charSheet->GetPosition().x - 30, party[i].charSheet->GetPosition().y);
					party[i].attack->Play();
				}
			}
			break;
		case(CA_MovingBack) :
			party[i].currentTime += DTime;
			if (party[i].currentTime >= 1.0f / 20) {
				party[i].charSheet->SetSrcFrame(party[i].idle);
				party[i].charSheet->ResizeTo(party[i].idle->w, party[i].idle->h);
				party[i].charSheet->Scale(3.75f);
				party[i].charSheet->SetPosition(party[i].charSheet->GetPosition().x + 30, party[i].charSheet->GetPosition().y);
				if (!party[i].isFleeing) {
					party[i].currentTime = 0;
					party[i].charSheet->Flip(flip_n);
					party[i].action = CA_Idle;
					party[i].changed = true;
				}
				else {
					party[i].action = CA_Fleeing;
				}
			}
			break;
		case(CA_Fleeing) :
			party[i].currentTime += DTime;
			if (party[i].currentTime >= 1.0f / 12) {
				party[i].currentTime = 0;
				party[i].isFleeing = !party[i].isFleeing;
				if (party[i].isFleeing) {
					party[i].charSheet->SetSrcFrame(party[i].idle);
					party[i].charSheet->ResizeTo(party[i].idle->w, party[i].idle->h);
					party[i].charSheet->Scale(3.75f);
				}
				else {
					party[i].charSheet->SetSrcFrame(party[i].move);
					party[i].charSheet->ResizeTo(party[i].move->w, party[i].move->h);
					party[i].charSheet->Scale(3.75f);
				}
			}
			break;
		case(CA_Hit) :
			party[i].currentTime += DTime;
			if (party[i].currentTime >= 0.8f) {
				if (currentPlayer->GetParty().at(i)->stats.cHP > 0) {
					party[i].action = CA_Idle;
				}
				else {
					party[i].action = CA_Dead;
					names[i]->SetColor({ 200, 200, 200 });
					currentHP[i]->SetColor({ 200, 200, 200 });
					maxHP[i]->SetColor({ 200, 200, 200 });
					currentMP[i]->SetColor({ 200, 200, 200 });
					deadCount++;
					if (deadCount == currentPlayer->GetPartySize()) {
						cEngine->DeleteComponent(background);
						cEngine->DeleteComponent(bar);
						cEngine->DeleteComponent(choicesBg);
						cEngine->DeleteComponent(enemiesNames);
						for (int i = 0; i < currentPlayer->GetPartySize(); ++i) {
							cEngine->DeleteComponent(party[i].charSheet, false);
							cEngine->DeleteComponent(party[i].attack, false);
							cEngine->DeleteComponent(names[i]);
							cEngine->DeleteComponent(currentHP[i]);
							cEngine->DeleteComponent(maxHP[i]);
							cEngine->DeleteComponent(currentMP[i]);
						}
						cursor->SetVisibility(false);
						for (int j = 0; j < 4; ++j) {
							cEngine->DeleteComponent(enemies[j]);
						}
						cEngine->DeleteComponent(this);
						new Text("Game Over", f_mainfont, point<int>(370, 220), 0, Color::WHITE, OpFadeIn);
						cAudio->PlayMusic(m_gameover, 1);
						new Text("(Well, not really, the game usually start here, but it's as far as this demo go for now)", f_mainfont, point<int>(170, 320), 600, Color::WHITE, OpFadeIn);
					}
				}
				party[i].changed = true;
				enemyAttackComplete = true;
			}
			break;
		case(CA_Attacking) :
			if (!party[i].attack->GetIsPlaying()) {
				party[i].currentTime += DTime;
				if (party[i].currentTime >= 1.0f / 12) {
					party[i].isAttacking = false;
					party[i].charSheet->ToggleVisibility();
					party[i].attack->ToggleVisibility();
					party[i].action = CA_MovingBack;
					party[i].currentTime = 0;
				}
			}
			break;
		}
	}
}

void BattleScene::Kill() {
	delete this;
}

void BattleScene::Hit(int index) {
	party[index].action = CA_Hit;
	party[index].charSheet->SetSrcFrame(party[index].hit);
	party[index].charSheet->ResizeTo(party[index].hit->w, party[index].hit->h);
	party[index].charSheet->Scale(3.75f);
}

void BattleScene::MovingF(int index) {
	party[index].action = CA_MovingForward;
	party[index].charSheet->SetSrcFrame(party[index].move);
	party[index].charSheet->ResizeTo(party[index].move->w, party[index].move->h);
	party[index].charSheet->Scale(3.75f);
	party[index].charSheet->SetPosition(party[index].charSheet->GetPosition().x - 30, party[index].charSheet->GetPosition().y);
}

void BattleScene::MovingB(int index) {
	party[index].action = CA_MovingBack;
	party[index].charSheet->Flip(flip_h);
	party[index].charSheet->SetSrcFrame(party[index].move);
	party[index].charSheet->ResizeTo(party[index].move->w, party[index].move->h);
	party[index].charSheet->Scale(3.75f);
	party[index].charSheet->SetPosition(party[index].charSheet->GetPosition().x + 30, party[index].charSheet->GetPosition().y);
}

void  BattleScene::AttackPlayer(int target, int damage) {
	Hit(target);
	currentPlayer->GetParty().at(target)->stats.cHP -= damage;
	if (currentPlayer->GetParty().at(target)->stats.cHP < 0) {
		currentPlayer->GetParty().at(target)->stats.cHP = 0;
	}
}

void BattleScene::FlipMode() {
	for (int i = 0; i < 4; ++i) {
		choices[i]->ToggleVisibility();
	}
	choicesBg->ToggleVisibility();
	cursor->ToggleVisibility();
}
