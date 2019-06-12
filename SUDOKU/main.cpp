#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"
#include "IntroView.h"


int main()
{
	srand(time(NULL));
	SudokuBoard sb(900, 900, HARD);
	//sb.setNumbers();
	sb.debug_display();

	IntroView iv(sb);

	unsigned int width;
	unsigned int height;

	width = (unsigned)sb.getWindowWidth();
	height = (unsigned)sb.getWindowHeight();

	sf::RenderWindow w{ sf::VideoMode{width, height}, "SUDOKU" };

	w.setFramerateLimit(60);
	sf::Event event;

	while (w.isOpen()) {

		sf::Event event;
		while (w.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				w.close();
			//gm.handleEvent(event);
		}


		w.clear();
		iv.draw(w);
		//gm.draw(w);

		w.display();
	}

}


