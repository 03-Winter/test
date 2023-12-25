// EasyX11_11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include<easyx.h>
//#include <iostream>

int main()
{
    initgraph(800, 600);
    setbkcolor(WHITE);
    cleardevice();
    settextcolor(RGB(164, 225, 202));

    //C语言不允许函数同名
    //但是c++允许,叫做重载
    //第三个参数代表不同字符的指针
    //需要在设置中改为未设置，因为设置默认字符集
    outtextxy(0, 0, "Helld，你好世界。");
    //outtextxy(0, 300, 'A');

    //rect 是一个是结构体指针，绘制文字区域
    RECT recr;
    recr.left = 200;
    recr.top = 200;
    recr.right = 200;
    recr.bottom= 200;
    rectangle(recr.left, recr.top, recr.right, recr.bottom);

    const char* str = "你好世界";
    drawtext(str, &recr, DT_CENTER);



    //设置字体大小,版本一
    //传入长宽和字体样式
    settextstyle(0, 0, "微软雅黑");

    //版本二
    //传入一个结构体，再通过gettextstyle函数改变参数
    //LOGFONT fronstyle;
    //gettextstyle(&fronstyle);
    //fronstyle.lfItalic = true;
    //fronstyle.lfUnderline = true;
    //fronstyle.lfQuality = ANTIALIASED_QUALITY;
    //settextstyle(&fronstyle);




    //设置字体后面背景
    setbkmode(TRANSPARENT);



    //cleardevice();
    getchar();
    closegraph();
    //std::cout << "Hello World!\n";
}
