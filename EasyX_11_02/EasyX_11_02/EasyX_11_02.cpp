// EasyX_11_02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include<stdio.h>
#include<easyx.h>
#include<math.h>
#include<conio.h>
#include<time.h>
//实现直线运动函数
void LinearMotion(int x1, int y1, int x2, int y2, int v)
{
	double vx, vy;
	if (y1 == y2)
	{
		vx = v;
		vy = 0;
	}
	else if (x1 == x2)
	{
		vy = v;
		vx = 0;
	}
	else
	{
		double tantheta = (double)abs(y2 - y1) / (double)abs(x2 - x1);
		double theta = atan(tantheta);

		vx = cos(theta) * v;
		vy = sin(theta) * v;
	}

	int flagx = 0, flagy = 0;
	if (x2 - x1>0)
	{
		flagx = 1;
	}
	else if (x2 - x1<0)
	{
		flagx = -1;
	}
	if (y2 - y1>0)
	{
		flagy = 1;
	}
	 else if (y2 - y1<0)
	{
		flagy = -1;
	}
	vx = vx * flagx;
	vy = vy * flagy;
	if (vx == 0 && vy == 0)
		return;
	double x, y;
	x = x1;
	y = y1;

	while (1)
	{
		cleardevice();
		solidcircle(x, y, 25);
		Sleep(40);
		x += vx;
		y += vy;

		if (flagx == 1)
		{
			if (x >= x2)
				break;
		}
		else if (flagx == -1)
		{
			if (x <= x2)
				break;
		}
		if (flagy == 1)
		{
			if (y >= y2)
				break;
		}
		else if (flagy == -1)
		{
			if (y <= y2)
				break;
		}



	}
}


//将数据进行结构体封装
typedef struct
{
	int x, y;
	int vx, vy;
	int r;
	int barleft, bartop, barright, barbottom;
}Gamedata;

//将随机坐标函数
void reset(Gamedata* gdata)
{
	gdata->x=rand() % (400 + 1) - 200;
	gdata->y = rand() % (400 + 1) - 200;
	gdata->vx = 5;
	gdata->vy = 5;
	if (rand() % 2 == 0)
	{
		gdata->vx = -gdata->vx;
	}
	if (rand() % 2 == 0)
	{
		gdata->vy = -gdata->vy;
	}

	gdata->r = 40;
	gdata->barleft = -150;
	gdata->bartop = -280;
	gdata->barright = 150; 
	gdata->barbottom = -300;
}



int main()
{

	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	
   /* std::cout << "Hello World!\n";*/

	setbkcolor(RGB(164, 225, 202));
	cleardevice();
	//LinearMotion(0, 200, 200, -200, 5);
	//LinearMotion(200, -200, -200, -200, 5);
	//
	//LinearMotion(-200, -200, 0, 200, 5);



	//实现弹球小游戏
	srand((unsigned int)time(NULL));

	Gamedata gdata;
	reset(&gdata);


	while (1) 
	{
		cleardevice();
		solidcircle(gdata.x, gdata.y, gdata.r);
		solidrectangle(gdata.barleft, gdata.bartop, gdata.barright, gdata.barbottom);

		Sleep(40);


		if (gdata.x >= 400- gdata.r|| gdata.x<=-400+ gdata.r)
		{
			gdata.vx = -gdata.vx;
		}
		if (gdata.y >= 300- gdata.r)
		{
			gdata.vy = -gdata.vy;
		}
		if (gdata.y <= gdata.bartop+ gdata.r&& gdata.x>= gdata.barleft&& gdata.x<= gdata.barright)
		{
			gdata.vy = -gdata.vy;
		}
		gdata.x += gdata.vx;
		gdata.y += gdata.vy;
		if (_kbhit() != 0) {
			char c = _getch();
			if (c == 'a')
			{
				if (gdata.barleft >= -400)
				{
					gdata.barleft -= 20;
					gdata.barright -= 20;
				}
			}
			else if (c == 'd')
			{
				if (gdata.barright <=400)
				{
					gdata.barleft += 20;
					gdata.barright += 20;
				}
			}
		}
		if (gdata.y <= -400)
		{
			reset(&gdata);
		}
	}

	
	closegraph();

}

