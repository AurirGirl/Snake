#include "Snake.h"

Snake::Snake(Board _gameBoard)
{
	lenght = 1;
	coorX = _gameBoard.getWidth() / 2;
	coorY = _gameBoard.getHeight() / 2;
	body.emplace_back(coorX,coorY);
	_snakeDirection = DOWN;
	
	_gameBoard.changeField(coorX, coorY, SNAKE);
}

void Snake::move(Board _gameBoard,Game &game)
{
	body.emplace_back(coorX, coorY);

	switch (_snakeDirection)
	{
	case UP:
		coorY--;
		if(game.checkField(_gameBoard,coorX,coorY)) _gameBoard.changeField(coorX, coorY, SNAKE);
		break;
	case DOWN:
		coorY++;
		if(game.checkField(_gameBoard, coorX, coorY)) _gameBoard.changeField(coorX, coorY, SNAKE);	
		break;
	case LEFT:
		coorX--;
		if(game.checkField(_gameBoard, coorX, coorY)) _gameBoard.changeField(coorX, coorY, SNAKE);
		break;
	case RIGHT:
		coorX++;
		if(game.checkField(_gameBoard, coorX, coorY)) _gameBoard.changeField(coorX, coorY, SNAKE);
		break;
	}

	_gameBoard.changeField(body[body.size() - lenght].x, body[body.size() - lenght].y, EMPTY);

}

void Snake::changeDirection()
{
	unsigned char sign;

	while (_kbhit())
	{
		sign = _getch();
		static_cast<int>(sign);

		switch (sign)
		{
		case 119:
			_snakeDirection = UP;
			break;
		case 115:
			_snakeDirection = DOWN;
			break;
		case 100:
			_snakeDirection = RIGHT;
			break;
		case 97:
			_snakeDirection = LEFT;
			break;
		default:
			break;
		}
	}

}
