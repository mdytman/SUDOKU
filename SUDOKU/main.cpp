#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SudokuBoard.h"


int main()
{
	srand(time(NULL));
	SudokuBoard sb(500, 500, HARD);
	sb.debug_display();
}


