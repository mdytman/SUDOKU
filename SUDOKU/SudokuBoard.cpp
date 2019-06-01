#include "pch.h"
#include "SudokuBoard.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

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
	
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			board[i1][i2].isFilled = true;
		}
		
	}
	for (int i3 = 0; i3 < 9; ++i3)
	{
		for (int i4 = 0; i4 < 9; ++i4)
		{
			board[i3][i4].number = 0;
		}
	}
	
	////filling one row and one column randomly
	//int tmpRow = rand() % 9 + 1;
	//
	//std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//std::random_shuffle(numbers.begin(), numbers.end());
	//for (int i5 = 0; i5 < 9; ++i5)
	//{
	//	board[tmpRow][i5].number = numbers[i5];
	//}

	//int tmpNumber = rand() % 9 + 1;
	//int tmpColumn = findInARow(tmpNumber, tmpRow);
	////auto tmpColumn = std::find(numbers.begin(), numbers.end(), tmpNumber);
	//numbers.erase(numbers.begin() + tmpColumn);
	//std::random_shuffle(numbers.begin(), numbers.end());
	////generate column without this number
	//int i7 = 0;
	//for (size_t i6 = 0; i6 < numbers.size(); ++i6)
	//{
	//	if (i7 == tmpRow)
	//	{
	//		++i7;
	//	}
	//	board[i7][tmpColumn].number = numbers[i6];
	//	++i7;
	//}

	fillDiagonalTables(0, 0);
	fillDiagonalTables(3, 3);
	fillDiagonalTables(6, 6);
	fillOtherTables(0, 3);



	//setNumbers();
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
	//int tmp;
	for (int i1 = 0; i1 < 9; ++i1)
	{
		for (int i2 = 0; i2 < 9; ++i2)
		{
			//tmp = board[i1][i2].number;
			if (board[i1][i2].number == 0)
			{
				do
				{
					x = rand() % 9 + 1;
					if (checkColumn(i2, i1, x) == false && checkRow(i2, i1, x) == false)
					{						
							board[i1][i2].number = x;
					}
				} while (board[i1][i2].number == 0);

				//(checkColumn(i2, i1, x) == true || checkRow(i2, i1, x) == true); // || checkSmallTab(i2, i1, x) == true);
				
			}
			else board[i1][i2].number = -1; //= tmp;
			
		}
	}
}

int SudokuBoard::findInARow(int tmp, int row)
{
	for (int i = 0; i < 9; ++i)
	{
		if (board[row][i].number == tmp)
			return i;
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

void SudokuBoard::fillOtherTables(int y, int x)
{
	fillALine(y, x);
	fillALine(y, x + 1);
	fillALine(y, x + 2);
}

void SudokuBoard::fillALine(int y, int x)
{
	std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
	//removing repeated elements in a row
	for (int i1 = 0; i1 < 9; ++i1)
	{
		if (board[i1][x].number != 0)
			std::remove(numbers.begin(), numbers.end(), board[i1][x].number);
	}
	std::random_shuffle(numbers.begin(), numbers.end()); //need to fix this
	int idx = 1;
	for (int i2 = 0 + y; i2 < 3 + y; ++i2)
	{
		while (checkColumn(x, i2, numbers[idx - 1]))
		{
			std::random_shuffle(numbers.begin(), numbers.end());
		}
		board[i2][x].number = numbers[idx - 1];
		idx = idx + 1;
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

bool SudokuBoard::checkColumn(int x, int y, int n) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (i != x)
		{
			if (board[y][i].number == n)
				return true;
		}
	}
	return false;
}

bool SudokuBoard::checkRow(int x, int y, int n) const
{
	for (int i = 0; i < 9; ++i)
	{
		if (i != y)
		{
			if (board[i][x].number == n)
				return true;
		}
	}
	return false;
}

bool SudokuBoard::checkSmallTab(int x, int y, int n) const
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
				if (board[i][j].number == n)
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
