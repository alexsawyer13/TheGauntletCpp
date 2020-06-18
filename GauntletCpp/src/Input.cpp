#include "Input.h"

#include <conio.h>
#include <stdlib.h>
#include <time.h>

namespace input
{
	char GetInput(char* validInputs)
	{
		char input;

		bool valid = false;
		while (!valid)
		{
			input = _getch();
			for (int i = 0; i < sizeof(validInputs) / sizeof(validInputs[0]); i++)
			{
				if (input == validInputs[i])
					valid = true;
			}
		}

		delete[] validInputs;

		return input;
	}

	int CharToInt(char c) { return (int)(c - '0'); }

	void Continue() { _getch(); }

	int RandInt(int min, int max)
	{
		static bool seeded = false;
		if (!seeded)
		{
			srand(time(NULL));
			seeded = true;
		}
		return rand() % (max - min + 1) + min;
	}

	std::string Repeat(std::string str, int num)
	{
		std::string output = "";
		for (int i = 0; i < num; i++)
		{
			output += str;
		}
		return output;
	}

	std::string Spaces(int num)
	{
		return Repeat(" ", num);
	}
}