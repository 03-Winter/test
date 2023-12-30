#pragma once

#define N 100

typedef int DataType;


//��̬˳���
//typedef struct SeqList
//{
//	DataType a[N];
//	int size;
//}SL;

//��̬˳���
typedef struct SeqList
{
	DataType* a;
	int size;//��ʾ�����д洢�˶�������
	int capacity;//����ʵ�ʿռ�����
}SL;

//�ӿں���
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
