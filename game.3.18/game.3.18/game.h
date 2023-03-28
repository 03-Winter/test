#pragma once
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 10

void Intiaboard(char board[ROWS][COLS], int rows,int cols,int set);

void Displayboard(char board[ROWS][COLS], int row, int col);

void Setmine(char mine[ROWS][COLS], int row, int col);

void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);


