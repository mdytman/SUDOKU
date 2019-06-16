#include "pch.h"
#include "BoardView.h"

BoardView::BoardView(SudokuBoard & b) : board(b)
{
	background.setSize(sf::Vector2f(board.getWindowHeight(), board.getWindowWidth()));
	background.setFillColor(sf::Color(171, 171, 171));

	field.setSize(sf::Vector2f(board.getWindowWidth() / 12, board.getWindowHeight() / 12));
	field.setFillColor(sf::Color(171, 171, 171));
	field.setPosition(board.getWindowWidth() / 12, board.getWindowHeight() / 12);

	for (int i = 0; i < 10; ++i)
	{
		verticalLines[i].setFillColor(sf::Color::Black);
		verticalLines[i].setPosition(board.getWindowWidth() / 8 + i * board.getWindowWidth() / 12, board.getWindowHeight() / 5);
		if (i % 3 == 0)
		{
			verticalLines[i].setSize(sf::Vector2f(board.getWindowWidth() / 100, 9*board.getWindowHeight() / 12));
		}
		else
		{
			verticalLines[i].setSize(sf::Vector2f(board.getWindowWidth() / 200, 9 * board.getWindowHeight() / 12));
		}
	}

	for (int j = 0; j < 10; ++j)
	{
		horizontalLines[j].setFillColor(sf::Color::Black);
		horizontalLines[j].setPosition(board.getWindowWidth() / 8, board.getWindowHeight() / 5 + j * board.getWindowHeight() / 12);
		if (j % 3 == 0)
		{
			horizontalLines[j].setSize(sf::Vector2f(9 * board.getWindowWidth() / 12 + board.getWindowWidth() / 100, board.getWindowHeight() / 100));
		}
		else
		{
			horizontalLines[j].setSize(sf::Vector2f(9 * board.getWindowWidth() / 12 + board.getWindowWidth() / 100, board.getWindowHeight() / 200));
		}
	}
	
	if (!numFont.loadFromFile("numbers.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}
	numbers.setFont(numFont);
	numbers.setCharacterSize(board.getWindowHeight() / 12);
	numbers.setStyle(sf::Text::Regular);
	numbers.setFillColor(sf::Color::Black);

	newNumbers.setFont(numFont);
	newNumbers.setCharacterSize(board.getWindowHeight() / 35);
	newNumbers.setFillColor(sf::Color::Black);

	if (!mistakesFont.loadFromFile("mistakes.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}
	mistakesAmount.setFont(numFont);
	mistakesAmount.setCharacterSize(30);
	mistakesAmount.setStyle(sf::Text::Regular);
	mistakesAmount.setFillColor(sf::Color::Black);
	mistakesAmount.setPosition(board.getWindowWidth() / 3, board.getWindowHeight() / 18);
	mistakesAmount.setString("Mistakes amount: " + std::to_string(board.getMistakesAmount()) + "/3");


}

void BoardView::changeFieldColour(int y, int x, bool tmp)
{
	if (tmp == false)
	{
		field.setFillColor(sf::Color(171, 171, 171));
		field.setPosition(board.getWindowWidth() / 6.8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + y * board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
	}
	if (tmp == true)
	{
		field.setFillColor(sf::Color(132, 186, 220));
		field.setPosition(board.getWindowWidth() / 6.8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + y*board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
	}	
}

void BoardView::changeNumberColour(int y, int x, bool tmp)
{
	if (tmp == true)
	{
		newNumbers.setFillColor(sf::Color::Red); //setPosition!!!!!!!!!!
	}
	if (tmp == false)
	{
		newNumbers.setFillColor(sf::Color(19, 19, 237));
	}
}

void BoardView::draw(sf::RenderWindow & win)
{
	win.draw(background);
	win.draw(field);
	for (int i = 0; i < 10; ++i)
	{
		win.draw(verticalLines[i]);
	}
	for (int j = 0; j < 10; ++j)
	{
		win.draw(horizontalLines[j]); 
	}
	for (int k = 0; k < 9; ++k)
	{
		for (int m = 0; m < 9; ++m)
		{
			if (board.getFieldInfo(k, m) >= '1' && board.getFieldInfo(k, m) <= '9')
			{
				numbers.setPosition(board.getWindowWidth() / 6.8 + m * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + k*board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
				numbers.setString(board.getFieldInfo(k, m));
				win.draw(numbers);
			}
			if (board.getInfoAboutNewNumber(k, m) >= '1' && board.getInfoAboutNewNumber(k, m) <= '9')
			{
				newNumbers.setPosition(board.getWindowWidth() / 6.8 + m * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + k*board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
				newNumbers.setString(board.getInfoAboutNewNumber(k, m));
				win.draw(newNumbers);
			}
		}
	}
	win.draw(mistakesAmount);
}
