#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"

//

class BoardView
{
	SudokuBoard board;
	sf::RectangleShape background;
	sf::RectangleShape field;
	sf::RectangleShape verticalLines[20];
	sf::RectangleShape horizontalLines[12];
	sf::Text numbers;
	sf::Text newNumbers;
	sf::Text numbersToChoose;
	sf::Text mistakesAmount;
	sf::Font numFont;
	sf::Font mistakesFont;
public:
	BoardView(SudokuBoard & b);
	void changeFieldColour(int y, int x, bool tmp);
	void fillTheField(int y, int x, int n);
	void changeNumberColour(int y, int x, bool tmp); //if move isnt correct         //delete
	void draw(sf::RenderWindow &win);
};

