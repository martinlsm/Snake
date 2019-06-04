#include "snake.h"

snake_t* new_snake(size_t len, point_t start_pos, signed char heading_dir)
{
	snake_t* snake = malloc(sizeof(snake_t));

	snake->len = len;
	snake->body = malloc(SNAKE_MAX_LEN * sizeof(point_t));
	snake->head_index = 0;
	snake->heading_dir = heading_dir;

	int delta_row = 0;
	int delta_col = 0;
	switch (heading_dir) {
		case EAST:
			delta_col = -1;
			break;
		case NORTH:
			delta_row = +1;
			break;
		case WEST:
			delta_col = +1;
			break;
		case SOUTH:
			delta_row = -1;
			break;
	}
	for (size_t i = 0; i < len; ++i) {
		snake->body[i] = (point_t){ start_pos.row + delta_row,
		                            start_pos.col + delta_col };
	}

	return snake;
}

void free_snake(snake_t* snake) {
	free(snake->body);
	free(snake);
}

void move_snake(snake_t* snake, signed char turn_dir, int board[M][N], bool* ate_apple)
{
	point_t			curr_pos;
	point_t			next_pos;
	size_t			next_head_index;
	signed char		next_heading_dir;

	curr_pos = snake->body[snake->head_index];
	next_heading_dir = (snake->heading_dir + turn_dir) % 4;
	next_pos = next_point(curr_pos, next_heading_dir);
	next_head_index = (snake->head_index - 1) % SNAKE_MAX_LEN;

	if (board[next_pos.col][next_pos.col] == APPLE) {
		*ate_apple = true;
		++snake->len;
	}

	snake->body[next_head_index] = next_pos;
	snake->heading_dir = next_heading_dir;
	snake->head_index = next_head_index;
}

point_t* empty_positions(int board[M][N], size_t* size)
{
	int		k = 0;
	point_t* 	p = malloc(M*N * sizeof(point_t));

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (board[i][j] == GROUND)
				p[k++] = (point_t){i,j};
	*size = k;
	return p;

}
