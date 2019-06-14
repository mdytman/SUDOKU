#include "pch.h"
#include "IntroController.h"

IntroController::IntroController(IntroView & v, SudokuBoard & b) : view(v), board(b)
{
}

void IntroController::handleEvent(sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{

		}
	}
}

GameMode IntroController::getGMode() const
{
	return gMode;
}
