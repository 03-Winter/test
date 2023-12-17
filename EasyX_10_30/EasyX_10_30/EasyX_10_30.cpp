// EasyX_10_30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include<easyx.h>
#include <iostream>
#include<math.h>
#define PI 3.14

int main()
{
	//initgraph(800, 600);
	//setaspectratio(1, -1);
	//setbkcolor(RGB(134, 173, 242));
	//cleardevice();

	//setbkcolor(HSVtoRGB(134, 1, 1));
	//cleardevice();

	//彩虹背景
	/*float dh = 360.0 / 600.0;
	float h = 0;
	for (int i = 0; i < 600; i++)
	{
		setlinecolor(HSVtoRGB(h, 1, 1));
		line(0, i, 800, i);
		h += dh;

	}*/

	//做一个天蓝色的天空和彩虹
	//float s = 0.76;
	//float ds = s/ 600;
	//for (int i = 0; i <600; i++)
	//{
	//	setlinecolor(HSVtoRGB(216, s, 0.95));
	//	line(0, i, 800, i);
	//	s -= ds;

	//}

	//float h = 0;
	//float dh = 360.0 / 100.0;
	//for (int i = 300; i > 200; i--)
	//{
	//	setlinecolor(HSVtoRGB(h, 1, 1));
	//	circle(400, 600, i);
	//	h += dh;
	//}

	//做一个显示器
	//setbkcolor(WHITE);
	//cleardevice();
	////绘制外形圆角矩形加上白色
	//setfillcolor(RGB(232, 235, 240));
	//solidroundrect(100, 50, 700, 450, 20, 20);
	//setfillcolor(RGB(71, 78, 94));
	//solidrectangle(100, 390, 700, 410);
	//solidroundrect(100, 50, 700, 410, 20, 20);
	////绘制屏幕
	//setfillcolor(RGB(115, 199, 235));
	//solidrectangle(120, 70, 680, 390);
	////绘制开机键和摄像头
	//setfillcolor(RGB(232,235,240));
	//solidcircle(400, 60, 5);
	//setfillcolor(RGB(71, 78, 94));
	//solidcircle(400, 430, 12);
	////绘制底座和支柱
	//setfillcolor(RGB(218,219,224));
	//solidellipse(275, 515, 525, 545);

	//setfillcolor(RGB(232, 235, 240));
	//POINT points[4] = { {345,450},{455,450},{475,530},{325,530} };
	//solidpolygon(points, 4);
	////绘制支柱上的阴影
	//setfillcolor(RGB(219, 219, 224));
	//POINT arr[4] = { {345,450},{455,450},{460,470},{340,470} };
	//solidpolygon(arr, 4);

	initgraph(800, 800);
	setorigin(400, 400);
	setaspectratio(1, -1);
	//圆圆交错
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 8);

	int r = 150;
	////剪切中间的圆
	//HRGN rgn = CreateEllipticRgn(250, 250, 550, 550);
	//setcliprgn(rgn);

	//设置剪切模式
	HRGN rgn1 = CreateEllipticRgn(250, 250, 550, 500);
	HRGN rgn2 = CreateEllipticRgn(250, 100, 550, 400);
	HRGN rgn = CreateEllipticRgn(0, 0, 0, 0);
	//交集
	//CombineRgn(rgn, rgn1, rgn2, RGN_AND);
	// 差集
	//CombineRgn(rgn, rgn1, rgn2, RGN_DIFF);
	// 并集
	//CombineRgn(rgn, rgn1, rgn2, RGN_OR);
	// 并集并排除重叠的部分
	//CombineRgn(rgn, rgn1, rgn2, RGN_XOR);

	setcliprgn(rgn);

	circle(0, 0, r);
	for (int i = 0; i < 6; i++)
	{
		int x, y;
		x = cos(i * PI/3) * r;
		y = sin(i * PI/ 3) * r;
		circle(x, y, r);
	}

	//设置空和销毁区域
	setcliprgn(NULL);
	DeleteObject(rgn);
	DeleteObject(rgn1);
	DeleteObject(rgn1);


	////绘制成功后将剪切区域设置为空
	//setcliprgn(NULL);
	////销毁区域
	//DeleteObject(rgn);
	getchar();
	closegraph();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
