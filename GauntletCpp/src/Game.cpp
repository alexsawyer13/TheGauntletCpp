#include "Game.h"
#include "Input.h"
#include "ClassContainer.h"

#include <iostream>

Game::Game()
	: _player(nullptr)
	, _overworld(nullptr)
	, _battle(nullptr)
{
}

Game::~Game()
{
	delete _player;
	delete _overworld;
	delete _battle;
}

void Game::Start()
{
	ChooseClass();
	StartOverworld();
	StartBattle();
}

void Game::ChooseClass()
{
	std::cout << "Which class would you like to choose?" << std::endl;
	std::cout << "[1] Tank" << std::endl;
	std::cout << "[2] Ninja" << std::endl;
	std::cout << "[3] Mage" << std::endl;
	std::cout << "[4] Dark Mage" << std::endl;

	int index = input::CharToInt(input::GetInput(new char[4]{ '1', '2', '3', '4' }));

	ClassContainer c;
	_player = c.GetClass(index); // If index is out of bounds default class is tank
}

void Game::StartOverworld()
{
	_overworld = new Overworld(_player);
	_overworld->Loop();
}

void Game::StartBattle()
{
	_battle = new Battle(_player);
	_battle->Loop();
}