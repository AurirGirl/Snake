#pragma once
#include "Board.h"
#include "Snake.h"
class Food
{
	int coorX, coorY;
public:
	Food(Board _gameBoard);
	inline int getCoorX() { return coorX; }
	inline int getCoorY() { return coorY; }
	~Food();
};
