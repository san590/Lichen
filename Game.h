#pragma once
#include "SFML/Graphics.hpp"
#include "Cell.h"
#include <iostream>
#include <list>

class Game
{
public:

	int wrapValue(int v, int vMax);
	void start();
};

