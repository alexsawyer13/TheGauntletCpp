#pragma once

#include "Combatant.h"

#include <functional>

class Item
{
private:
	std::string _name;
	std::string _description;
	std::function<void(Combatant&)> use_item;
public:
	Item();
	Item(std::string name, std::string description, std::function<void(Combatant&)> use_item);

	void UseItem(Combatant* c);
};