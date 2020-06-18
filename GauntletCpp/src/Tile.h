#pragma once

#include "Item.h"
#include "Combatant.h"

class Tile
{
private:
	char _displayCharacter;
	Item* _item;
public:
	const static char defaultChar = '-';
	const static char chestChar = 'C';
	const static char playerChar = 'P';
	const static char trampledChar = '@';

	Tile();
	~Tile();

	char GetChar();
	void UseItem(Combatant* c);

	void SetChar(char ch);
	void SetItem(Item* item);
};

