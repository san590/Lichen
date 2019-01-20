#include "LoadingScreen.h"

LoadingScreen::LoadingScreen() {

	background_texture.loadFromFile("Resources/graph/icon.png");

}

void LoadingScreen::resize(int x, int y) {


}

void LoadingScreen::show() {


	


}


void LoadingScreen::wait(float seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}