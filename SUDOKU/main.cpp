#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"
#include "IntroView.h"
#include "IntroController.h"
#include "ScoreView.h"


int main()
{
	srand(time(NULL));
	SudokuBoard sb(900, 900, EASY);
	sb.debug_display();

	IntroView iv(sb);
	IntroController ic(iv, sb);

	ScoreView sv(sb);

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
			//ic.handleEvent(event);
			//gm.handleEvent(event);
		}


		w.clear();
		//iv.draw(w);
		sv.draw(w);
		//gm.draw(w);
		

		w.display();
	}

}


