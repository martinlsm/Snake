#include "snake.h"

point_t next_point(point_t from, heading_t heading_dir)
{
	point_t		new_point = from;

	switch (heading_dir) {
		case EAST:
			++new_point.col;
			break;
		case NORTH:
			--new_point.row;
			break;
		case WEST:
			--new_point.col;
			break;
		case SOUTH:
			++new_point.row;
			break;
	}
	return new_point;
}

int score(point_t loc, int board[M][N])
{
	int	val = board[loc.row][loc.col];

	if (val == WALL || val == APPLE)
		return 1;
	else
		return 0;
}

void init_board(int board[M][N])
{
	for (int i = 0; i < M; ++i) {
		board[i][0] = WALL;
		board[i][N - 1] = WALL;
	}

	for (int j = 0; j < N; ++j) {
		board[0][j] = WALL;
		board[M - 1][j] = WALL;
	}

	for (int i = 1; i < M - 1; ++i)
		for (int j = 1; j < N - 1; ++j)
			board[i][j] = GROUND;
}
