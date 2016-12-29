#pragma once

#define DEFAULT_CHAR '*'
#define TURN_X 1
#define TURN_Y 0

struct Game
{
	char board[3][3];

	char playerX = 'X';
	char playerO = 'O';

	int turn;
};

void printBoard(Game *game);
void initBoard(Game *game);
void makeMove(Game *game);
void putChar(Game *game, int x, int y, char c);
int checkPosition(Game *game, int x, int y);
int checkWin(Game *game);
int validateInput(int input);
int checkDraw(Game *game);