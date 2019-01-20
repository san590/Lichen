#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Grid.h"
#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "MY_DEFINITONS.h"
#include <time.h>

class Game
{
private:
	sf::Image icon;
	sf::RenderWindow window;
	sf::Event event;
	int quantity;
	bool running;
	Grid grid;

public:
	Game();
	void GetParameters();
	void Run();
	void EventHandler();
	bool isRunning();
	void HideConsole();
	void wait(float seconds);
};

