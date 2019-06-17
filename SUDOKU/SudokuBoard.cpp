#include "pch.h"
#include "SudokuBoard.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

SudokuBoard::SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode) : winWidth(windowWidth), winHeight(windowHeight), gameMode(gamemode)
{
	
	resetBoard(gameMode);


}

void SudokuBoard::resetBoard(GameMode gm)
{
	gameMode = gm;
	gameState = RUNNING;
	mistakesAmount = 0;
	filledFields = 0;
	
	switch (gm)
	{
	case EASY:

		revealFields(38);
		fieldsToFill = 44;
		break;

	case MEDIUM:
		std::cout << "medium\n";
		revealFields(30);
		fieldsToFill = 52;
		break;

	case HARD:

		revealFields(28);
		fieldsToFill = 54;
		break;

	case EXPERT:

		revealFields(23);
		fieldsToFill = 59;
		break;

	default:
		break;
	}

}

void SudokuBoard::debug_display() const
{
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			std::cout << "[" << getFieldInfo(i2, i1) << "]";
		}
		std::cout << std::endl;
	}
}

bool SudokuBoard::setNumbers() //inspired by https://www.geeksforgeeks.org/sudoku-backtracking-7/
{
	int y, x;

	if (!isEmpty(y, x))
	{
		return true;
	}

	for (int n = 1; n <= 9; ++n)
	{
		if (!checkAll(y, x, n))
		{
			board[y][x].number = n;

			if (setNumbers())
				return true;

			board[y][x].number = 0;
		}
	}
	return false;
}

void SudokuBoard::revealFields(int amount)
{
	int x, y;
	for (int i = 0; i < amount; ++i)
	{
		std::cout << "revealFields \n";
		do
		{
			x = rand() % 9;
			y = rand() % 9;
		} while (board[y][x].isRevealed);
		board[y][x].isRevealed = true;
	}
}


void SudokuBoard::fillDiagonalTables(int y, int x)
{
	std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
	std::random_shuffle(numbers.begin(), numbers.end());
	int idx = 0;
	for (int k1 = 0 + y; k1 < 3 + y; ++k1)
	{
		for (int k2 = 0 + x; k2 < 3 + x; ++k2)
		{
			board[k1][k2].number = numbers[idx];
			idx = idx + 1;
		}
	}
}

bool SudokuBoard::checkAll(int y, int x, int n)
{
	if (!checkColumn(x, y, n) && !checkRow(x, y, n) && !checkSmallTab(x - x % 3, y - y % 3, n) && board[y][x].number == 0)
	{
		return false;
	}
	else return true;
}

bool SudokuBoard::isEmpty(int &y, int &x) const
{
	for (y = 0; y < 9; ++y)
	{
		for (x = 0; x < 9; ++x)
		{
			if (board[y][x].number == 0)
				return true;
		}
	}
	return false;
}


int SudokuBoard::getWindowHeight() const
{
	return winHeight;
}

int SudokuBoard::getWindowWidth() const
{
	return winWidth;
}

int SudokuBoard::getBoardHeight() const
{
	return height;
}

int SudokuBoard::getBoardWidth() const
{
	return width;
}

void SudokuBoard::increaseFilledFieldsAmount()
{
	filledFields = filledFields + 1;
}

bool SudokuBoard::checkColumn(int x, int y, int n) const
{
	for (int i = 0; i < 9; i++)
	{
		if (board[y][i].number == n)
			return true;
	}
	return false;
}

bool SudokuBoard::checkRow(int x, int y, int n) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (board[i][x].number == n)
			return true;
	}
	return false;
}

bool SudokuBoard::checkSmallTab(int x, int y, int n) const //x and y must be the coordinates of the top left corner of small tab
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + y][j + x].number == n)
				return true;
	return false;
}


int SudokuBoard::getMistakesAmount() const
{
	return mistakesAmount;
}

void SudokuBoard::increaseMistakesAmount()
{
	mistakesAmount = mistakesAmount + 1;
}

GameState SudokuBoard::getGameState() const
{
	std::cout << "finished \n";

	if (mistakesAmount > 2)
	{
		std::cout << "finished \n";

		return FINISHED_LOSS;
	}
	if (mistakesAmount <= 2 && filledFields == fieldsToFill)
	{
		std::cout << "finished \n";

		return FINISHED_WIN;
	}
	else return gameState;
}

char SudokuBoard::getFieldInfo(int x, int y) const
{
	int tmp;
	if (board[y][x].isRevealed)
	{
		tmp = board[y][x].number;
		return '0' + tmp;
	}
	if (!board[y][x].isRevealed)
	{
		return '_';
	}
}

int SudokuBoard::getNumber(int y, int x) const
{
	return board[y][x].number;
}
