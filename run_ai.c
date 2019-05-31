#include "board.h"
#include "snake.h"

#define START_LEN		(3)
#define START_HEADING	(NORTH)

static const point_t START_POS = (point_t){15, 15};

int main() {
	int board[M][N];
	snake_t* snake = new_snake(3, M*N, START_POS, START_HEADING);
	signed char ai_action;

	while (!terminal(snake->body[snake->head_index], board)) {

		ai_action = FORWARD; // get ai action

		move(snake, ai_action, board);

		// Print board
	}
	return 0;
}
