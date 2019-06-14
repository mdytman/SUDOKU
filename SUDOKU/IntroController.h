#pragma once
#include <SFML/Graphics.hpp>
#include "SudokuBoard.h"
#include "IntroView.h"

class IntroController
{
	bool finished = false;
	IntroView & view;
	SudokuBoard & board;
	GameMode gMode;
public:
	explicit IntroController(IntroView & v, SudokuBoard & b);
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	GameMode getGMode() const;
	bool isFinished() const { return finished; }
};

