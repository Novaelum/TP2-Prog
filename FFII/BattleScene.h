#pragma once
#include "Libraries.h"

class BattleScene:
	public Component
{

	enum BattleMode {
		BM_Action,
		BM_Targetting,
		BM_Enemy,
		BM_Acting
	};

	struct BKnight {
		Sprite* sprite;
		int health = 1140;
	};


public:
	BattleScene();
	~BattleScene();

	void Update();
	void Kill();

private:
	Sprite* background;
	Sprite* cursor;
	Sprite* bar;
	Sprite* choicesBg;
	BattleState party[4];
	BKnight enemies[4];
	bool enemyAttackDone;
	bool enemyAttackComplete;

	Text* damageFeedback;

	Text* enemiesNames;
	Text* choices[4];

	Text* names[4];
	Text* currentHP[4];
	Text* maxHP[4];
	Text* currentMP[4];

	int chc;
	int currentChar;
	int target;
	int deadCount;
	bool actionDone;

	void Hit(int index);
	void Dead();
	void MovingF(int index);
	void MovingB(int index);

	void AttackPlayer(int target, int damage);
	void AttackEnemy(int damage);

	void FlipMode();

	BattleMode battleMode;
};

