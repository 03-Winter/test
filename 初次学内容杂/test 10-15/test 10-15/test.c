#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<windows.h>
//С����


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
//		system("cls");//��պ���
//
//		for (i = 0; i < x; i++)
//			printf("\n");
//		for (j = 0; j < y; j++)
//			printf(" ");
//		Sleep(100);//����0.1��
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
//�򵥷ɻ�С��Ϸ
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

		if (isFired == 1)//�Ƿ����ӵ�
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
				printf("�������");
				break;
			}
			isFired = 0;
		}
		else
		{
			for (i = 0; i < x; i++)
				printf("\n");
		}
	

		for (j = 0; j < y; j++)//��ӡ�ɻ�ģ��
			printf("  ");
		printf("  *\n");
		for (j = 0; j < y; j++)
			printf("  ");
		printf("*****\n");
		for (j = 0; j < y; j++)
			printf("  ");
		printf(" * *\n");

		input = getch();//getch�������ƣ�������ʾ

		//w:��  a����  d����  s����
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