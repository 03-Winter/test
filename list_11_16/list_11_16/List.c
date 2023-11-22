#define _CRT_SECURE_NO_WARNINGS  1
#include"List.h"
#include<stdio.h>

ListNode* buymolloc(DataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}



void Listprint(ListNode* phead)
{
	ListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}



void ListPushback(ListNode** phead, DataType x)
{
	ListNode* newnode = buymolloc(x);

	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else
	{
		ListNode* tail = *phead;

		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


void ListPushFront(ListNode** phead, DataType x)
{
	ListNode* newnode1 = buymolloc(x);
	newnode1->next = *phead;
	*phead = newnode1;
}


void ListPopback(ListNode** phead)
{
	//版本一

	//温柔版
	//if (*phead == NULL)
	//{
	//	return;
	//}

	//暴力版
	assert(*phead);

	//程序头为空
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead= NULL;
	}
	else
	{
		ListNode* prev = NULL;
		ListNode* tail = *phead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
	//版本二
	//ListNode* tail=*phead;
	//while (tail->next->next)
	//{
	//	tail = tail->next;
	//}
	//free(tail->next);
	//tail->next = NULL;
}

void ListPopFront(ListNode** phead)
{

	assert(*phead);
	ListNode* next = (*phead)->next;
	free(*phead);
	*phead = next;

}



ListNode* ListFind(ListNode* phead,DataType x)
{
	//assert(phead);
	ListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void ListInsert(ListNode** phead, ListNode* pos,DataType x)
{
	ListNode* newnode = buymolloc(x);
	if (*phead != pos)
	{
		ListNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
	else
	{
		newnode->next = *phead;
		*phead = newnode;
	}
}
void ListErase(ListNode** phead, DataType pos);
void ListDestroy(ListNode** phead);
