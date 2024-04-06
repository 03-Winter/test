#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

int PartSort(int* a, int left, int right)
{
	//int mid = GetMidIndex(a, left, right);
	//Swap(&a[left], &a[mid]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[pivot];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;
		a[pivot] = a[end];
		pivot = end;

		while (begin < end && a[begin] <= key)
			++begin;
		a[pivot] = a[begin];
		pivot = begin;

	}
	a[begin] = key;
	return pivot;
}

void QuickSortNonR(int* a, int n)
{
	SL s;
	StackInit(&s);
	StackPush(&s, n - 1);
	StackPush(&s, 0);

	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);
		StackPop(&s);

		int right = StackTop(&s);
		StackPop(&s);
		 
		int mid = PartSort(a, left, right);
		if (mid + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, mid + 1);
		}
		if (left < mid - 1)
		{
			StackPush(&s, mid - 1);
			StackPush(&s, left);
		}
	}
	StackDeatroy(&s);

}


void _mergesort(int* a, int left, int right, int* tem)
{
	if (left >= right)	return;
	
	//if (right - left < 3) mid = left;

	int mid = (left + right) >> 1;
	//使用后续遍历
	_mergesort(a, left, mid, tem);
	_mergesort(a, mid+1,right,tem);

	//归并

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tem[index++] = a[begin1++];
		}
		else
		{
			tem[index++] = a[begin2++];
		}

	}

	while (begin1 <= end1)
	{
		tem[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tem[index++] = a[begin2++];
	}
	for (int i = left; i <= right; ++i)
	{
		a[i] = tem[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tem = (int*)malloc(sizeof(int) * n);
	_mergesort(a, 0, n - 1, tem);

	free(tem);
}


void MergeSortNonR(int* a, int n)
{
	int* tem = (int*)malloc(sizeof(int) * n);

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap )
		{
			int begin1 = i, end1 = i + gap-1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;

			int index = i; 
			while (begin1 <= end1 && begin2 <= end2)
			{
				if(a[begin1] < a[begin2])
				{
					tem[index++] = a[begin1++];
				}
				else
				{
					tem[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tem[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tem[index++] = a[begin2++];
			}
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tem[j];
			}
		}
		gap *= 2;
	}
	free(tem);
}

int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,2,1 };
	int size = sizeof(a) / sizeof(a[0]);

	//QuickSortNonR(a, size);
	//MergeSort(a, size);
	MergeSortNonR(a, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}