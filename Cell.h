#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "MY_DEFINITONS.h"

class Cell
{
public:
	Cell(int x, int y, bool alive, bool immune);
	void setAlive(bool alive);
	void setImmune(int timeImmune);
	void setColour();
	void draw(sf::RenderWindow &window);
	int getTimeInfected();
	int getTimeImmune();
	void setTimeInfected(int timeInfected);
	void setTimeImmune(int timeImmune);
	void changeTimeInfected(int timeImmune);
	void changeTimeImmune();
	bool isAlive();
	bool isImmune();
	
private:

	int timeInfected;
	int timeImmune;
	bool alive;
	bool immune;
	sf::RectangleShape cellShape;

};


