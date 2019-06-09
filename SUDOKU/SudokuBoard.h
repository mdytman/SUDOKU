#pragma once
#include <vector>

enum GameMode {EASY, MEDIUM, HARD, EXPERT};
enum GameState {RUNNING, FINISHED_LOSS, FINISHED_WIN};
enum FillingMode {NORMAL, NOTEMODE};

struct Field
{
	bool isFilled;
	int number;
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
	Field board[9][9];
	GameMode gameMode;
	GameState gameState;
	FillingMode fillingMode;
	

	int findInARow(int tmp, int row);
	void fillDiagonalTables(int y, int x);
	void fillOtherTables(int y, int x);
	void fillALine(int y, int x);
	bool checkAll(int y, int x, int n);
	bool isEmpty(int &y, int &x) const;
public:
	SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode);
	bool setNumbers();
	void debug_display() const;
	int getWindowHeight() const;
	int getWindowWidth() const;
	int getBoardHeight() const;
	int getBoardWidth() const;
	bool checkColumn(int x, int y, int n) const; //true if there is a number in column
	bool checkRow(int x, int y, int n) const;
	bool checkSmallTab(int x, int y, int n) const;
	char fillTheField(int number);
	bool isCorrectFieldFilling() const;
	void changeFillingMode(FillingMode mode);
	int getMistakesAmount() const;
	GameState getGameState() const;
	char getFieldInfo(int x, int y) const;
};

