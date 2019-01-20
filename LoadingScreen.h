#pragma once

#include <time.h>
#include <SFML/Graphics.hpp>

class LoadingScreen
{
public:
	
	LoadingScreen();
	void resize(int x, int y);
	void show();
	void wait(float seconds);

private:

	sf::Event event;
	sf::Texture background_texture;

};

