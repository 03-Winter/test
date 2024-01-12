#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct TreeNode;
typedef TreeNode* Datatype;


typedef struct Queuelist
{
	Queuelist* next;
	Datatype data;
}ql;

typedef struct Queue
{
	Queuelist* head;
	Queuelist* tail;
}qu;

//ǧ��Ҫ��Ϊ���˽��� �Լ�������� �����Լ�������������һ�Ų�һ�������� ȥ�ջ�һ���Ĺ�ʵ

void QueueInit(qu* pq);
void QueueDestroy(qu* pq);
void QueuePush(qu* pq, Datatype x);
void QueuePop(qu* pq);
Datatype QueueFront(qu* pq);
Datatype QueueBack(qu* pq);
int QueueSize(qu* pq);
bool QueueEmpty(qu* pq);



