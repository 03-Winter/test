#define _CRT_SECURE_NO_WARNINGS  1
#include"Queue.h"


void QueueInit(qu* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestroy(qu* pq)
{
	assert(pq);
	ql* cur = pq->head;
	while (cur != NULL)
	{
		ql* newnode = cur->next;
		free(cur);
		cur = newnode;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(qu* pq, Datatype x)
{
	assert(pq);
	ql* newnode = (ql*)malloc(sizeof(ql));
	newnode->data = x;
	newnode->next=NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(qu* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	ql* newhead = pq->head->next;
	free(pq->head);
	pq->head = newhead;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = NULL;
	}

}
Datatype QueueFront(qu* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
Datatype QueueBack(qu* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(qu* pq)
{
	assert(pq);
	int count =0;
	ql* cur = pq->head;

	while (cur)
	{
		++count;
		cur = cur->next;
	} 
	return count;
}
bool QueueEmpty(qu* pq)
{
	assert(pq);
	return (pq->head == NULL) && (pq->tail == NULL);
}








