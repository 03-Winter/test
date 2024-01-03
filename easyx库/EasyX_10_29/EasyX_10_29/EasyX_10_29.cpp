// EasyX_10_29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include<easyx.h>
#include <iostream>
#define PI 3.14
int main()
{
   /* std::cout << "Hello World!\n";*/
	//初始化画布
	initgraph(1000, 1000);
	//设置圆心
	/*setorigin(400, 300);*/
	//翻转y轴
	//setaspectratio(1, -1);


	//连接处为斜面
	//setlinestyle(PS_JOIN_BEVEL, 64);
	//POINT point1[3] = { {-150,100},{0,200},{150,100} };
	//polyline(point1,3);
	////连接处为斜接
	//setlinestyle(PS_JOIN_MITER, 64);
	//POINT point2[3] = { {-150, 0},{0,100},{150, 0} };
	//polyline(point2, 3);
	////连接处为圆弧
	//setlinestyle(PS_JOIN_ROUND, 64);
	//POINT point3[3] = { {-150,-100},{0,0},{150,-100} };
	//polyline(point3, 3);

	//绘制填充图形
	//setfillcolor(RED);
	//solidcircle(0, 0, 200);
	setbkcolor(WHITE);
	cleardevice();
	//绘制即填充又描边图形
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 10);
	setfillcolor(BLUE);
	fillellipse(88, 95,890, 831);

	setfillcolor(WHITE);
	fillellipse(159, 200, 820, 831);
	//眼睛
	fillellipse(330, 120, 510, 360);
	fillellipse(510, 120, 680, 360);
	//眼珠
	setfillcolor(BLACK);
	solidcircle(440, 300, 25);
	solidcircle(570, 300, 25);

	setfillcolor(WHITE);
	solidcircle(450, 300, 10);
	solidcircle(580, 300, 10);

	//鼻子和线
	setfillcolor(RED);
	solidcircle(510, 370, 35);
	line(510, 410, 510, 710);

	//嘴巴
	arc(280, 470, 740, 710, PI, 2 * PI);

	//胡须
	line(70,260,250,380);
	line(30,390,230,440);
	line(30,540,220,520);
	line(710,360,920,280);
	line(730,420,950,400);
	line(740,500,950,550);




	getchar();
	closegraph();

	return 0;
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
