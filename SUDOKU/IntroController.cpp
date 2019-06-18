//#include "pch.h"
#include "IntroController.h"

IntroController::IntroController(IntroView & v, SudokuBoard & b) : view(v), board(b)
{
}

void IntroController::handleEvent(sf::Event & event)
{
	bool gameModeSelected = false;
	int tmp = board.getWindowHeight() / 9;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (int i = 0; i < 4; ++i)
			{
				if ((event.mouseButton.x > board.getWindowWidth() / 8) && (event.mouseButton.x < board.getWindowWidth() / 8 + board.getWindowWidth() / 4) && (event.mouseButton.y > board.getWindowHeight() / 2.2 + i * tmp) && (event.mouseButton.y < board.getWindowHeight() / 2.2 + i * tmp + board.getWindowHeight() / 17))
				{
					for (int j = 0; j < 4; ++j)
					{
						if (j != i)
							view.gameModeOutline(j, false);
					}
					view.gameModeOutline(i, true);
					gameModeSelected = true;
					
					switch (i)
					{
					case 0:

						gMode = EASY;
						break;

					case 1:

						gMode = MEDIUM;
						break;

					case 2:

						gMode = HARD;
						break;

					case 3:

						gMode = EXPERT;
						break;

					default:
						break;
					}
				}

			}
			if ((event.mouseButton.x > board.getWindowWidth() / 2) && (event.mouseButton.x < board.getWindowWidth() / 2 + board.getWindowWidth() / 3) && (event.mouseButton.y > board.getWindowHeight() / 1.5) && (event.mouseButton.y < board.getWindowHeight() / 1.5 + board.getWindowHeight() / 14))
			{
				board.resetBoard(board.getWindowWidth(), board.getWindowHeight(), getGMode());
				finished = true;
			}
		}
	}
}

GameMode IntroController::getGMode() const
{
	return gMode;
}
