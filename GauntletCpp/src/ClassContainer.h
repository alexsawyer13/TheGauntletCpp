#pragma once

#include "Combatant.h"
#include "Input.h"
#include "MoveContainer.h"

#include <string>

class ClassContainer
{
private:
	MoveContainer* c;
public:
	Combatant* Tank()
	{
		return new Combatant("Tank", 100, 10, 10, 10, c->GetMoves(new int[2]{ 1, 2 }));
	}
	Combatant* Ninja()
	{
		return new Combatant("Ninja", 100, 10, 10, 10, c->GetMoves(new int[2]{ 1, 2 }));
	}
	Combatant* Mage()
	{
		return new Combatant("Mage", 100, 10, 10, 10, c->GetMoves(new int[2]{ 1, 2 }));
	}
	Combatant* DarkMage()
	{
		return new Combatant("Dark Mage", 100, 10, 10, 10, c->GetMoves(new int[2]{ 1, 2 }));
	}

	ClassContainer()
	{
		c = new MoveContainer();
	}

	~ClassContainer()
	{
		delete c;
	}

	Combatant* GetClass(int index)
	{
		switch (index)
		{
		case 1: return Tank(); break;
		case 2: return Ninja(); break;
		case 3: return Mage(); break;
		case 4: return DarkMage(); break;
		default: return Tank(); break;
		}
	}
};