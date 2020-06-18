#include "Combatant.h"

Combatant::Combatant(std::string name, int health, int attack, int defence, int speed, std::vector<Move> moves)
	: _name(name)
	, _maxHealth(health)
	, _health(health)
	, _attack(attack)
	, _defence(defence)
	, _speed(speed)
	, _moves(moves)
{
}

Combatant::~Combatant()
{

}

std::string Combatant::GetName() { return _name; }
int Combatant::GetMaxHealth() { return _maxHealth; }
int Combatant::GetHealth() { return _health; }
int Combatant::GetAttack() { return _attack; }
int Combatant::GetDefence() { return _defence; }
int Combatant::GetSpeed() { return _speed; }

void Combatant::AddHealth(int amt) { _maxHealth += amt; _health += amt; }
void Combatant::AddAttack(int amt) { _attack += amt; }
void Combatant::AddDefence(int amt) { _defence += amt; }
void Combatant::AddSpeed(int amt) { _speed += amt; }

void Combatant::ApplyItem(std::string name, std::string desc)
{
	_itemsApplied += name;
	_itemsApplied += ": ";
	_itemsApplied += desc;
	_itemsApplied += '\n';
}

std::ostream& operator<<(std::ostream& os, Combatant c)
{
	os << "Items applied:" << std::endl;
	os << c._itemsApplied << std::endl;
	os << "Your new stats are:" << std::endl;
	os << "Max health: " << c._health << std::endl;
	os << "Current health: " << c._maxHealth << std::endl;
	os << "Attack: " << c._attack << std::endl;
	os << "Defence: " << c._defence << std::endl;
	os << "Speed: " << c._speed << std::endl;
	return os;
}