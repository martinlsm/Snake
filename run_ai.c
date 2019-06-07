#include <time.h>
#include "gui.h"

#define GUI

#define START_LEN		(3)
#define START_HEADING		(NORTH)

static const point_t START_POS = (point_t){15, 15};
/*
static void print_board(char guiboard[M][N])
{
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%c", guiboard[i][j]);
		}
		printf("\n");
	}
}

static void print_snake(snake_t snake)
{
	size_t head = snake.head_index;
	size_t len = snake.len;
	for (size_t i = 0; i < len; ++i) {
		size_t index = (i + head) % SNAKE_MAX_LEN;
		point_t p = snake.body[index];
		printf("[%zu](%zu,%zu)--", index, p.row, p.col);
	}
	printf("\n");
}
*/
int main() {
	srand(time(NULL));

	int		board[M][N];
	char		guiboard[M][N];
	snake_t* 	snake;
	signed char	action = FORWARD;
	int		score = 0;
	bool		ate_apple = false;

	init_board(board);
 	snake = new_snake(3, START_POS, START_HEADING);
	spawn_apple(board, *snake);

#ifdef GUI
	initscr();
#endif

	while (!terminal(board, *snake)) {

		update_gui(guiboard, board, *snake);
#ifdef GUI
		draw(guiboard, score);
		refresh();
		int keypress = getch();
		switch (keypress) {
		case 'a':
			action = LEFT;
			break;
		case 'd':
			action = RIGHT;
			break;
		default:
			action = FORWARD;
			break;
		}
		clear();
#endif

		move_snake(snake, action, board, &ate_apple);

		if (ate_apple) {
			spawn_apple(board, *snake);
			ate_apple = false;
			score += 1;
		}
	}

#ifdef GUI
	endwin();
#endif
	free_snake(snake);
	return 0;
}
