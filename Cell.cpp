#include "Cell.h"

Cell::Cell(int x, int y, bool alive, bool immune)
{
	cellShape = sf::RectangleShape(sf::Vector2f(CELL_SIDE, CELL_SIDE));
	cellShape.setOutlineThickness(-0.5);
	cellShape.setOutlineColor(GREY);
	cellShape.setPosition(x, y);
	this->alive = alive;
	this->immune = immune;

	setColour();
}

void Cell::setTimeInfected(int timeInfected) {
	this->timeImmune = timeInfected;
};

void Cell::setTimeImmune(int timeImmune) {
	this->timeImmune = timeImmune;
};


void Cell::setAlive(bool alive, sf::RenderWindow &window)
{
	this->alive = alive;
	draw(window);
}

void Cell::setImmune(bool immune, sf::RenderWindow &window)
{
	this->immune = immune;
	draw(window);
}

int Cell::changeTimeImmune() {
	timeImmune--;

	if (timeImmune != 0)
		return 1;
	else
		return 0;
}

int Cell::changeTimeInfected() {
	timeInfected--;

	if (timeInfected != 0)
		return 1;
	else
		return 0;
}

void Cell::setColour()
{
	if (alive)
		cellShape.setFillColor(BLACK);
	else if (immune)
		cellShape.setFillColor(LIGHT_GREY);
	else
		cellShape.setFillColor(WHITE);
}

void Cell::draw(sf::RenderWindow &window) {
	window.draw(cellShape);
}

int Cell::getTimeInfected() {
	return timeInfected;
}

int Cell::getTimeImmune() {
	return timeImmune;
}

bool Cell::isAlive() {
	return alive;
}

bool Cell::isImmune() {
	return immune;
}


