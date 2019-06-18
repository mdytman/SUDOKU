#include "pch.h"
#include "ScoreView.h"

ScoreView::ScoreView(SudokuBoard & b) : board(b)
{
	background.setSize(sf::Vector2f(board.getWindowHeight(), board.getWindowWidth()));
	background.setFillColor(sf::Color(171, 171, 171));

	if (!gameResultFont.loadFromFile("sudoku.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	gameResult.setFont(gameResultFont);
	gameResult.setCharacterSize(board.getWindowHeight() / 5);
	gameResult.setPosition(board.getWindowWidth() / 6.8, board.getWindowHeight() / 8);
	gameResult.setFillColor(sf::Color::Black);
	gameResult.setString("THE END");

	if (!pressSpaceFont.loadFromFile("courier-new.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}
	pressSpace.setFont(pressSpaceFont);
	pressSpace.setCharacterSize(board.getWindowHeight() / 45);
	pressSpace.setFillColor(sf::Color::Black);
	pressSpace.setString("press space to close the window");
	pressSpace.setPosition(board.getWindowWidth() / 4, board.getWindowHeight() / 1.3);
}

void ScoreView::draw(sf::RenderWindow & win)
{
	win.draw(background);
	win.draw(gameResult);
	win.draw(pressSpace);
}
