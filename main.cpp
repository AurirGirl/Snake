#include <iostream>
#include <chrono>
#include <thread>
#include "console.h"
#include "Snake.h"
#include "Food.h"
#include "Game.h"

bool check(Board gameBoard, Food *_food, Snake& _snake)
{
	bool eat = (_food->getCoorX() == _snake.getCoorX() && _food->getCoorY() == _snake.getCoorY());
	if (eat) _snake.growBody();
	return eat;
}

int main()
{
	Game snakeGame;

	int width, height;
	std::cout << "Podaj szerokosc planszy: ";
	std::cin >> width;
	std::cout << "Podaj wysokosc planszy: ";
	std::cin >> height;

	Board gameBoard(width, height);
	Snake snake(gameBoard);
	Food *food = new Food(gameBoard);

	while (snakeGame.getStatus())
	{
		clear();
		gameBoard.drawBoard();
		std::cout << "WYNIK = " << snakeGame.getResult() << std::endl;
		std::chrono::milliseconds timespan(1000);
		std::this_thread::sleep_for(timespan);
		snake.changeDirection();
		snake.move(gameBoard,snakeGame);
		

		if (check(gameBoard,food, snake))
		{
			snakeGame.addResult();
			delete food;
			food = new Food(gameBoard);
		}
	}

	std::cout << "KONIEC GRY" << std::endl;

}
