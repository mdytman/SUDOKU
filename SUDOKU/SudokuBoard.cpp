#include "pch.h"
#include "SudokuBoard.h"
#include <vector>
#include <iostream>

SudokuBoard::SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode)
{
	winWidth = windowWidth;
	winHeight = windowHeight;
	gameMode = gamemode;
	gameState = RUNNING;
	fillingMode = NORMAL;
	//easy - 38/81
	//medium -30/81
	//hard - 28/81
	//expert - 23/81
	
	setNumbers();
	
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			board[i1][i2].isFilled = true;
		}
		
	}
	for (int i3 = 0; i3 < 9; ++i3)
	{
		for (int i4 = 0; i4 < 0; ++i4)
		{
			board[i3][i4].number == 0;
		}
	}
}

void SudokuBoard::debug_display() const
{
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			std::cout << "[" << getFieldInfo(i1, i2) << "]";
		}
		std::cout << std::endl;
	}
}



void SudokuBoard::setNumbers()
{	

	
	int x;	
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			do
			{
				x = rand() % 9 + 1;
				board[i1][i2].number = x;
			} while (checkColumn(i2, i1) == true || checkRow(i2, i1) == true || checkSmallTab(i2, i1) == true);
		}
	}
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

bool SudokuBoard::checkColumn(int x, int y) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (i != x)
		{
			if (board[y][i].number == board[y][x].number)
				return true;
		}
	}
	return false;
}

bool SudokuBoard::checkRow(int x, int y) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (i != y)
		{
			if (board[i][x].number == board[y][x].number)
				return true;
		}
	}
	return false;
}

bool SudokuBoard::checkSmallTab(int x, int y) const
{
	int rx; //r - remainder
	rx = x % 3;
	int ry;
	ry = y % 3;

	int tmpx = x - rx; //thats an idea for checking which small tab x and y belong to
	int tmpy = y - ry;
	
	for (int i = tmpy; i < tmpy + 3; ++i)
	{
		for (int j = tmpx; j < tmpx + 3; ++j)
		{
			if (i != y && j != x)
			{
				if (board[i][j].number == board[y][x].number)
					return true;
			}
		}
	}
	return false;
}

char SudokuBoard::fillTheField(int number)
{
	if (number < 1 || number > 9)
	{
		return '_';
	}
	if (number >= 1 && number <= 9)
	{
		return '0' + number;
	}
}

bool SudokuBoard::isCorrectFieldFilling() const
{
	return false;
}

void SudokuBoard::changeFillingMode(FillingMode mode)
{
}

int SudokuBoard::getMistakesAmount() const
{
	return 0;
}

GameState SudokuBoard::getGameState() const
{
	return gameState;
}

char SudokuBoard::getFieldInfo(int x, int y) const
{
	int tmp;
	if (board[y][x].isFilled)
	{
		tmp = board[y][x].number;
		return '0' + tmp;
	}
	if (!board[y][x].isFilled)
	{
		return '_';
	}
	
}
