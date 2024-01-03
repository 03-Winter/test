// EasyX_11_03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#define NODE_WIDTH 40

//绘制网格
void painGrid()
{
    //横线
    for (int y = 0; y < 600; y += NODE_WIDTH)
    {
        line(0, y, 800, y);
    }
    //竖线
    for (int x = 0; x < 800; x += NODE_WIDTH)
    {
        line(x, 0, x, 600);
    }
}

typedef struct
{
    int x, y;

}node;


//绘制蛇体
void paintsnake(node* snake, int n)
{
    int left, top, right, bottom;
    for (int i = 0; i < n; i++)
    {
        left = snake[i].x * NODE_WIDTH;
        top = snake[i].y * NODE_WIDTH;
        right = (snake[i].x+1) * NODE_WIDTH;
        bottom = (snake[i].y +1)* NODE_WIDTH;
        solidrectangle(left, top, right, bottom);
    }
}

//定义四个方向的枚举
enum direction
{
    eup,
    edown,
    eleft,
    eright
};


//使蛇动起来
node snakeMove(node* snake, int length, int direction)
{
    node tail = snake[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }
    node newhead;
    newhead = snake[0];
    if (direction == eup)
    {
        newhead.y--;
    
    }
    else if (direction == edown)
    {
        newhead.y++;
    }
    else if (direction == eleft)
    {
        newhead.x--;
    }
    else if (direction == eright)
    {
        newhead.x++;
    }

    snake[0] = newhead;

    return tail;
}


//改变蛇头方向
void changeDirection(enum direction* pd)
{
    if (_kbhit() != 0)
    {
        char c = _getch();
        switch (c)
        {
        case 'w':
            if(*pd!=edown)
            *pd = eup;
            break;
        case 's':
            if (*pd != eup)
            *pd = edown;
            break;
        case 'a':
            if (*pd != eright)
            *pd = eleft;
            break;
        case 'd':
            if (*pd != eleft)
            *pd = eright;
            break;
        }
    }
}


//随机创建食物坐标
node creatFood(node* snake, int length)
{
    node food;
    while (2)
    {
        food.x = rand() % (800 / NODE_WIDTH);
        food.y = rand() % (600 / NODE_WIDTH);
        int i;
        for (i = 0; i < length; i++)
        {
            if (snake[i].x == food.x && snake[i].y == food.y)
            {
                break;
            }
        }
        if (i < length)
            continue;
        else
            break;
    }
    return food;


}

//绘制食物样式
void paintfood(node food)
{
    int left, top, right, down;
    left = food.x * NODE_WIDTH;
    top = food.y * NODE_WIDTH;
    right = (food.x+1) * NODE_WIDTH;
    down = (food.y +1)* NODE_WIDTH;
    setfillcolor(YELLOW);
    solidrectangle(left, top, right, down);
    setfillcolor(WHITE);
}


//判断游戏结束
bool isGameOver(node* snake, int length)
{
    if (snake[0].x < 0 || snake[0].x > 800/NODE_WIDTH)
        return true;
    if (snake[0].y < 0 || snake[0].y > 600 / NODE_WIDTH)
        return true;
    for (int i = 1; i < length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}


//游戏结束后重置游戏参数函数
void reset(node* snake, int* length, enum direction* d)
{
    snake[0] = node{ 5,7 };
    snake[1] = node{ 4,7 };
    snake[2] = node{ 3,7 };
    snake[3] = node{ 2,7 };
    snake[4] = node{ 1,7 };
    *length = 5;
    *d = eright;

}



int main()
{
    
    initgraph(800, 600);
    setbkcolor(RGB(164, 225, 202));
    cleardevice();
    node snake[100] = { {5,7},{4,7},{3,7},{2,7},{1,7} };
    int length = 5;
    enum direction d=eright;
    srand((unsigned int)time(NULL));
    node food=creatFood(snake,length);

    while (1)
    {
        cleardevice();
        //绘制网格
        painGrid();
        //绘制蛇身
        paintsnake(snake, length);
        paintfood(food);

        Sleep(400);

        changeDirection(&d);
        node lasttail = snakeMove(snake, length, d);
        if (snake[0].x == food.x && snake[0].y == food.y)
        {
            if (length < 100)
            {
                snake[length] = lasttail;
                length++;
            }
            food = creatFood(snake, length);
        }
        //snakeMove(snake, length, d);

        //判断游戏是否结束
        if (isGameOver(snake,length) == true)
        {
            reset(snake, &length, &d);
            food = creatFood(snake, length);
        }
    }


    getchar();
    closegraph();
    //std::cout << "Hello World!\n";
    return 0;
}

