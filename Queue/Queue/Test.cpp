#define _CRT_SECURE_NO_WARNINGS  1
#include"Queue.h"
void queuetast()
{
	qu sl;
	QueueInit(&sl);
	QueuePush(&sl,1);
	QueuePush(&sl,2);
	QueuePush(&sl,3);
	QueuePush(&sl,4);
	QueuePush(&sl,5);
	QueuePop(&sl);
	QueuePop(&sl);
	QueuePop(&sl);
	QueuePop(&sl);

	QueueDestroy(&sl);

}


void queuetest()
{
	qu sl;
	QueueInit(&sl);
	QueuePush(&sl, 1);
	QueuePush(&sl, 2);
	QueuePush(&sl, 3);
	QueuePush(&sl, 4);
	QueuePush(&sl, 5);
	while (!QueueEmpty(&sl))
	{
		Datatype front = QueueFront(&sl);
		printf("%d ", front);
		QueuePop(&sl);
	}
	printf("\n");

	QueueDestroy(&sl);
}


int main()
{
	//queuetast();
	queuetest();

	return 0;
}
















