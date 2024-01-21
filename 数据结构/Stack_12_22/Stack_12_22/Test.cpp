#define _CRT_SECURE_NO_WARNINGS  1

#include"Stack.h"

void Stacxktext1()
{
	SL Z;
	StackInit(&Z);

	StackPush(&Z, 1);
	StackPush(&Z, 2);
	StackPush(&Z, 3);
	StackPush(&Z, 4);

	StackPop(&Z);
	StackPop(&Z);
	StackPop(&Z);
	printf("%d", StackTop(&Z));

	StackDeatroy(&Z);
}

void Stacxktext2()
{
	SL Z;
	StackInit(&Z);

	StackPush(&Z, 1);
	StackPush(&Z, 2);
	StackPush(&Z, 3);
	StackPush(&Z, 4);



}

int main()
{
	Stacxktext1();
	Stacxktext2();


	return 0;
}




