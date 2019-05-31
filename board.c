#include "snake.h"

point_t next_point(point_t from, signed char heading_dir)
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

bool terminal(point_t loc, int board[M][N])
{
	int	val = board[loc.row][loc.col];
	return (val > 0 || val == WALL);
}