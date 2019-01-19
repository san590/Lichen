#include "Grid.h"


void Grid::create(int how_many){

	for (int x = 0; x < how_many; x++)
	{
		CellVector.push_back(std::vector<Cell>());

		for (int y = 0; y < how_many; y++)
		{
			CellVector[x].push_back(Cell(x*CELL_SIDE,y*CELL_SIDE,1,0));
		}
		
	}
}

void Grid::draw(int how_many, sf::RenderWindow &window)
{
	for (int x = 0; x < how_many; x++)
		for (int y = 0; y < how_many; y++)
			CellVector[x][y].draw(window);
}

