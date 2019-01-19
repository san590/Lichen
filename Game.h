#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "MY_DEFINITONS.h"

class Game
{
private:
	sf::Image icon;
	sf::RenderWindow window;
	sf::Event event;
	int quantity;
	bool running;

public:
	Game();
	void GetParameters();
	void Run();
	void EventHandler();
	bool isRunning();
	void HideConsole();
};

