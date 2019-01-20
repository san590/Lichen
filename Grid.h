#pragma once
#include "Cell.h"
#include <vector>
#include <cstdlib>
#include <time.h>


class Grid
{
public:
	Grid();
	~Grid();
	void create(int how_many);
	void draw(int how_many, sf::RenderWindow &window);
	void modify(int how_many, float probability);
	int generate();
	
private:
	std::vector<std::vector<Cell>> CellVector;
};

