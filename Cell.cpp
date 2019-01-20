#include "Cell.h"

Cell::Cell(int x, int y, bool alive, bool immune)
{
	cellShape = sf::RectangleShape(sf::Vector2f(CELL_SIDE, CELL_SIDE));
	cellShape.setOutlineThickness(1);
	cellShape.setOutlineColor(GREY);
	cellShape.setPosition(x, y);
	this->alive = alive;
	this->immune = immune;

}

void Cell::setTimeInfected(int timeInfected) {
	this->timeInfected = timeInfected;
};

void Cell::setTimeImmune(int timeImmune) {
	this->timeImmune = timeImmune;
};


void Cell::setAlive(bool alive)
{
	immune = 0;
	this->alive = alive;
}

void Cell::setImmune(int timeImmune)
{
	alive = 1;
	immune = 1;

	setTimeImmune(timeImmune);
}


void Cell::changeTimeImmune() {

	timeImmune--;
	if (timeImmune == 0)
		immune = 0;
}

void Cell::changeTimeInfected(int timeImmune) {

	timeInfected--;
	
	if (timeInfected == 0) {
		setImmune(timeImmune);
	}
}

void Cell::setColour()
{
	if (alive && !immune)
		cellShape.setFillColor(WHITE);
	else if (immune)
		cellShape.setFillColor(LIGHT_GREY);
	else
		cellShape.setFillColor(BLACK);
}

void Cell::draw(sf::RenderWindow &window) {
	setColour();
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


