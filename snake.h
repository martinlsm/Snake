#ifndef SNAKE_H
#define SNAKE_H

#include "board.h"

typedef struct {
	size_t len;
	size_t max_len;
	size_t head_index;
	signed char heading_dir;
	point_t* body;
} snake_t;

/* Creates a fully stretched out snake facing heading_dir */
snake_t* new_snake(size_t len, size_t max_len,
                   point_t start_pos, signed char heading_dir);

void free_snake(snake_t*);

void move(snake_t* snake, signed char turn_dir, int board[M][N]);

#endif
