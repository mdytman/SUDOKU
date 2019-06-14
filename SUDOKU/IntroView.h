#pragma once
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"

class IntroView
{
	SudokuBoard board;
	sf::RectangleShape background;
	sf::Font sudokuFont;
	sf::Font gameModeFont;
	sf::Font authorFont;
	sf::Text sudokuText;
	sf::Text gameModeText[4];
	sf::Text startText;
	sf::Text author;
	sf::RectangleShape gameModeRect[4];
	sf::RectangleShape start;
public:
	IntroView(SudokuBoard & sudokuBoard);
	void gameModeOutline(int num, bool tmp);
	void draw(sf::RenderWindow & win);
};

