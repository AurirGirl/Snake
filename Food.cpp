#include "Food.h"
#include <cstdlib>
#include <time.h>

Food::Food(Board _gameBoard)
{
	srand(time(NULL));
	do {
		coorX = (std::rand() % (_gameBoard.getWidth() - 1)) + 1;
		coorY = (std::rand() % (_gameBoard.getHeight() - 1)) + 1;
	} while (_gameBoard.checkField(coorX, coorY) == SNAKE);
	_gameBoard.changeField(coorX, coorY, FOOD);
}

Food::~Food()
{

}
