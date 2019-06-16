#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BoardView.h"
#include "SudokuBoard.h"

class BoardController
{
	bool finished = false;
	BoardView & view;
	SudokuBoard & board;

public:
	explicit BoardController(BoardView & v, SudokuBoard & b);
public:
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};

