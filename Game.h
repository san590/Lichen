#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "SFML/Graphics.hpp"
#include "definitions.h"
#include "Grid.h"
#include "Cell.h"

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
	bool pause;
	void HideConsole();
	void wait(float seconds);
};

