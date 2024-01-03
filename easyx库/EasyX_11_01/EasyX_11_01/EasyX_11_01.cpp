// EasyX_11_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<conio.h>
//#include <iostream>
#define PI 3.14

//绘制移动的五角星

void FivePointstart(int x,int y,int r, double startangle)
{
	double theta = 2 * PI / 5;
	POINT point[5];
	for (int i = 0; i < 5; i++)
	{
		point[i].x = cos(startangle + i * theta*2) * r+x;
		point[i].y = sin(startangle + i * theta*2) * r+y;

	}
	solidpolygon(point, 5);

}


int main()
{
  /*  std::cout << "Hello World!\n";*/
	//设置图画坐标
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	//设置背景
	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	//制作移动的圆
	//int i=0, y=0;
	//for (int i = -400; i <= 400; i += 5)
	//{
	//	cleardevice();
	//	solidcircle(i, y, 50);
	//	Sleep(40);
	//}
	//绘制移动的五角星函数
	//setfillcolor(WHITE);
	//setpolyfillmode(WINDING);
	//int x = 0, y = 0;
	//for (int i = -400; i <= 400; i+=5) {
	//	cleardevice();
	//	FivePointstart(i, 0, 50, PI / 2);
	//	Sleep(40);
	//}
	//做五角星往返运动
	//int x = -400, y = 0,dx=5;
	//while (1) {
	//	cleardevice();
	//	FivePointstart(x, y, 50, PI / 2);
	//	Sleep(40);
	//	x += dx;
	//	if (x < -400 || x>400) {
	//		dx = -dx;
	//	}

	//}
	//五角星做矩形运动
	//int x = -300, y = 200;
	//int dx = 5, dy = 5;

	//while (1)
	//{
	//	if (x == -300 && y == 200)
	//	{
	//		dx = 5;
	//		dy = 0;
	//	}
	//	if (x == 300 && y == 200)
	//	{
	//		dx = 0;
	//		dy = -5;
	//	}
	//	if (x == 300 && y == -200)
	//	{
	//		dx = -5;
	//		dy = 0;
	//	}
	//	if (x == -300 && y == -200)
	//	{
	//		dx = 0;
	//		dy = 5;
	//	}
	//	cleardevice();
	//	FivePointstart(x, y, 50, PI / 2);
	//	Sleep(40);
	//	x += dx;
	//	y += dy;
	//}

	//五角星做圆周运动且自转
	//int x, y;
	//int r = 200;
	//double theta = 0, dtheta = 0.05,startangle=PI/2,dstartangle=0.05;
	//while (1)
	//{
	//	x = cos(theta) * r;
	//	y = sin(theta) * r;
	//	cleardevice();
	//	FivePointstart(x, y, 50, startangle);
	//	Sleep(40);
	//	theta += dtheta;
	//	startangle += dstartangle;
	//}


	//实现键盘交互
	//int x = 0, y = 0;
	//int dx = 5, dy = 0;
	//setfillcolor(WHITE);
	//solidcircle(x, y, 50);
	//while (1)
	//{
	//	cleardevice();
	//	solidcircle(x, y, 50);
	//	Sleep(40);



	//	if (_kbhit() != 0)
	//	{
	//		char c = 0;
	//		c = _getch();
	//		switch (c)
	//		{
	//		case 'w':
	//			dx = 0;
	//			dy = 5;
	//			break;
	//		case 'a':
	//			dx = -5;
	//			dy = 0;
	//			break;
	//		case 's':
	//			dx = 0;
	//			dy = -5;
	//			break;
	//		case 'd':
	//			dx = 5;
	//			dy = 0;
	//			break;

	//		}
	//	}
	//	x += dx;
	//	y += dy;
	//}

	


	getchar();
	closegraph();

	return 0;
}

