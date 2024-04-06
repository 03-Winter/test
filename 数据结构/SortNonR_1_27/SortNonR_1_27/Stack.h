#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Stack {
	DataType* a;
	int top;
	int capacity;

}SL;

void StackInit(SL* ps);
void StackDeatroy(SL* ps);
void StackPush(SL* ps, DataType x);
void StackPop(SL* ps);
DataType StackTop(SL* ps);
int StackSize(SL* ps);
bool StackEmpty(SL* ps);




