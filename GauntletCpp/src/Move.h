#pragma once

#include "Combatant.h"

#include <string>

class Move
{
private:
	std::string _name;
	std::string _description;
	int _accuracy;
	int _power;

public:
	Move(std::string name, std::string description, int accuracy, int power);
};