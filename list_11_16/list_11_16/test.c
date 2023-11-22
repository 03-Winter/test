#define _CRT_SECURE_NO_WARNINGS  1
#include"List.h"

void text1()
{
	ListNode* plist = NULL;
	ListPushback(&plist, 1);
	ListPushback(&plist, 2);
	ListPushback(&plist, 3);
	ListPushback(&plist, 4);
	ListPushback(&plist, 5);
	Listprint(plist);


	//ListPushFront(&plist, 1);
	//ListPushFront(&plist, 2);
	//ListPushFront(&plist, 3);
	//ListPushFront(&plist, 4);
	//ListPushFront(&plist, 5);
	//Listprint(plist);

	ListPopback(&plist);
	ListPopback(&plist);
	ListPopback(&plist);
	ListPopback(&plist);
	ListPopback(&plist);
	ListPopback(&plist);
	Listprint(plist);
}


void text2()
{
	ListNode* plist = NULL;
	ListPushback(&plist, 1);
	ListPushback(&plist, 2);
	ListPushback(&plist, 3);
	ListPushback(&plist, 4);
	ListPushback(&plist, 3);
	Listprint(plist);

	ListNode* pos = ListFind(plist, 3);
	int i = 1;
	while (pos)
	{
		printf("第%d个%d节点是：%d", i++, pos, pos->data);
		pos = ListFind(pos->next, 3);
	}
}
int main()
{
	//text1();
	text2();
	return 0;
}

