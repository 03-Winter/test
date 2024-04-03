#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<time.h>

#include<stdlib.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tem = a[end + 1];
		while (end >= 0)
		{
			if (tem < a[end])
			{
				a[end+1] = a[end];
				--end;
			}
			else break;
		}
		a[end+1] = tem;
	}
}


//交换
void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}


//对于有序的数组，快排存在缺陷
//采取三数取中方法
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[mid] < a[left])
	{
		if (a[mid] < a[right])
		{
			if (a[left] > a[right])
				return right;
			else return left;
		}
		else
		{
			return mid;
		}
	}
	else if (a[mid] > a[left])
	{
		if (a[mid] > a[right])
		{
			if (a[left] > a[right]) return left;
			else return right;
		}
		else return mid;
	}
}

//挖坑法
int PartSort(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[index], &a[left]);
	//int pivot = PartSort(a, left, right);
	int begin = left, end = right;
	int pivot = begin;//GetMidIndex(a, left, right);
	int key = a[pivot];
	//大的在右边end，小的在左边begin

	while (begin < end)
	{
		while (begin < end && a[end] >= key)	--end;
		a[pivot] = a[end];
		pivot = end;

		while (begin < end && a[begin] <= key)	++begin;
		a[pivot] = a[begin];
		pivot = begin;
	}
	a[begin] = key;


	return pivot;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = PartSort(a, left, right);
	//递归调用
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);


	//进行递归优化
	//if (pivot - 1 - left > 11)
	//{
	//	QuickSort(a, left, pivot - 1);
	//}
	//else
	//{
	//	InsertSort(a + left, pivot - 1 - left + 1);
	//}
	//if (right - pivot + 1 > 11)
	//{
	//	QuickSort(a, pivot + 1, right);
	//}
	//else {
	//	InsertSort(a + pivot + 1, right - (pivot + 1) + 1);
	//}
}



void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void test()
{
	int a[] = {6,5,5,4,3,9,8,7,2,-1,0 };
	int size = sizeof(a) / sizeof(int);
	QuickSort(a, 0, size-1);
	//InsertSort(a, size);
	print(a, size);
}


// 测试排序的性能对比

int main()
{
	test();
	//TestOP();

	return 0;
}