#include "pch.h"
#include "SudokuBoard.h"

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




}

void SudokuBoard::setNumbers()
{
	
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

char SudokuBoard::fillTheField(int number)
{
	if (number < 1 || number > 9)
	{
		return;
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

char SudokuBoard::getFieldInfo() const
{
}
