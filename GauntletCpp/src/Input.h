#pragma once

#include <string>

namespace input
{
	char GetInput(char* validInputs);
	int CharToInt(char c);

	void Continue();

	int RandInt(int min, int max);

	std::string Repeat(std::string str, int num);
	std::string Spaces(int num);
}