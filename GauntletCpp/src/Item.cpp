#include "Item.h"

Item::Item()
	: _name("none")
	, use_item([](Combatant& c) {})
{
}

Item::Item(std::string name, std::string description,  std::function<void(Combatant&)> use_item)
	: _name(name)
	, _description(description)
	, use_item(use_item)
{
}

void Item::UseItem(Combatant* c)
{
	use_item(*c);
	c->ApplyItem(_name, _description);
}