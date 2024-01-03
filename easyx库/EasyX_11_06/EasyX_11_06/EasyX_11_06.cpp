// EasyX_11_06.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include <iostream>
#include<easyx.h>
#include<conio.h>
#include<math.h>
#include<time.h>

#define BEAR_FRAMES 11

//加载透明图片
void PutTransparentImage(int x, int y,const IMAGE* mask,const IMAGE* bear)
{
    putimage(x, y, mask, SRCAND);
    putimage(x, y, bear, SRCPAINT);
}



int main()
{
    /*std::cout << "Hello World!\n";*/
    initgraph(1200, 480);
    //setorigin(400, 300);
    //setaspectratio(1, -1);
    setbkcolor(WHITE);
    cleardevice();

    IMAGE imgbkground;
    loadimage(&imgbkground, "./background.jpg");
    IMAGE imgbearmask[BEAR_FRAMES];
    for (int i = 0; i < BEAR_FRAMES; i++)
    {
        char strimgpath[100];
        sprintf(strimgpath, "./bear/frames/bearmask%d.png", i);
        loadimage(&imgbearmask[i], strimgpath);
    }
    IMAGE imgbearFrame[BEAR_FRAMES];
    for (int i = 0; i < BEAR_FRAMES; i++)
    {
        char strimgpath[100];
        sprintf(strimgpath, "./bear/frames/bear%d.png", i);
        loadimage(&imgbearFrame[i], strimgpath);
    }


    int frame = 0; //图片数组的下标
    int x = -150;//熊的坐标

    BeginBatchDraw();

    while (1)
    {
        putimage(0, 0, &imgbkground);
        PutTransparentImage(x, 180, &imgbearmask[frame], &imgbearFrame[frame]);

        FlushBatchDraw();
        frame++;
        x += 10;
        if (frame >= 11)
        {
            frame = 0;
        }
        if (x >= 1200 + 150)
        {
            x = -150;
        }
        Sleep(40);
    }
    EndBatchDraw();


    //BeginBatchDraw();
    //solidcircle(-300, 0, 20);
    //Sleep(1000);
    //solidcircle(-200, 0, 20);
    //Sleep(1000);

    //FlushBatchDraw();
    //                        //beginbatchdraw,endbatchdraw将绘图函数包括起来
    //solidcircle(-100, 0, 20);//flushbatchdraw将显示之前累计的俩个圆形
    //Sleep(1000);
    //solidcircle(0, 0, 20);
    //Sleep(1000);


    //EndBatchDraw();


    //IMAGE img;
    //loadimage(&img, "./background.jpg");
    ////putimage(0, 0, &img);
    ////图像重叠，解决一
    ////loadimage(&img, "./bear.png",0,0,true);
    ////解决二
    //IMAGE imgbear;
    //loadimage(&imgbear, "./bear.png");
    ////putimage(530, 180, &img);
    //IMAGE mask;
    //loadimage(&mask,"./mask.jpg");

    //putimage(0, 0, &img);
    //putimage(530, 180, &mask, SRCAND);
    //putimage(530, 180, &imgbear, SRCPAINT);


    getchar();
    closegraph();
    return 0;
}

