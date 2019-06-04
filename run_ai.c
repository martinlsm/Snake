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
	int		board[M][N];
	char		guiboard[M][N];
	snake_t* 	snake;
	signed char	ai_action;
	bool		ate_apple = false;

	init_board(board);
 	snake = new_snake(3, START_POS, START_HEADING);

#ifdef GUI
	initscr();
#endif

	for (int i = 0; i < 5; ++i) {
	// while (!terminal(snake->body[snake->head_index], board)) {

		update_gui(guiboard, board, *snake);
#ifdef GUI
		draw(guiboard, 0);
		refresh();
		getch();
		clear();
#endif

		ai_action = FORWARD;
		move_snake(snake, ai_action, board, &ate_apple);
	}

#ifdef GUI
	endwin();
#endif
	free_snake(snake);
	return 0;
}
