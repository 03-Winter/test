#define _CRT_SECURE_NO_WARNINGS  1
#include"droublelist.h"

void test1()
{
	dlist* phead = Listinit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	listprint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	listprint(phead);

	ListPushfront(phead, 4);
	ListPushfront(phead, 3);
	ListPushfront(phead, 2);
	listprint(phead);

	dlist* pos=ListFind(phead, 1);
	if (pos)
	{
		ListErase(pos);
	}
	listprint(phead);

	ListDestroy(phead);
	phead = NULL;
}
int main()
{
	test1();
	return 0;
}