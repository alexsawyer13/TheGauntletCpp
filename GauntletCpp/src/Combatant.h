#pragma once

#include "Move.h"

#include <string>
#include <iostream>
#include <vector>

class Combatant
{
private:
	std::string _name;
	int _maxHealth;
	int _health;
	int _attack;
	int _defence;
	int _speed;

	std::vector<Move> _moves;

	std::string _itemsApplied;
public:
	Combatant(std::string name, int health, int attack, int defence, int speed, std::vector<Move> moves);
	~Combatant();

	std::string GetName();
	int GetMaxHealth();
	int GetHealth();
	int GetAttack();
	int GetDefence();
	int GetSpeed();

	void AddHealth(int amt);
	void AddAttack(int amt);
	void AddDefence(int amt);
	void AddSpeed(int amt);

	void ApplyItem(std::string name, std::string desc);

	friend std::ostream& operator<<(std::ostream& os, Combatant c);
};

