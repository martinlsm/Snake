#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdbool.h>

#define M		(30)
#define N		(30)

#define EAST		(0)
#define NORTH		(1)
#define WEST		(2)
#define SOUTH		(3)

#define LEFT		(1)
#define FORWARD		(0)
#define RIGHT		(-1)

#define WALL		(-1)
#define GROUND		(0)
#define APPLE		(-2)

typedef struct {
	size_t row;
	size_t col;
} point_t;

point_t next_point(point_t from, signed char heading_dir);

int score(point_t loc, int board[M][N]);

bool terminal(point_t loc, int board[M][N]);

void init_board(int board[M][N]);

#endif
