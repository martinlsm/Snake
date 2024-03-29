#include <stdio.h>
#include <memory.h>
#include "snake.h"

#define snake_body_part(snake, n)	(((snake).head_index + (n)) % SNAKE_MAX_LEN)

snake_t* new_snake(size_t len, point_t start_pos, heading_t heading_dir)
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

	size_t place_row = start_pos.row;
	size_t place_col = start_pos.col;
	for (size_t i = 0; i < len; ++i) {
		snake->body[i] = (point_t){ place_row, place_col };
		place_row += delta_row;
		place_col += delta_col;
	}

	return snake;
}

void free_snake(snake_t* snake) {
	free(snake->body);
	free(snake);
}

void move_snake(snake_t* snake, action_t action, int board[M][N], bool* ate_apple)
{
	point_t			curr_pos;
	point_t			next_pos;
	size_t			next_head_index;
	heading_t		next_heading_dir;

	curr_pos = snake->body[snake->head_index];
	next_heading_dir = (4 + snake->heading_dir + action) % 4;
	next_pos = next_point(curr_pos, next_heading_dir);

	if (snake->head_index > 0)
		next_head_index = snake->head_index - 1;
	else
		next_head_index = SNAKE_MAX_LEN - 1;

	if (board[next_pos.row][next_pos.col] == APPLE) {
		*ate_apple = true;
		++snake->len;
		board[next_pos.row][next_pos.col] = GROUND;
	}

	snake->body[next_head_index] = next_pos;
	snake->heading_dir = next_heading_dir;
	snake->head_index = next_head_index;
}

void spawn_apple(int board[M][N], snake_t snake)
{
	int		board_with_snake[M][N];
	point_t		free_spots[M*N];
	int		n = 0;


	memcpy(board_with_snake, board, M*N);
	for (size_t i = 0; i < snake.len; ++i) {
		size_t index = (snake.head_index + i) % SNAKE_MAX_LEN;
		point_t p = snake.body[index];
		board_with_snake[p.row][p.col] = WALL; // mark snake body as wall
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board_with_snake[i][j] == GROUND)
				free_spots[n++] = (point_t){ i, j };
		}
	}

	int	random = rand() % n;
	point_t	apple_p = free_spots[random];
	board[apple_p.row][apple_p.col] = APPLE;
}

bool terminal(int board[M][N], snake_t snake)
{
	point_t		head = snake.body[snake.head_index];
	int		head_point = board[head.row][head.col];
	for (size_t i = 1; i < snake.len; ++i) {
		size_t index = (snake.head_index + i) % SNAKE_MAX_LEN;
		point_t p = snake.body[index];
		if (p.row == head.row && p.col == head.col)
			return true;
	}
	return (head_point > 0 || head_point == WALL);
}
