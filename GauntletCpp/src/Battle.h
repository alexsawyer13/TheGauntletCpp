#pragma once

#include "Combatant.h"

class Battle
{
private:
	Combatant* _player;
	Combatant* _enemy;
	
	int _round;
public:
	Battle(Combatant* player);

	void Display();

	void Loop();
	void CreateEnemy();
	void PlayerAttack();
	void EnemyAttack();
};

