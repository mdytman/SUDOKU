#pragma once
#include <vector>

enum GameMode {EASY, MEDIUM, HARD, EXPERT};
enum GameState {RUNNING, FINISHED_LOSS, FINISHED_WIN};
enum FillingMode {NORMAL, NOTEMODE};

struct Field
{
	bool hasNumber;
	int number;
};

struct LargeTab
{
	Field smallTab[3][3];
};

class SudokuBoard
{
	int winHeight;
	int winWidth;
	int height;
	int width;
	LargeTab largeTab[3][3];
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
	void changeFillingMode(FillingMode mode);
	int getMistakesAmount() const;
	GameState getGameState() const;
	char getFieldInfo() const;	
};

