#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<windows.h>
//小球弹跳


//
//int main()
//{
//	int i, j, x = 5, y = 20;
//	int velocity_x = 5;
//
//	int velocity_y = 5;
//	int top = 5, bottom = 20, left = 5, right = 20;
//	while (1)
//	{
//		
//		x += velocity_x;
//		y += velocity_y;
//
//		system("cls");//清空函数
//
//		for (i = 0; i < x; i++)
//			printf("\n");
//		for (j = 0; j < y; j++)
//			printf(" ");
//		Sleep(100);//待机0.1秒
//		printf("0\n");
//		if (x == top || x == bottom)
//		{
//			velocity_x=-velocity_x;
//		}
//		if (y == left || y == right)
//		{
//			velocity_y=-velocity_y;
//		}
//	}
//	
//	return 0;
//}
#include<time.h>
#include<stdlib.h>
//简单飞机小游戏
int main()
{
	int i, j, x = 5, y = 5;
	int isFired = 0, iswin = 0;
	char input;
	int np;
	srand((unsigned int)time(NULL));
	np = rand() % 10;

	//printf("%d", np);
	while (1)
	{
		system("cls");
		for (i = 0; i < np; i++)
			printf("  ");
		printf("  +\n");

		if (isFired == 1)//是否发射子弹
		{
			for (i = 0; i < x; i++)
			{
				for (j = 0; j < y; j++)
				{
					printf("  ");
				}
				printf("  |\n");
			}
			if (y  == np)
			{
				printf("你打中了");
				break;
			}
			isFired = 0;
		}
		else
		{
			for (i = 0; i < x; i++)
				printf("\n");
		}
	

		for (j = 0; j < y; j++)//打印飞机模型
			printf("  ");
		printf("  *\n");
		for (j = 0; j < y; j++)
			printf("  ");
		printf("*****\n");
		for (j = 0; j < y; j++)
			printf("  ");
		printf(" * *\n");

		input = getch();//getch函数优势：输入显示

		//w:上  a：左  d：右  s：下
		if (input == ' ')
			isFired = 1;
		if (input == 'w')
			x--;
		if (input == 's')
			x++;
		if (input == 'a')
			y--;
		if (input == 'd')
			y++;

	}
	return 0;
}