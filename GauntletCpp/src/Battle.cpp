#include "Battle.h"
#include "Input.h"
#include "MoveContainer.h"

#include <iostream>
#include <string>
#include <windows.h>

Battle::Battle(Combatant* player)
	: _player(player)
	, _round(0)
{
}

void Battle::Loop()
{
	CreateEnemy();
	while (_player->GetHealth() > 0)
	{
		Display();
		PlayerAttack();
		EnemyAttack();
	}
}

void Battle::CreateEnemy()
{
	_round++;

	std::string enemyName = "Enemy " + std::to_string(_round);
	int enemyHealth = 100;
	int enemyAttack = 10;
	int enemyDefence = 10;
	int enemySpeed = 10;

	delete _enemy;

	MoveContainer* c = new MoveContainer();
	_enemy = new Combatant(enemyName, enemyHealth, enemyAttack, enemyDefence, enemySpeed, c->GetMoves(new int[2]{ 1, 2 }));
	delete c;
}

void Battle::PlayerAttack()
{
	int move = input::CharToInt(input::GetInput(new char[4]{ '1', '2', '3', '4' }));
}

void Battle::EnemyAttack()
{

}

void Battle::Display()
{
	system("CLS");

	const int boxSize = 15; // Size of 'box' each combatant is in

	const std::string player = "|:]";
	const std::string enemy = ">:{";

	const int playerLen = player.length();
	const int enemyLen = enemy.length();

	const std::string playerName = _player->GetName();
	const int playerNameLength = playerName.length();

	const std::string enemyName = _enemy->GetName();
	const int enemyNameLength = enemyName.length();

	const std::string playerHealth = std::to_string(_player->GetHealth());
	const int playerHealthLength = playerHealth.length();

	const std::string enemyHealth = std::to_string(_enemy->GetHealth());
	const int enemyHealthLength = enemyHealth.length();

	// First line
	std::string pGap = input::Spaces(round((boxSize - playerLen) / 2));
	std::string eGap = input::Spaces(round((boxSize - enemyLen) / 2));
	std::cout << pGap << player << pGap << eGap << enemy << eGap << std::endl;

	// Second line
	pGap = input::Spaces(round((boxSize - playerNameLength) / 2));
	eGap = input::Spaces(round((boxSize - enemyNameLength) / 2));
	std::cout << pGap << playerName << pGap << eGap << enemyName << eGap << std::endl;

	// Third line
	pGap = input::Spaces(round((boxSize - playerHealthLength) / 2));
	eGap = input::Spaces(round((boxSize - enemyHealthLength) / 2));
	std::cout << pGap << playerHealth << pGap << eGap << enemyHealth << eGap << std::endl;
}