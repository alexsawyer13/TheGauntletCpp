#pragma once

#include "Overworld.h"
#include "Battle.h"

class Game
{
private:
	Combatant* _player;
	Overworld* _overworld;
	Battle* _battle;

	void ChooseClass();
	void StartOverworld();
	void StartBattle();
public:
	Game();
	~Game();

	void Start();
};

