#include <stdio.h>
#include "ai.h" 

static point_t find_apple(int board[M][N])
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (board[i][j] == APPLE)
				return (point_t){ i, j };
	fprintf(stderr, "Error: no apple on the board\n");
	exit(1);
}

action_t ai_action(snake_t* snake, int board[M][N])
{
	point_t apple = find_apple(board);
	action_t action_choices[] = { LEFT, FORWARD, RIGHT };
	return action_choices[rand() % 3];
}
