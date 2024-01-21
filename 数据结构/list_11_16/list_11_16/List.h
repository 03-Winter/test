#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;


typedef struct Slist
{
	DataType data;
	struct Slist* next;
}ListNode;



void Listprint(ListNode* phead);
void ListPushback(ListNode** phead,DataType x);
void ListPushFront(ListNode** phead, DataType x);
void ListPopback(ListNode** phead);
void ListPopFront(ListNode** phead);
ListNode* ListFind(ListNode* phead, DataType x);

void ListInsert(ListNode** phead, int pos, DataType x);
void ListErase(ListNode** phead, DataType pos);
void ListDestroy(ListNode** phead);







