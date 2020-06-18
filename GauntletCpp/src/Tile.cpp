#include "Tile.h"

Tile::Tile()
	: _displayCharacter(defaultChar)
	, _item(nullptr)
{
}

Tile::~Tile()
{
	delete _item;
}

char Tile::GetChar() { return _displayCharacter; }

void Tile::UseItem(Combatant* c)
{
	_item->UseItem(c);
}

void Tile::SetChar(char ch) { _displayCharacter = ch; }

void Tile::SetItem(Item* item) { _item = item; }
