#include "pch.h"
#include "BoardController.h"

BoardController::BoardController(BoardView & v, SudokuBoard & b) : view(v), board(b)
{
}

void BoardController::handleEvent(sf::Event & event)
{
	int n;
	int k = 0;
	int m = 0;
	if (event.type == sf::Event::MouseButtonPressed && board.getGameState() == RUNNING)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (int i = 0; i < 9; ++i)
			{
				for (int j = 0; j < 9; j++)
				{
					if ((event.mouseButton.x > board.getWindowWidth() / 6.8 + j * board.getWindowWidth() / 12) && (event.mouseButton.x < board.getWindowWidth() / 6.8 + j * board.getWindowWidth() / 12 + board.getWindowWidth() / 12) && (event.mouseButton.y > board.getWindowHeight() / 5 + i * board.getWindowHeight() / 12 - board.getWindowHeight() / 60) && (event.mouseButton.y < board.getWindowHeight() / 5 + i * board.getWindowHeight() / 12 - board.getWindowHeight() / 60 + board.getWindowHeight() / 12))
					{
						view.changeFieldColour(i, j, true);
						m = i;
						k = j;
					}
				}
			}
		}		
	}
	if (event.type == sf::Event::KeyPressed)
	{
		for (int i1 = 1; i1 <= 9; ++i1)
		{
			if (event.key.code == sf::Keyboard::Num0 + i1)
			{
				std::cout << "num0" << std::endl;
				if (board.isCorrectMove(k, m, i1))
				{
					std::cout << "dobrze" << std::endl;
					view.changeNumberColour(k, m, false);
					board.fillTheField(k, m, i1);
				}
				if (board.isCorrectMove(k, m, i1))
				{
					std::cout << "zle" << std::endl;
					view.changeNumberColour(k, m, true);
					board.fillTheField(k, m, i1);
				}
			}
		}
	}
	/*std::cin >> n;
	*/
}

