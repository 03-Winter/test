#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int DataType;
/// <summary>
/// leetcode上用栈实现队列题目
/// </summary>
typedef struct Stack {
    DataType* a;
    int top;
    int capacity;

}SL;

void StackInit(SL* ps);
void StackDeatroy(SL* ps);
void StackPush(SL* ps, DataType x);
void StackPop(SL* ps);
DataType StackTop(SL* ps);
int StackSize(SL* ps);
bool StackEmpty(SL* ps);


void StackInit(SL* ps)
{
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

//销毁栈
void StackDeatroy(SL* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

//入栈
void StackPush(SL* ps, DataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        DataType* tem = (DataType*)realloc(ps->a, sizeof(DataType) * newcapacity);
        if (tem == NULL)
        {
            exit(0);
        }
        ps->a = tem;
        ps->capacity = newcapacity;

    }
    ps->a[ps->top] = x;
    ps->top++;
}

//出栈
void StackPop(SL* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

//从栈顶取出元素
DataType StackTop(SL* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];

}

//计算栈的大小
int StackSize(SL* ps)
{
    assert(ps);
    return ps->top;
}

//判定栈是否为空
bool StackEmpty(SL* ps)
{
    assert(ps);
    return (ps->top == 0);
}

typedef struct {
    SL s1;
    SL s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->s1);
    StackInit(&q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->s1, x);

}

int myQueuePop(MyQueue* obj) {
    if (StackEmpty(&obj->s2))
    {
        while (!StackEmpty(&obj->s1));
        {
            StackPush(&obj->s2, StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
    }

    int top = StackTop(&obj->s2);
    StackPop(&obj->s2);
    return top;

}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->s2))
    {
        while (!StackEmpty(&obj->s1));
        {
            StackPush(&obj->s2, StackTop(&obj->s1));
            StackPop(&obj->s1);
        }
    }

    return StackTop(&obj->s2);

}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    StackDeatroy(&obj->s1);
    StackDeatroy(&obj->s2);
    free(obj);
}