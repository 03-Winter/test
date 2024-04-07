#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}




int GetMidIndex(int* a, int left, int right)
{
	if (right - left + 1 < 3) {
		// 处理数组元素不足3个的情况
		// 可以返回left、right、mid中的任意一个，或者根据实际情况做其他处理
		return left;
	}

	//int mid = (left + right) >> 1;
	int mid = (left + right)/2;
	if (a[left] > a[mid])
	{
		if (a[mid] < a[right])
			if (a[right] < a[left])    return right;
			else return left;
		else return mid;
	}
	else if (a[left] < a[mid])
	{
		if (a[mid] > a[right])
			if (a[left] > a[right]) return left;
			else return right;
		else return mid;
	}
}
int PartSort(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

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


//前后指针法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int begin = left, end = right;
	int key = begin;
	while (begin < end)
	{
		while (begin < end && a[key] <= a[end])	--end;

		while (begin < end && a[key] >= a[begin])	++begin;

		Swap(&a[begin], &a[end]);

		return begin;
	}
}

//抽象法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = left, pre = left, cur = left + 1;
	while (cur <= right)
	{
		while (a[cur] < a[key] && ++pre != cur)
		{
			Swap(&a[cur], &a[pre]);
		}
		++cur;
	}
	Swap(&a[key], &a[pre]);

	return pre;
}



void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	int pivot = PartSort3(a, left, right);
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);

}

int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	int size = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}