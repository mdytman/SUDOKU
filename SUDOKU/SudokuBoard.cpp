//#include "pch.h"
#include "SudokuBoard.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int SudokuBoard::mistakesCounter = 0;
int SudokuBoard::filledFieldsCounter = 0;

SudokuBoard::SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode) : winWidth(windowWidth), winHeight(windowHeight), gameMode(gamemode)
{
	gameState = RUNNING;
	mistakesAmount = 0;
	filledFields = 0;

	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			board[i1][i2].isRevealed = false;
		}

	}
	for (int i3 = 0; i3 < 9; ++i3)
	{
		for (int i4 = 0; i4 < 9; ++i4)
		{
			board[i3][i4].number = 0;
		}
	}


	fillDiagonalTables(0, 0);
	fillDiagonalTables(3, 3);
	fillDiagonalTables(6, 6);

	setNumbers();
	resetBoard(winWidth, winHeight, gameMode);
}

void SudokuBoard::resetBoard(int wWidth, int wHeight, GameMode gm)
{
	winWidth = wWidth;
	winHeight = wHeight;
	gameMode = gm;

	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			board[i1][i2].isRevealed = false;
		}

	}
	switch (gameMode)
	{
	case EASY:

		revealFields(38);
		fieldsToFill = 43;
		break;

	case MEDIUM:

		revealFields(30);
		fieldsToFill = 51;
		break;

	case HARD:

		revealFields(28);
		fieldsToFill = 53;
		break;

	case EXPERT:
		std::cout << "expert \n";
		revealFields(23);
		fieldsToFill = 58;
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

int SudokuBoard::countMistakes()
{
	mistakesCounter++;
	return mistakesCounter;
}

int SudokuBoard::countFilledFields()
{
	filledFieldsCounter++;
	return filledFieldsCounter;
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
	if (mistakesCounter > 2)
	{
		return FINISHED_LOSS;
	}
	if (mistakesCounter <= 2 && filledFieldsCounter == fieldsToFill) 
	{
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
