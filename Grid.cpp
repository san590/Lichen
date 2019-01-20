#include "Grid.h"

Grid::Grid() {
	srand(time(NULL));
}

Grid::~Grid() {
	std::vector<std::vector<Cell>>().swap(CellVector);
}

void Grid::create(int how_many) {

	int half = how_many / 2;

	for (int x = 0; x < how_many; x++)
	{
		CellVector.push_back(std::vector<Cell>());

		for (int y = 0; y < how_many; y++)
		{
			if (x == half && y == half) {
				CellVector[x].push_back(Cell(x*CELL_SIDE, y*CELL_SIDE, 0, 0));
				CellVector[half][half].setTimeInfected(4);
			}
			else
				CellVector[x].push_back(Cell(x*CELL_SIDE, y*CELL_SIDE, 1, 0));
		}

	}
}


void Grid::draw(int how_many, sf::RenderWindow &window)
{
	for (int x = 0; x < how_many; x++)
		for (int y = 0; y < how_many; y++)
			CellVector[x][y].draw(window);
}

void Grid::modify(int how_many, float probability) {

	int limit = probability * 100;
	int temp; //wartosc pseudogeneratora


	for (int x = 0; x < how_many; x++) {
		for (int y = 0; y < how_many; y++) {

			if (CellVector[x][y].isImmune())
				CellVector[x][y].changeTimeImmune();

			if (!CellVector[x][y].isAlive())
				CellVector[x][y].changeTimeInfected(5);
		}
	}

	std::vector<std::vector<bool>> VecInfected;

	for (int x = 0; x < how_many; x++) {

		VecInfected.push_back(std::vector<bool>());

		for (int y = 0; y < how_many; y++) {

			temp = generate();

			if (x > 0 && !CellVector[x - 1][y].isAlive() && CellVector[x][y].isAlive() && !CellVector[x][y].isImmune() && limit > temp) {
				VecInfected[x].push_back(1);
			}

			else if (x < how_many - 1 && !CellVector[x + 1][y].isAlive() && CellVector[x][y].isAlive() && !CellVector[x][y].isImmune() && limit > temp) {
				VecInfected[x].push_back(1);
			}

			else if (y > 0 && !CellVector[x][y - 1].isAlive() && CellVector[x][y].isAlive() && !CellVector[x][y].isImmune() && limit > temp) {
				VecInfected[x].push_back(1);
			}

			else if (y < how_many - 1 && !CellVector[x][y + 1].isAlive() && CellVector[x][y].isAlive() && !CellVector[x][y].isImmune() && limit > temp) {
				VecInfected[x].push_back(1);
			}

			else
				VecInfected[x].push_back(0);

		}
	}

	for (int x = 0; x < how_many; x++) {
		for (int y = 0; y < how_many; y++) {
			if (VecInfected[x][y] == 1) {
				CellVector[x][y].setAlive(0);
				CellVector[x][y].setTimeInfected(4);
			}
		}
	}

	//zwalnianie pamiêci
	std::vector<std::vector<bool>>().swap(VecInfected);

}


int Grid::generate() {
	return rand() % 99 + 1;
}