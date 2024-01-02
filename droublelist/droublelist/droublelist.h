#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListType;

typedef struct droublelist
{
	ListType data;
	struct droublelist* pre;
	struct droublelist* next;
}dlist;


dlist* Listinit();
void listprint(dlist* head);
void ListPushBack(dlist* head, ListType x);
void ListPopBack(dlist* head);
void ListPushfront(dlist* head, ListType x);
void ListPopfront(dlist* head);

dlist* ListFind(dlist* head, ListType x);
void ListInsert(dlist* pos, ListType x);
void ListErase(dlist* pos);
void ListDestroy(dlist* head);



