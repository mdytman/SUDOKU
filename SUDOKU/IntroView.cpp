//#include "pch.h"
#include <iostream>
#include "IntroView.h"

IntroView::IntroView(SudokuBoard & sudokuBoard) : board(sudokuBoard)
{
	background.setSize(sf::Vector2f(board.getWindowHeight(), board.getWindowWidth()));
	background.setFillColor(sf::Color(171, 171, 171));

	if (!sudokuFont.loadFromFile("sudoku.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	sudokuText.setFont(sudokuFont);
	sudokuText.setCharacterSize(board.getWindowHeight() / 5);
	int posW = board.getWindowWidth() / 6;
	int posH = board.getWindowHeight() / 8;
	sudokuText.setPosition(posW, posH);
	sudokuText.setString("SUDOKU");
	sudokuText.setFillColor(sf::Color::Black);

	int x = board.getWindowHeight() / 9;
	for (int i = 0; i < 4; ++i)
	{
		gameModeRect[i].setSize(sf::Vector2f(board.getWindowWidth() / 4, board.getWindowHeight() / 17 ));
		gameModeRect[i].setFillColor(sf::Color(59, 59, 59));
		gameModeRect[i].setPosition(board.getWindowWidth() / 8, board.getWindowHeight() / 2.2 + i*x);
	}

	if (!gameModeFont.loadFromFile("gamemode.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	for (int j = 0; j < 4; ++j)
	{
		gameModeText[j].setFont(gameModeFont);
		gameModeText[j].setCharacterSize(board.getWindowHeight() / 18);		
		gameModeText[j].setFillColor(sf::Color::White);
	}
	gameModeText[0].setString("EASY");
	gameModeText[0].setPosition(board.getWindowWidth() / 5.5, board.getWindowHeight() / 2.23 + 0 * x);
	gameModeText[1].setString("MEDIUM");
	gameModeText[1].setPosition(board.getWindowWidth() / 8, board.getWindowHeight() / 2.23 + 1 * x);
	gameModeText[2].setString("HARD");
	gameModeText[2].setPosition(board.getWindowWidth() / 6, board.getWindowHeight() / 2.23 + 2 * x);
	gameModeText[3].setString("EXPERT");
	gameModeText[3].setPosition(board.getWindowWidth() / 7, board.getWindowHeight() / 2.23 + 3 * x);

	start.setSize(sf::Vector2f(board.getWindowWidth() / 3, board.getWindowHeight() / 14));
	start.setFillColor(sf::Color(59, 59, 59));
	start.setPosition(board.getWindowWidth() / 2, board.getWindowHeight() / 1.5);

	startText.setFont(gameModeFont);
	startText.setCharacterSize(board.getWindowHeight() / 18);
	startText.setFillColor(sf::Color::White);
	startText.setString("START");
	startText.setPosition(board.getWindowWidth() / 1.75, board.getWindowHeight() / 1.5);

	if (!authorFont.loadFromFile("courier-new.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	author.setFont(authorFont);
	author.setCharacterSize(board.getWindowHeight() / 35);
	author.setFillColor(sf::Color(135, 37, 37));
	author.setString("Dytman Marta, 249046");
	author.setPosition(board.getWindowWidth() / 2, board.getWindowHeight() / 2.8);
}

void IntroView::gameModeOutline(int num, bool tmp)
{
	if (tmp == true)
	{
		gameModeRect[num].setOutlineThickness(10);
		gameModeRect[num].setOutlineColor(sf::Color(129, 17, 17));
	}
	if (tmp == false)
	{
		gameModeRect[num].setOutlineThickness(10);
		gameModeRect[num].setOutlineColor(sf::Color(171, 171, 171));
	}
}

void IntroView::draw(sf::RenderWindow & win)
{
	win.draw(background);
	
	win.draw(sudokuText);

	for (int i = 0; i < 4; ++i)
	{
		win.draw(gameModeRect[i]);
	}
	for (int j = 0; j < 4; ++j)
	{
		win.draw(gameModeText[j]);
	}
	
	win.draw(start);
	win.draw(startText);

	win.draw(author);
}
