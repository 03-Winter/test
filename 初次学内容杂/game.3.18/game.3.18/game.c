#define _CRT_SECURE_NO_WARNINGS  1

#include "game.h"

void Intiaboard(char board[ROWS][COLS], int rows, int cols,int set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int j = 0, i = 0;
	printf("---------------ɨ����Ϸ----------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)

		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------ɨ����Ϸ----------------\n");

}


void Setmine(char mine[ROWS][COLS], int row, int col)
{
	
	int count = MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


int Numbermine(char mine[ROW][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	printf("����������:>");
	int x, y,win=0;
	while (win<row*col-MINE)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����~��\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int sum = Numbermine(mine, x,y);
				show[x][y] = sum + '0';
				Displayboard(show, ROW, COL);

			}
		}
		else
		{
			printf("���겻�Ϸ�������������:>\n");
		}
	}
	if (win == row * col - MINE)
	{
		printf("��ϲ�㣬ɨ�׳ɹ�~��\n");
		Displayboard(mine, ROW, COL);

	}
}
