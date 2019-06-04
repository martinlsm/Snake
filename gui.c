#include "gui.h"

void update_gui(char guiboard[M][N], int board[M][N], snake_t snake)
{
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int b = board[i][j];
			switch (b) {
			case GROUND:
				guiboard[i][j] = ' ';
				break;
			case WALL:
				guiboard[i][j] = 'W';
				break;
			case APPLE:
				guiboard[i][j] = 'O';
				break;
			}
		}
	}

	size_t head = snake.head_index;
	size_t len = snake.len;

	for (size_t i = 0; i < len; ++i) {
		point_t p = snake.body[(i + head) % SNAKE_MAX_LEN];
		guiboard[p.row][p.col] = 'S';
	}
}

void draw(char guiboard[M][N], int score)
{
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printw("%c", guiboard[i][j]);
		}
		printw("\n");
	}
	printw("\n\nCurrent score: %d\n", score);
}
