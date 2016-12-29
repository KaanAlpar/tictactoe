#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "main.h"

int main()
{
	Game game;

	initBoard(&game);
	printBoard(&game);

	int quit = 0;
	while (!quit)
	{
		makeMove(&game);
		printBoard(&game);
		if (checkWin(&game))
		{
			break;
		}
	}

	_getch();
	return 0;
}

void printBoard(Game *game)
{
	int k = 0;
	while (k < 9)
	{
		printf("%c", '-');
		k++;
	}
	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c%c%c", '|', game->board[i][j], '|');
		}

		printf("\n");
	}

	k = 0;
	while (k < 9)
	{
		printf("%c", '-');
		k++;
	}
	printf("\n");
}

void initBoard(Game *game)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game->board[i][j] = DEFAULT_CHAR;
		}
	}

	game->turn = TURN_X;
}

void makeMove(Game *game)
{
	if (game->turn == TURN_X)
	{
		printf("Turn: X\n");
	}
	else if (game->turn == TURN_Y)
	{
		printf("Turn: Y\n");
	}

	int x_move, y_move;

	printf("Enter y coord: ");
	scanf("%d", &x_move);
	if (!validateInput(x_move))
	{
		return;
	}

	printf("Enter x coord: ");
	scanf("%d", &y_move);
	if (!validateInput(y_move))
	{
		return;
	}

	x_move -= 1;
	y_move -= 1;

	if (checkPosition(game, x_move, y_move))
	{
		if (game->turn == TURN_X)
		{
			putChar(game, x_move, y_move, game->playerX);
			game->turn = TURN_Y;
		}
		else if (game->turn == TURN_Y)
		{
			putChar(game, x_move, y_move, game->playerO);
			game->turn = TURN_X;
		}
	}
}

void putChar(Game *game, int x, int y, char c)
{
	game->board[x][y] = c;
}

int checkPosition(Game *game, int x, int y)
{
	switch (game->board[x][y])
	{
	case DEFAULT_CHAR:
		return 1;
		break;
	case 'X':
		return 0;
		break;
	case 'O':
		return 0;
		break;
	default:
		return 0;
		break;
	}
}

int checkWin(Game *game)
{
	//Check X
	if (game->board[0][0] == game->playerX && game->board[0][1] == game->playerX && game->board[0][2] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[1][0] == game->playerX && game->board[1][1] == game->playerX && game->board[1][2] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[2][0] == game->playerX && game->board[2][1] == game->playerX && game->board[2][2] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[0][0] == game->playerX && game->board[1][0] == game->playerX && game->board[2][0] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[0][1] == game->playerX && game->board[1][1] == game->playerX && game->board[2][1] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[0][2] == game->playerX && game->board[1][2] == game->playerX && game->board[2][2] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[0][0] == game->playerX && game->board[1][1] == game->playerX && game->board[2][2] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	else if (game->board[2][0] == game->playerX && game->board[1][1] == game->playerX && game->board[2][0] == game->playerX)
	{
		printf("Player 1 wins");
		return 1;
	}
	//Check Y
	else if (game->board[0][0] == game->playerO && game->board[0][1] == game->playerO && game->board[0][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[1][0] == game->playerO && game->board[1][1] == game->playerO && game->board[1][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[2][0] == game->playerO && game->board[2][1] == game->playerO && game->board[2][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[0][0] == game->playerO && game->board[1][0] == game->playerO && game->board[2][0] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[0][1] == game->playerO && game->board[1][1] == game->playerO && game->board[2][1] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[0][2] == game->playerO && game->board[1][2] == game->playerO && game->board[2][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[0][0] == game->playerO && game->board[1][1] == game->playerO && game->board[2][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}
	else if (game->board[2][0] == game->playerO && game->board[1][1] == game->playerO && game->board[0][2] == game->playerO)
	{
		printf("Player 2 wins");
		return 1;
	}

	return 0;
}

int validateInput(int input)
{
	if (input <= 0 || input > 3)
	{
		return 0;
	}

	return 1;
}