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
	for (int k = 0; k < 10; ++k)
	{
		verticalLines[k + 10].setSize(sf::Vector2f(board.getWindowWidth() / 200, board.getWindowHeight() / 12));
		verticalLines[k + 10].setPosition(board.getWindowWidth() / 8 + k * board.getWindowWidth() / 12, board.getWindowHeight() / 10);
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
	for (int m = 0; m < 2; ++m)
	{
		horizontalLines[m + 10].setSize(sf::Vector2f(9 * board.getWindowWidth() / 12 + board.getWindowWidth() / 100 - board.getWindowWidth() / 200, board.getWindowHeight() / 200));
		horizontalLines[m + 10].setPosition(board.getWindowWidth() / 8, board.getWindowHeight() / 10 + m * board.getWindowHeight() / 12);
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
	//newNumbers.setFillColor(sf::Color::Black);
	newNumbers.setFillColor(sf::Color(19, 19, 237));

	mistakesAmount.setFont(numFont);
	mistakesAmount.setCharacterSize(30);
	mistakesAmount.setStyle(sf::Text::Regular);
	mistakesAmount.setFillColor(sf::Color::Black);
	mistakesAmount.setPosition(board.getWindowWidth() / 3, board.getWindowHeight() / 20);
	mistakesAmount.setString("Mistakes amount: " + std::to_string(board.getMistakesAmount()) + "/3");

	numbersToChoose.setFont(numFont);
	numbersToChoose.setCharacterSize(board.getWindowHeight() / 12);
	numbersToChoose.setStyle(sf::Text::Regular);
	numbersToChoose.setFillColor(sf::Color(86, 86, 86));
}

void BoardView::changeFieldColour(int y, int x, bool tmp)
{
	if (tmp == false)
	{
		field.setFillColor(sf::Color(171, 171, 171));
		field.setPosition(board.getWindowWidth() / 8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5);
	}
	if (tmp == true)
	{
		field.setFillColor(sf::Color(132, 186, 220));
		field.setPosition(board.getWindowWidth() / 8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + y * board.getWindowHeight() / 12);
	}	
}

void BoardView::changeNumberColour(int y, int x, bool tmp)
{
	if (tmp == true)
	{
		newNumbers.setFillColor(sf::Color::Red); 
		newNumbers.setPosition(board.getWindowWidth() / 6.8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + y * board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
	}
	if (tmp == false)
	{
		newNumbers.setFillColor(sf::Color(19, 19, 237));
		newNumbers.setPosition(board.getWindowWidth() / 6.8 + x * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + y * board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
	}
}

void BoardView::draw(sf::RenderWindow & win)
{
	win.draw(background);
	win.draw(field);
	for (int i = 0; i < 20; ++i)
	{
		win.draw(verticalLines[i]);
	}
	for (int j = 0; j < 12; ++j)
	{
		win.draw(horizontalLines[j]); 
	}
	for (int n = 1; n <= 9; ++n)
	{
		numbersToChoose.setPosition(board.getWindowWidth() / 6.8 + (n-1) * board.getWindowWidth() / 12, board.getWindowHeight() / 10 - board.getWindowHeight() / 60);
		numbersToChoose.setString(std::to_string(n));
		win.draw(numbersToChoose);
	}
	for (int k = 0; k < 9; ++k)
	{
		for (int m = 0; m < 9; ++m)
		{
			if (board.getFieldInfo(m, k) >= '1' && board.getFieldInfo(m, k) <= '9')
			{
				numbers.setPosition(board.getWindowWidth() / 6.8 + m * board.getWindowWidth() / 12, board.getWindowHeight() / 5 + k*board.getWindowHeight() / 12 - board.getWindowHeight() / 60);
				numbers.setString(board.getFieldInfo(m, k));
				win.draw(numbers);
			}		
		}
	}
	for (int p = 0; p < 9; ++p)
	{
		for (int r = 0; r < 9; ++r)
		{
			if (board.getInfoAboutNewNumber(r, p) >= '1' && board.getInfoAboutNewNumber(r, p) <= '9')
			{
				std::cout << "newNumbers" << std::endl;
				newNumbers.setString(board.getInfoAboutNewNumber(r, p));
				win.draw(newNumbers);
			}
		}
	}
	win.draw(mistakesAmount);
}
