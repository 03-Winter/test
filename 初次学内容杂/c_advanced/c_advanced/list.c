#define _CRT_SECURE_NO_WARNINGS  1
#include"head.h"
#include<stdio.h>
#include<assert.h>


//初始化列表
void SeqListInit(SL* ps)
{
	ps->a = 0;
	ps->size = ps->capacity = 0;

}


//是否扩容
void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		DataType* tem = (DataType*)realloc(ps->a, newcapacity * sizeof(DataType));
		if (tem == NULL)
		{
			exit(-1);
		}
		ps->a = tem;
		ps->capacity = newcapacity;
	}

}

//列表打印
void Listprint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);

	}
	printf("\n");
}

//向后放元素
void SeqListPushBack(SL* ps, DataType x)
{
	CheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
	//版本二
	//SeqListinsert(ps, ps->size, x);
}

//释放表
void ListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//向后删除
void SeqListPopBack(SL* ps)
{
	if (ps->size > 0)
	{
		ps->a[ps->size - 1] = 0;
		ps->size--;
	}

	//版本二
	//SeqListErase(ps, ps->size-1);
}

//向前放元素
void SeqListPushFront(SL* ps,DataType x)
{
	CheckCapacity(ps);
	//防止溢出
	int end = ps->size - 1;
	//整体后移
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;

	//版本二
	//SeqListinsert(ps, ps->size, x);

}

//向前删除
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int begin = 1;
	//覆盖前面的值，实现删除方法
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;

	//版本二
	//SeqListErase(ps, 0);
}

void SeqListfind(SL* ps, DataType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListinsert(SL* ps, int pos, DataType x)
{
	CheckCapacity(ps);
	assert(pos <= ps->size && pos >= 0);
	for (int i = ps->size; i >pos; --i)
	{
		ps->a[i] = ps->a[i - 1];

	}
	ps->a[pos] = x;
	ps->size++;
}


void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos <= ps->size);
	int begin = pos;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}
	ps->size--;
}












