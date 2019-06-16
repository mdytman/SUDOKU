#pragma once
#include <vector>

enum GameMode {EASY, MEDIUM, HARD, EXPERT};
enum GameState {RUNNING, FINISHED_LOSS, FINISHED_WIN};

struct Field
{
	bool isRevealed;
	int number;
	int newNumber;
};

struct tempField
{
	int x;
	int y;
};

class SudokuBoard
{
	int winHeight;
	int winWidth;
	int height;
	int width;
	int mistakesAmount;
	Field board[9][9];
	GameMode gameMode;
	GameState gameState;
	
	void fillDiagonalTables(int y, int x);
	bool checkColumn(int x, int y, int n) const; //true if there is a number in column
	bool checkRow(int x, int y, int n) const;
	bool checkSmallTab(int x, int y, int n) const;
	bool checkAll(int y, int x, int n); //false if number 'n' is not in the column, row and small tab
	bool isEmpty(int &y, int &x) const; //that method is looking for a field with no number on it
	bool setNumbers();
	void revealFields(int amount);
public:
	SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode);
	void resetBoard(int wWidth, int wHeight, GameMode gm);
	void debug_display() const;
	int getWindowHeight() const;
	int getWindowWidth() const;
	int getBoardHeight() const;
	int getBoardWidth() const;
	char fillTheField(int number);
	bool isCorrectMove(int y, int x, int n);
	int getMistakesAmount() const;
	GameState getGameState() const;
	char getFieldInfo(int x, int y) const;
	char getInfoAboutNewNumber(int x, int y) const;
};

