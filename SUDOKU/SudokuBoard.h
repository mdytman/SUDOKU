#pragma once
#include <vector>

enum GameMode {EASY, MEDIUM, HARD, EXPERT};
enum GameState {RUNNING, FINISHED_LOSS, FINISHED_WIN};
enum FillingMode {NORMAL, NOTEMODE};

struct Field
{
	int smallTab[3][3];
};

class SudokuBoard
{
	int winHeight;
	int winWidth;
	int height;
	int width;
	Field largeTab[3][3];
	void setNumbers();
	GameMode gameMode;
	GameState gameState;
	FillingMode fillingMode;
public:
	SudokuBoard(int windowWidth, int windowHeight, GameMode gamemode);
	int getWindowHeight() const;
	int getWindowWidth() const;
	int getBoardHeight() const;
	int getBoardWidth() const;
	char fillTheField(int number);
	bool isCorrectFieldFilling() const;
	int getMistakesAmount() const;
	GameState getGameState() const;
	char getFieldInfo() const;	
};

