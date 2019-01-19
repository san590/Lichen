#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "MY_DEFINITONS.h"

class Cell
{
public:
	Cell(int x, int y, bool alive, bool immune);
	void setAlive(bool alive, sf::RenderWindow &window);
	void setImmune(bool immune, sf::RenderWindow &window);
	void setColour();
	void draw(sf::RenderWindow &window);
	int getTimeInfected();
	int getTimeImmune();
	void setTimeInfected(int timeInfected);
	void setTimeImmune(int timeImmune);
	int changeTimeInfected();
	int changeTimeImmune();
	bool isAlive();
	bool isImmune();
	
private:

	int timeInfected;
	int timeImmune;
	bool alive;
	bool immune;
	sf::RectangleShape cellShape;

};


