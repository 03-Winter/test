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
	//��ʼ��������Ÿ��ڴ棬��������
	Initboard( board, ROW, COL);
	//��ʾ����
	Displayboard(board, ROW, COL);
	//�������
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
		//��������
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if(ret=='Q')
		printf("ƽ��\n");
	Displayboard(board, ROW, COL);

}
int main() 
{
	int n = 0;
	srand((unsigned int )time(NULL));
	do
	{ 
	menu();
	printf("�����룺\n");
	scanf("%d", &n);
		switch (n)
		{
		case 1:game();
			
			
			break;
		case 0:printf("�˳���Ϸ\n"); break;
		default:printf("�����������������\n"); break;
		}
	} while (n);
	return 0;
}