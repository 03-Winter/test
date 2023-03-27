#define _CRT_SECURE_NO_WARNINGS  1
#include "game.h"
void menu()
{
	printf("*************************\n");
	printf("*********  1.play *******\n");
	printf("*********  0.exit  ******\n");
	printf("*************************\n");
	

}
void game()
{
	char board[ROW][COL];
	//初始化，申请九个内存，构建棋盘
	Initboard( board, ROW, COL);
	//显示棋盘
	Displayboard(board, ROW, COL);
	//玩家下棋
	char ret=0;
	while (1)
	{
		Playmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
			if(ret !='C')
			{
				break;
			}
		//电脑下棋
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if(ret=='Q')
		printf("平局\n");
	Displayboard(board, ROW, COL);

}
int main() 
{
	int n = 0;
	srand((unsigned int )time(NULL));
	do
	{ 
	menu();
	printf("请输入：\n");
	scanf("%d", &n);
		switch (n)
		{
		case 1:game();
			
			
			break;
		case 0:printf("退出游戏\n"); break;
		default:printf("输入错误，请重新输入\n"); break;
		}
	} while (n);
	return 0;
}