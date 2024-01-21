#define _CRT_SECURE_NO_WARNINGS  1
#include"Stack.h"

//初始化
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
	    DataType* tem = (DataType*)realloc(ps->a, sizeof(DataType)*newcapacity);
		if (tem == NULL)
		{
			exit(-1);
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
	assert(ps->top > 0);
	ps->top--;
}

//从栈顶取出元素
DataType StackTop(SL* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));
	//printf("%d ", ps->a[ps->top]);
	//ps->top--;
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
