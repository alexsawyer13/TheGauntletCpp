#include "Overworld.h"
#include "Item.h"
#include "Input.h"
#include "ItemContainer.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h>

Overworld::Overworld(Combatant* player)
	: _player(player)
	, _x(floor((WIDTH + 1) / 2) - 1)
	, _y(floor((HEIGHT + 1) / 2) - 1)
	, _movesLeft(player->GetSpeed())
{
	_grid[_y][_x].SetChar(_grid[_y][_x].playerChar);
	PlaceItems();
}

void Overworld::Loop()
{
	bool loop = true;
	while (_movesLeft > 0)
	{
		Display();
		HandleInput();
	}
	Summary();
}

void Overworld::PlaceItems()
{
	srand(time(NULL));

	int chestsPlaced = 0;

	ItemContainer c;

	while (chestsPlaced < NUM_CHESTS)
	{
		int x = rand() % WIDTH;
		int y = rand() % HEIGHT;

		if (_grid[y][x].GetChar() == _grid[y][x].defaultChar)
		{
			_grid[y][x].SetChar(_grid[y][x].chestChar);
			_grid[y][x].SetItem(c.RandItem());
			chestsPlaced++;
		}
	}
}

void Overworld::Display()
{
	system("CLS");

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << _grid[i][j].GetChar();
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "You have " << _movesLeft << " moves left" << std::endl;
}

void Overworld::HandleInput()
{
	char input = input::GetInput(new char[4]{ 'w', 'a', 's', 'd' });

	switch (input)
	{
	case 'w':
		MovePlayer(0, -1);
		break;
	case 'a':
		MovePlayer(-1, 0);
		break;
	case 's':
		MovePlayer(0, 1);
		break;
	case 'd':
		MovePlayer(1, 0);
		break;
	default:
		break;
	}
}

void Overworld::MovePlayer(int x, int y)
{
	int newX = _x + x;
	int newY = _y + y;
	char newChar = _grid[newY][newX].GetChar();

	if ((newX >= 0 && newX < WIDTH) && (newY >= 0 && newY < HEIGHT))
	{
		_grid[_y][_x].SetChar(_grid[_y][_x].trampledChar);

		_x = newX;
		_y = newY;

		if (newChar == _grid[_y][_x].chestChar)
		{
			_grid[_y][_x].UseItem(_player);
		}

		_grid[_y][_x].SetChar(_grid[_y][_x].playerChar);

		_movesLeft--;
	}
}

void Overworld::Summary()
{
	system("CLS");
	std::cout << *_player << std::endl << "Press any key to continue";
	input::Continue();
}