#pragma once

#define N 100

typedef int DataType;


//静态顺序表
//typedef struct SeqList
//{
//	DataType a[N];
//	int size;
//}SL;

//动态顺序表
typedef struct SeqList
{
	DataType* a;
	int size;//表示数组中存储了多少数据
	int capacity;//数组实际空间容量
}SL;

//接口函数
void Listprint(SL* ps);
void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps,DataType x);
void ListDestroy(SL* ps);
void CheckCapacity(SL* ps);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, DataType x);
void SeqListPopFront(SL* ps);
void SeqListfind(SL* ps, DataType x);
void SeqListinsert(SL* ps,int pos, DataType x);
void SeqListErase(SL* ps, int pos);
