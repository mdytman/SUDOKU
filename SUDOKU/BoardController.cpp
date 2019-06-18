//#include "pch.h"
#include "BoardController.h"

BoardController::BoardController(BoardView & v, SudokuBoard & b) : view(v), board(b)
{
	k = 0;
	m = 0;
}

void BoardController::handleEvent(sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; j++)
				{
					if ((event.mouseButton.x > board.getWindowWidth() / 8 + j * board.getWindowWidth() / 12) && (event.mouseButton.x < board.getWindowWidth() / 8 + j * board.getWindowWidth() / 12 + board.getWindowWidth() / 12) && (event.mouseButton.y > board.getWindowHeight() / 5 + i * board.getWindowHeight() / 12) && (event.mouseButton.y < board.getWindowHeight() / 5 + i * board.getWindowHeight() / 12 + board.getWindowHeight() / 12))
					{
						view.changeFieldColour(i, j, true);
						m = i;
						k = j;
			
					}
				}
			}
			for (int p = 0; p < 9; ++p)
			{
				std::cout << "m: " << m << " k: " << k << std::endl; 
				if ((event.mouseButton.x > board.getWindowWidth() / 8 + p * board.getWindowWidth() / 12) && (event.mouseButton.x < board.getWindowWidth() / 8 + p * board.getWindowWidth() / 12 + board.getWindowWidth() / 12) && (event.mouseButton.y > board.getWindowHeight() / 10) && (event.mouseButton.y < board.getWindowHeight() / 10 + board.getWindowHeight() / 12))
				{
					std::cout << "mousebutton \n";
					view.fillTheField(m, k, p + 1);
					if (view.isCorrectMove(m, k , p+1) == true)
					{
						board.countFilledFields();
					}
					if (view.isCorrectMove(m, k, p + 1) == false)
					{
						board.countMistakes();
					}
				}
			}
			
		}		
	}
	if (board.getGameState() != RUNNING)
	{
		finished = true;
	}
}

