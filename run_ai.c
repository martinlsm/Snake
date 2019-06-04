#include "gui.h"

#define START_LEN		(3)
#define START_HEADING	(NORTH)

static const point_t START_POS = (point_t){15, 15};

int main() {
	int		board[M][N];
	char		guiboard[M][N];
	snake_t* 	snake = new_snake(3, START_POS, START_HEADING);
	signed char	ai_action;
	bool		ate_apple = false;

	update_gui(guiboard, board, *snake);
	draw(guiboard, 34);
	getch();
	endwin();

	/*
	while (!terminal(snake->body[snake->head_index], board)) {


		// ai_action = FORWARD; // get ai action

		// move(snake, ai_action, board, &ate_apple);

		// Print board
	}
	*/
	return 0;
}
