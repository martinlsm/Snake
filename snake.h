#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_MAX_LEN		(M*N)

#define action_t	signed char
#define LEFT		(1)
#define FORWARD		(0)
#define RIGHT		(-1)

#include "board.h"

typedef struct {
	size_t len;
	size_t head_index;
	heading_t heading_dir;
	point_t* body;
} snake_t;

/* Creates a fully stretched out snake facing heading_dir */
snake_t* new_snake(size_t len, point_t start_pos, heading_t heading_dir);

void free_snake(snake_t*);

void move_snake(snake_t* snake, action_t action, int board[M][N], bool* ate_apple);

void spawn_apple(int board[M][N], snake_t snake);

bool terminal(int board[M][N], snake_t snake);

#endif
