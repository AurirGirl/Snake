#pragma once

enum STATUS_FIELD { EMPTY, SNAKE, FOOD };

class Board
{
	int width, height;
	STATUS_FIELD** gameBoard;
public:
	Board(int width_,int height_);
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }
	inline STATUS_FIELD** getBoard() { return gameBoard; }
	inline void changeField(int x, int y, STATUS_FIELD fieldType) { gameBoard[y][x] = fieldType; }
	inline STATUS_FIELD checkField(int x, int y) { return gameBoard[y][x]; }
	void drawBoard();
};
