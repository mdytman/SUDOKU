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

	fillDiagonalTables(0, 0);
	fillDiagonalTables(3, 3);
	fillDiagonalTables(6, 6);
	//fillOtherTables(0, 3);

	setNumbers();

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

bool SudokuBoard::setNumbers()
{
	int y, x;

	// If there is no unassigned location, 
	// we are done  
	if (!isEmpty(y, x))
	{
		std::cout << "iseampty";
		return true; // success!  
	}
		// consider digits 1 to 9  
	for (int n = 1; n <= 9; n++) // efnjdjfsejidelksfdkljedmfek
	{
		std::cout << "checkAll" << std::endl;

		// if looks promising  
		if (!checkAll(y, x, n))
		{
			std::cout << "checkAll";

			// make tentative assignment  
			board[y][x].number = n;

			// return, if success, yay!  
			if (setNumbers())
				return true;

			// failure, unmake & try again  
			board[y][x].number = 0;
		}
	}
	return false; // this triggers backtracking 
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
	/*fillALine(y, x);
	fillALine(y, x + 1);
	fillALine(y, x + 2);*/
	std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
	int idx = 1;
	std::random_shuffle(numbers.begin(), numbers.end());
	int tmp = 0;
	int tmpValue = 10;
	int tmpSwap = 0; 
	while (checkAll(y, x, numbers[idx - 1]) || checkAll(y, x + 1, numbers[idx]) || checkAll(y, x + 2, numbers[idx + 1]) || checkAll(y + 1, x, numbers[idx + 2]) || checkAll(y + 1, x + 1, numbers[idx + 3]) || checkAll(y + 1, x + 2, numbers[idx + 4]) || checkAll(y + 2, x, numbers[idx + 5]) || checkAll(y + 2, x + 1, numbers[idx + 6]) || checkAll(y + 2, x + 2, numbers[idx + 7]))
	{
		std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
		tmp = tmp + 1;
		if (tmp == tmpValue)
		{
			std::random_shuffle(numbers.begin(), numbers.end());
			tmpValue = tmpValue * 2;
		}
	}
	idx = 1;
	for (int i3 = 0 + y; i3 < 3 + y; ++i3)
	{
		for (int i4 = 0 + x; i4 < 3 + x; ++i4)
		{
			board[i3][i4].number = numbers[idx - 1];
			idx = idx + 1;
		}
	}
}

void SudokuBoard::fillALine(int y, int x)
{
	//std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
	////removing repeated elements in a row
	//for (int i1 = 0; i1 < 9; ++i1)
	//{
	//	if (board[i1][x].number != 0)
	//		std::remove(numbers.begin(), numbers.end(), board[i1][x].number);
	//}
	//std::random_shuffle(numbers.begin(), numbers.end()); //need to fix this
	//int idx = 1;
	//for (int i2 = 0 + y; i2 < 3 + y; ++i2)
	//{
	//	while (checkcolumn(x, i2, numbers[idx - 1]))
	//	{
	//		std::random_shuffle(numbers.begin(), numbers.end());
	//	}
	//	board[i2][x].number = numbers[idx - 1];
	//	idx = idx + 1;
	//}


}

bool SudokuBoard::checkAll(int y, int x, int n)
{
	//return !UsedInRow(grid, row, num) &&
	//	!UsedInCol(grid, col, num) &&
	//	!UsedInBox(grid, row - row % 3,
	//		col - col % 3, num) &&
	//	grid[row][col] == UNASSIGNED;
	if (!checkColumn(x, y, n) && !checkRow(x, y, n) && !checkSmallTab(x % 3, y % 3, n))
	{
		return false;
	}
	else return true;
}

bool SudokuBoard::isEmpty(int &y, int &x) const
{
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
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

bool SudokuBoard::checkColumn(int x, int y, int n) const
{
	for (int i = 0; i < 9; ++i)
	{
		/*if (i != x)
		{*/
			if (board[y][i].number == n)
				return true;
		//}
	}
	return false;
}

bool SudokuBoard::checkRow(int x, int y, int n) const
{
	for (int i = 0; i < 9; ++i)
	{
		//if (i != y)
		//{
			if (board[i][x].number == n)
				return true;
		//}
	}
	return false;
}

bool SudokuBoard::checkSmallTab(int x, int y, int n) const //x and y must be the coordinates of the top left corner of small tab
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + y][j + x].number == n)
				return true;
	return false; //i j
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
