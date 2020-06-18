#pragma once

#include "Item.h"
#include "Input.h"

class ItemContainer
{
private:
	const int NUM_ITEMS = 4;
public:
	Item* HealthBoost() { return new Item("+50 Health Boost", "Health increased by 50", [](Combatant& c) {c.AddHealth(50); }); }
	Item* AttackBoost() { return new Item("+2 Attack Boost", "Attack increased by 2", [](Combatant& c) { c.AddAttack(2); }); }
	Item* DefenceBoost() { return new Item("+2 Defence Boost", "Defence increased by 2", [](Combatant& c) { c.AddDefence(2); });  }
	Item* SpeedBoost() { return new Item("+2 Speed Boost", "Speed increased by 2", [](Combatant& c) { c.AddSpeed(2); });  }

	Item* GetItem(int index)
	{
		switch (index)
		{
		case 1: return HealthBoost(); break;
		case 2: return AttackBoost(); break;
		case 3: return DefenceBoost(); break;
		case 4: return SpeedBoost(); break;
		default: return HealthBoost(); break;
		}
	}

	Item* RandItem()
	{
		return GetItem(input::RandInt(1, NUM_ITEMS));
	}
};