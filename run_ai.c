#include <time.h>

#define GUI
#define AI

#ifdef GUI
#include "gui.h"
#ifdef AI
#include "ai.h"
#endif
#else
#include <stdio.h>
#include "snake.h"
#include "board.h"
#endif


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
	snake_t* 	snake;
	signed char	action = FORWARD;
	int		score = 0;
	bool		ate_apple = false;

	init_board(board);
 	snake = new_snake(3, START_POS, START_HEADING);
	spawn_apple(board, *snake);

#ifdef GUI
	char		guiboard[M][N];
	initscr();
#endif

	while (!terminal(board, *snake)) {

#ifdef GUI
		update_gui(guiboard, board, *snake);
		draw(guiboard, score);
		refresh();
#ifdef AI
		action = ai_action(snake, board);
		getch(); // replace this
#else
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
#endif
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
	clear();
	printw("Final score: %d\n", score);
	refresh();
	getch();
	endwin();
#else
	printf("Final score: %d\n", score);
#endif
	free_snake(snake);
	return 0;
}
