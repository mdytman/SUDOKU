#pragma once
#include "IntroController.h"
#include "BoardController.h"
#include "ScoreController.h"
#include "SudokuBoard.h"

class GameManager {
	IntroController &introController;
	BoardController &boardController;
	ScoreController &scoreController;

	enum GameState 
	{
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(IntroController &ic, BoardController &bc, ScoreController &sc);

	void draw(sf::RenderWindow &win);

	void handleEvent(sf::Event &event);
};

