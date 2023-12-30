#define _CRT_SECURE_NO_WARNINGS  1
#include "head.h"


void  TestList1()
 {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	Listprint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	Listprint(&sl);

	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 20);
	Listprint(&sl);



	ListDestroy(&sl);
	

}    


void  TestList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	Listprint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	Listprint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	Listprint(&sl);

	SeqListinsert(&sl, 2, 33);
	Listprint(&sl);

	ListDestroy(&sl);

}

void  TestList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	Listprint(&sl);

	SeqListErase(&sl, 3);
	Listprint(&sl);

}

int main()
{
	//TestList1();
	//TestList2();
	TestList3();

	return 0;
}