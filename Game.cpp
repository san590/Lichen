#include "Game.h"

Game::Game() {

	icon.loadFromFile("Resources/graph/icon.png");
	setlocale(LC_ALL, "");
	running = 1;
	pause = 0;
	std::cout << "---Liszaj---";
	std::cout << std::endl;
}


void Game::GetParameters() {

	while (1) {
		
	/*	std::cout << "Domy�lne parametry: \n-wielko�� kom�rki: 50\n-ilo�� kom�rek na bok: 15\n-prawdopodobie�stwo zara�enia s�siedniej kom�rki: 0.5\n";
		std::cout << "-czas czekania: 0,1 sekundy\n-czas bycia zara�onym: 5 jednostek czasu\n-czas bycia odpornym: 5 jednostek czasu";
		std::cout << std::endl << std::endl << std::endl;*/

		std::cout << "Podaj, jak du�o kom�rek chcesz mie�: "; //przerobi� na jakie� lepsze pytanie
		std::cin >> quantity;

		if (quantity % 2 == 1 && quantity > 5 && quantity < 21)
			break;

		std::cout << std::endl << std::endl << std::endl;
		std::cout << "Poda�e� b��dne warto�ci, chcesz spr�bowa� jeszcze raz? (Yes\\Tak) ";

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
		std::cout << "Wymagania dotycz�ce ilo�ci kom�rek na bok: liczba nieparzysta wi�ksza od 5 i mniejsza od 21";
		std::cout << std::endl << std::endl << std::endl;

	}

	Run();

}

void Game::Run() {

	HideConsole();
	window.create(sf::VideoMode(quantity*CELL_SIDE, quantity*CELL_SIDE), "Lichen");
	window.setIcon(215, 214, icon.getPixelsPtr());
	window.requestFocus();
	grid.create(quantity);
	EventHandler();

}



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

					//pauza na spacji
				case sf::Keyboard::Space:
					pause = !pause;
					break;

				case sf::Keyboard::C:
					window.clear(sf::Color::White);
					grid.draw(quantity, window);
				}

			}

		}
		if (!pause){
			window.clear(sf::Color::White);
			grid.draw(quantity, window);	
			window.display();
			wait(0.05);
			grid.modify(quantity, 0.5);
		}

	}
	running = 0;
}

bool Game::isRunning() {
	return running;
}

void Game::HideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void Game::wait(float seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
