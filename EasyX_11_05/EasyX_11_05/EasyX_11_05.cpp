// EasyX_11_05.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<conio.h>
#include<time.h>

#define NUM_OF_BALLS 1000
#define PI 3.14
typedef struct
{
	int x, y, vx, vy;
	COLORREF color;
}ball;

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	cleardevice();

	//实现多物体运动
	//当数组较小时，可以用栈空间，然而数组过大时，需要改成推空间
	//ball balls[NUM_OF_BALLS];
	ball* balls = (ball*)malloc(sizeof(ball) * NUM_OF_BALLS);
	if (balls == NULL)
	{
		return -1;
	}

	int r = 10;
	//srand((unsigned int)time)
	//随机变量
	for (int i = 0; i < NUM_OF_BALLS; i++)
	{
		int m, n;
		//x坐标随机

		m = -400 + r;
		n = 400 - r;
		balls[i].x = rand() % (n - m + 1) + m;
		//y坐标随机
		m = -300 + r;
		n = 300 - r;
		balls[i].y = rand() % (n - m + 1) + m;
		//随机小球颜色
		balls[i].color = HSVtoRGB((float)(rand() % 360), 0.8f, 0.9f);

		//设置速度随机
		m = 3, n = 8;
		int v = rand() % (n - m + 1) + m;
		double theta = rand() % 360;
		//函数是实行弧度制，所以角度转化
		balls[i].vx = v * cos(theta * PI / 180);
		balls[i].vy = v * sin(theta * PI / 180);


	}
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		for (int i = 0; i < NUM_OF_BALLS; i++)
		{
			setfillcolor(balls[i].color);
			fillcircle(balls[i].x, balls[i].y, r);
		}
		Sleep(40);

		FlushBatchDraw();

		//版本一
		//if (x <= -400 + r || x>=400 - r)
		//{
		//	vx = -vx;
		//}
		//if (y <= -300 + r || y >= 300 - r)
		//{
		//	vy = -vy;;
		//}
		//x += vx;
		//y += vy;

		//版本二
		for (int i = 0; i < NUM_OF_BALLS; i++)
		{
			if (balls[i].x <= -400 + r || balls[i].x >= 400 - r)
			{
				balls[i].vx = -balls[i].vx;
			}
			if (balls[i].y <= -300 + r || balls[i].y >= 300 - r)
			{
				balls[i].vy = -balls[i].vy;

			}
			balls[i].x += balls[i].vx;
			balls[i].y += balls[i].vy;

		}

	}
	EndBatchDraw();

	//getchar();
	closegraph();

	return 0;
}

