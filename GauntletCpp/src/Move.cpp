#include "Move.h"

Move::Move(std::string name, std::string description, int accuracy, int power)
	: _name(name)
	, _description(description)
	, _accuracy(accuracy)
	, _power(power)
{
}