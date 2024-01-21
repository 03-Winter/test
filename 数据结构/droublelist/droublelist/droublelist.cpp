#define _CRT_SECURE_NO_WARNINGS  1
#include"droublelist.h"

dlist* Listinit()
{
	dlist* head = (dlist*)malloc(sizeof(dlist));
	head->pre = head;
	head->next = head;
	return head;
}
void listprint(dlist* head)
{
	assert(head);
	dlist* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//申请一个节点
dlist* Buylistnode(ListType x)
{
	dlist* newnode = (dlist*)malloc(sizeof(dlist));
	newnode->data = x;
	newnode->pre = NULL;
	newnode->next = NULL;
	return newnode;
}


void ListPushBack(dlist* head, ListType x)
{
	assert(head);
	dlist* tail = head->pre;

	dlist* newnode = Buylistnode(x);

	tail->next = newnode;
	newnode->pre = tail;
	head->pre = newnode;
	newnode->next = head;

}

//void ListPopBack(dlist* head)
//{
//	assert(head);
//	//链表为空，不能删除了
//	assert(head->next!=head);
//
//	dlist* tail = head->pre;
//	dlist* tailpre = tail->pre;
//	free(tail);
//
//	tailpre->next = head;
//	head->pre = tailpre;
//
//}

void ListPopBack(dlist* head)
{
	assert(head);
	assert(head->next != head);

	dlist* tail = head->pre;

	head->pre = tail->pre;
	tail->pre->next = head;

	free(tail);
}


void ListPushfront(dlist* head, ListType x)
{
	assert(head);

	dlist* newnode = Buylistnode(x);
	dlist* nextone = head->next;

	head->next = newnode;
	newnode->pre = head;

	newnode->next = nextone;
	nextone->pre = newnode;
}

void ListPopfront(dlist* head)
{
	assert(head);
	assert(head->next != NULL);
	dlist* next = head->next;
	dlist* nextNext = next->next;

	head->next = nextNext;
	nextNext->pre = head;

}


dlist* ListFind(dlist* head, ListType x)
{
	assert(head);
	dlist* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(dlist* pos, ListType x)
{
	assert(pos);
	dlist* pospre = pos->pre;
	dlist* newnode = Buylistnode(x);

	pospre->next = newnode;
	newnode->pre = pospre;
	newnode->next = pos;
	pos->pre = newnode;

}
void ListErase(dlist* pos)
{
	assert(pos);
	dlist* pospre = pos->pre;
	dlist* posnext = pos->next;

	pospre->next = posnext;
	posnext->pre = pospre;
	free(pos);
	pos = NULL;
}

void ListDestroy(dlist* head)
{
	assert(head);
	dlist* cur = head->next;
	while (cur != head)
	{
		dlist* next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	head = NULL;
}



