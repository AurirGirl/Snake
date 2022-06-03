#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Board.h"
#include "conio.h"
#include "Game.h"

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

struct coordinate
{
	coordinate(int x,int y): x(x),y(y){}
	int x;
	int y;
};

class Snake
{
	int coorX, coorY;
	std::string symbol;
	DIRECTION _snakeDirection;
	std::vector<coordinate>body;
	int lenght;
public:
	Snake(Board _gameBoard);
	void move(Board _gameBoard,Game &game);
	void changeDirection();
	inline int getCoorX() { return coorX; }
	inline int getCoorY() { return coorY; }
	inline void growBody() { lenght++; };
};

