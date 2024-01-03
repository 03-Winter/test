#define _CRT_SECURE_NO_WARNINGS  1

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("********* 1.play **********\n");
	printf("********* 2.exit **********\n");
	printf("***************************\n");

}

void game()
{
	//建立俩个数组，一个放雷，一个显示
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	Intiaboard(mine, ROWS, COLS,'0');
	Intiaboard(show, ROWS, COLS,'*');
	//显示棋盘
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	//Displayboard(mine, ROW, COL);

	//找雷
	Findmine(mine, show, ROW,COL);
	Displayboard(show, ROW, COL);



}
int main()
{
	int n=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:game();
		case 0:break;
		default:printf("输入错误，请重新输入。");
		}
	} while (n);
	return 0;
}