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
	//�����������飬һ�����ף�һ����ʾ
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	Intiaboard(mine, ROWS, COLS,'0');
	Intiaboard(show, ROWS, COLS,'*');
	//��ʾ����
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//������
	Setmine(mine,ROW,COL);
	//Displayboard(mine, ROW, COL);

	//����
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
		printf("�����룺>");
		scanf("%d", &n);
		switch (n)
		{
		case 1:game();
		case 0:break;
		default:printf("����������������롣");
		}
	} while (n);
	return 0;
}