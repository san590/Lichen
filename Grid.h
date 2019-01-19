#pragma once
#include "Cell.h"
#include <vector>


class Grid
{
public:
	void create(int how_many);
	void draw(int how_many, sf::RenderWindow &window);

private:
	std::vector<std::vector<Cell>> CellVector;

};

