#pragma once
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"
#include <iostream>

class ScoreView
{
	SudokuBoard board;
	sf::RectangleShape background;
	sf::Text gameResult;
	sf::Text pressSpace;
	sf::Font gameResultFont;
	sf::Font pressSpaceFont;
public:
	ScoreView(SudokuBoard & b);
	void draw(sf::RenderWindow &win);
};

