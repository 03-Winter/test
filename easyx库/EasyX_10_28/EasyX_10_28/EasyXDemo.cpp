

#include<stdio.h>
#include<easyx.h>
#define PI 3.14
#include<math.h>

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);
	//画五个点
	//putpixel(0, 0, RED);
	//putpixel(100,100, WHITE);
	//putpixel(2000, 200, GREEN);
	//putpixel(-100, -100, BLUE);
	//putpixel(-200, -200, YELLOW);

	//随机在坐标上显示1000个点
	//int x, y;
	//for (int i = 0; i < 1000; i++)
	//{
	//	x = rand() % (800 + 1)-400;
	//	y = rand() % (600 + 1)-300;
	//	putpixel(x, y, RED);
	//}

	//绘制liang条直线
	/*line(-200, 200, 200, -200);
	line(200, -200, -200, 200);*/

	//画圆
	//for(int i=0;i<300;i+=10)
	//	circle(0, 0,i);
	//

	//画一个矩形
	//rectangle(-200, 100, 200, -100);

	//画一个椭圆
	//ellipse(-200, 100, 200, -100);

	//画一个椭圆矩形
	//roundrect(-200, 100, 200, -100, 200, 100);
	
	//画一个扇形
	//pie(-200, 100, 200, -100, 0, 2*PI );


	//画一个圆弧
	//arc(-200, 100, 200, -100, 0, PI );

	//画一个三角形和正方形
	/*POINT points[] = { {0,200},{200,-200},{-200,-200} };
	polygon(points, 3);*/
	/*POINT points[] = { {200,200},{200,-200},{-200,-200},{-200,200} };
	polygon(points, 4);*/

	//画一个五边形
	//double theta = PI / 2;
	//double delta = 2 * PI / 5;
	//int r = 300;
	//POINT points[5];
	//for (int i = 0; i < 5; i++)
	//{
	//	points[i].x = cos(theta + i * delta) * r;
	//	points[i].y = sin(theta + i * delta) * r;
	//}
	//polygon(points, 5);


	//画M图形封闭图像
	/*POINT points[8] = { {-200,200},{0,50},{200,200},{400,0},{200,150},{0,0},{-200,150},{-400,0} };
	polygon(points, 8);*/

	//画w无封闭
	/*POINT points[5] = { {-400,200},{-200,-200},{0,100},{200,-200},{400,200} };
	polyline(points, 5);*/

	//设置线的样式
	//实线
	//setlinestyle(PS_SOLID);
	//line(-300, 200, 300, 200);
	////-----------
	//setlinestyle(PS_DASH);
	//line(-300, 150, 300, 150);
	////........
	//setlinestyle(PS_DOT);
	//line(-300, 100, 300,100);
	////_._._.
	//setlinestyle(PS_DASHDOT);
	//line(-300, 50, 300, 50);
	////_.._.._..
	//setlinestyle(PS_DASHDOTDOT);
	//line(-300, 0, 300,0);
	////不可见
	//setlinestyle(PS_NULL);
	//line(-300, -50, 300, -50);

	//绘制不同端点
	//圆形端点,16为描边粗细
	//setlinestyle(PS_ENDCAP_ROUND,16);
	//line(-300, 200, 300, 200);
	////方形端点
	//setlinestyle(PS_ENDCAP_SQUARE,16);
	//line(-300, 150, 300, 150);
	////平坦端点
	//setlinestyle(PS_ENDCAP_FLAT,16);
	//line(-300, 100, 300,100);

	getchar();
	closegraph();

	return 0;
}