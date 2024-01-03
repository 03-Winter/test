// EesyX_10_31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include<stdio.h>
#include<easyx.h>

#include<math.h>

#include<conio.h>

int main(void)
{
    initgraph(800, 600);
    //setaspectratio(1, -1);
    setbkcolor(RGB(233, 170, 0));
    cleardevice();

    //左耳朵
    setfillcolor(RGB(130, 69, 4));
     solidcircle(200, 130, 87);
     solidcircle(600, 130, 87);
    //右耳朵
    setfillcolor(RGB(255, 230, 50));
    solidcircle(200, 120, 87);
    solidcircle(600, 120, 87);
    //设置剪切区域，突出高光
    HRGN leftearClip = CreateEllipticRgn(110, 30, 290, 210);
    HRGN rightearClip = CreateEllipticRgn(510, 30, 690, 210);
    HRGN earClip = CreateEllipticRgn(0, 0, 0, 0);
    CombineRgn(earClip, leftearClip, rightearClip, RGN_OR);
    setcliprgn(earClip);

    setfillcolor(RGB(243, 154, 2));
    solidcircle(200, 130, 90);
    solidcircle(600, 130, 90);

    setfillcolor(RGB(255, 230, 50));
    solidcircle(200, 210, 90);
    solidcircle(600, 210, 90);

    //释放剪切区域
    DeleteObject(rightearClip);
    DeleteObject(earClip);
    DeleteObject(leftearClip);
    setcliprgn(NULL);
    //头部
    setfillcolor(RGB(255, 230, 50));
    solidcircle(400, 300, 245);
    //头部高光
    HRGN headClip = CreateEllipticRgn(150,50,650,550);
    setcliprgn(headClip);
    setfillcolor(RGB(243, 154,2));
    solidcircle(400,320, 250);

    DeleteObject(headClip);
    setcliprgn(NULL);
    
    //眼睛
    setfillcolor(RGB(51, 34, 8));
    solidcircle(275, 300, 25);
    solidcircle(525, 300, 25);

    //嘴巴
    setfillcolor(RGB(130, 69, 4));
    solidellipse(310, 385, 490, 485);
    setfillcolor(WHITE);
    solidellipse(310, 380, 490, 480);

    //绘制鼻子和胡须
    setfillcolor(RGB(51, 34, 8));
    solidcircle(400, 420, 15);
    setlinestyle(PS_SOLID, 5);
    setlinecolor(RGB(51, 34, 8));
    line(400, 420, 370, 450);
    line(400, 420, 430, 450);






    getchar();
    closegraph();
    return 0;
}

