#pragma once
#include "Cell.h"
#include "Game.h"
#include <list>


class Grid
{
public:
	Grid();
	~Grid();

	std::list<std::list<Cell>> CellList;
	void Create(int how_many);
};

