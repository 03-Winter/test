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

//千万不要因为别人交卷 自己胡乱填答案 克制自己的欲望，种下一颗不一样的种子 去收获不一样的果实

void QueueInit(qu* pq);
void QueueDestroy(qu* pq);
void QueuePush(qu* pq, Datatype x);
void QueuePop(qu* pq);
Datatype QueueFront(qu* pq);
Datatype QueueBack(qu* pq);
int QueueSize(qu* pq);
bool QueueEmpty(qu* pq);



