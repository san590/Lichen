#include "Game.h"
#include <Windows.h>
Game::Game() {

	icon.loadFromFile("Resources/graph/icon.png");
	setlocale(LC_ALL, "");
	running = 1;
	std::cout << "---Liszaj---";
	std::cout << std::endl;
	std::cout << "Wymagania dotycz¹ce iloœci komórek na bok: liczba nieparzysta wiêksza od 5 i mniejsza od 27";
	std::cout << std::endl << std::endl << std::endl;
}


void Game::GetParameters() {

	while (1) {
		std::cout << "Podaj, jak du¿o komórek chcesz mieæ: "; //przerobiæ na jakieœ lepsze pytanie
		std::cin >> quantity;

		if (quantity % 2 == 1 && quantity > 5 && quantity < 27)
			break;

		std::cout << std::endl << std::endl << std::endl;
		std::cout << "Poda³eœ b³êdne wartoœci, chcesz spróbowaæ jeszcze raz? (Yes\\Tak) ";

		char sign;
		std::cin.clear();
		std::cin.ignore();
		std::cin.get(sign);

		if (sign == 'T' || sign == 't' || sign == 'Y' || sign == 'y')
			system("CLS"); //czyszczenie konsoli
		else
			exit(0);

		std::cout << "---Liszaj---";
		std::cout << std::endl;
		std::cout << "Wymagana iloœæ komórek na bok: liczba nieparzysta wiêksza od 5 i mniejsza od 27";
		std::cout << std::endl << std::endl << std::endl;

	}

	Run();
	
}

void Game::Run() {

	HideConsole();
	window.create(sf::VideoMode(quantity*CELL_SIDE, quantity*CELL_SIDE), "Lichen");
	window.setIcon(215, 214, icon.getPixelsPtr());
	window.requestFocus();
	EventHandler();

}


//
void Game::EventHandler() {

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				//pauza na spacji
				window.clear(sf::Color::White);
				//	grid.draw(window);
				window.display();
			}

			running = 0;

		}
	}
}

bool Game::isRunning() {
	return running;
}

void Game::HideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}