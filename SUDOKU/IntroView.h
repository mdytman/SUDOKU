#pragma once
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"

class IntroView
{
	SudokuBoard board;
	sf::RectangleShape background;
	sf::Font sudokuFont;
	sf::Font gameModeFont;
	sf::Text sudokuText;
	sf::Text gameModeText[4];
	sf::RectangleShape gameModeRect[4];
	sf::RectangleShape start;
public:
	IntroView(SudokuBoard & sudokuBoard);
	void draw(sf::RenderWindow & win);
};

