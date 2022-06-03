#include "Board.h"
#include <iostream>

Board::Board(int width_, int height_) {
	width = width_;
	height = height_;

	gameBoard = new STATUS_FIELD * [width];

	for (int i = 0; i < width; i++) {
		gameBoard[i] = new STATUS_FIELD[height];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			gameBoard[i][j] = EMPTY;
		}
	}

}

void Board::drawBoard() {

	std::cout << "|";
	for (int i = 0; i < width; i++) std::cout << "=";
	std::cout << "|" << std::endl;
	for (int i = 0; i < height; i++) {
		std::cout << "|";
		for (int j = 0; j < width; j++) {
			if (gameBoard[i][j] == EMPTY) {
				std::cout << " ";
			}
			else if (gameBoard[i][j] == SNAKE) {
				std::cout << "S";
			}
			else if (gameBoard[i][j] == FOOD) {
				std::cout << "F";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "|";
	for (int i = 0; i < width; i++) std::cout << "=";
	std::cout << "|" << std::endl;
}
