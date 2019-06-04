#ifndef GUI_H
#define GUI_H

#include <ncurses.h>

#include "snake.h"
#include "board.h"

void update_gui(char guiboard[M][N], int board[M][N], snake_t snake);

void draw(char guiboard[M][N], int score);

#endif
