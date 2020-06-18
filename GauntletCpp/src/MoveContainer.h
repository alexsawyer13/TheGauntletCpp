#pragma once

#include "Move.h"

#include <vector>

class MoveContainer
{
public:
	Move Punch() { return Move("Punch", "Throws a punch at the target", 90, 30); }
	Move BodySlam() { return Move("Body Slam", "Slams into the target.", 60, 90); }

	Move GetMove(int index)
	{
		switch (index)
		{
		case 1: return Punch(); break;
		case 2: return BodySlam(); break;
		default: return Punch(); break; // Default move is punch
		}
	}

	std::vector<Move> GetMoves(int* indices)
	{
		std::vector<Move> moves;
		
		for (int i = 0; i < sizeof(indices) / sizeof(indices[0]); i++)
		{
			moves.push_back(GetMove(i));
		}

		delete[] indices;

		return moves;
	}
};