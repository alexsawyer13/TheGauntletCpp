#pragma once

#include "Tile.h"
#include "Combatant.h"

#include <iostream>

const int WIDTH = 11; // cols
const int HEIGHT = 11; // rows
const int NUM_CHESTS = 15;

class Overworld
{
private:
	Tile _grid[HEIGHT][WIDTH];
	Combatant* _player;

	int _x, _y;
	int _movesLeft;
public:
	Overworld(Combatant* player);

	void Loop();

	void PlaceItems();
	void Summary();

	void Display();
	void HandleInput();

	void MovePlayer(int x, int y);
};

