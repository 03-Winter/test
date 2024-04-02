#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<time.h>

#include<stdlib.h>

void Swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;

}


//向下调整算法：前提左右两边必须大堆或小堆
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n && a[child] < a[child + 1])
			child += 1;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//推排序
void HeapSort(int* a, int n)
{
	//调整为符合向下调整算法
	for (int i = (n - 2) / 2; i >=0; --i)	AdjustDown(a, n, i);

	//且堆排序必须使用大堆

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
		{
			if (a[j-1] > a[j])
			{
				//法一：此交换可以节省执行时间
				int tem = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tem;

				//法二:异或跟方法一样会增加使用时间
				//a[j - 1] = a[j - 1] ^ a[j];
				//a[j] = a[j - 1] ^ a[j];
				//a[j - 1] = a[j - 1] ^ a[j];

				//使用方法会增加执行时间
				//Swap(&a[j - 1], &a[j]);
			}
		}
	}
}


//直接排序，与冒泡排序相比，其适应性更强
//复杂度比冒泡排序也低

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = end;
		for (int i = begin; i <= end; ++i)
		{
			if (a[mini] > a[i])	mini = i;
			if (a[maxi] < a[i])	maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)	maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
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
	int a[] = { 9,8,7,6,5,5,4,3,2,-1,0 };
	int size = sizeof(a) / sizeof(int);
	BubbleSort(a, size);
	//SelectSort(a, size);
	//HeapSort(a, size);
	print(a, size);
}


// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];

	}
	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();
	//int begin2 = clock();
	//ShellSort(a2, N);
	//int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin7 = clock();
	BubbleSort(a7, N);
	int end7 = clock();
	//int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	//int end5 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();
	//printf("InsertSort:%d\n", end1 - begin1);
	//printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSortSort:%d\n", end7 - begin7);
	//printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}
int main()
{
	test();
	TestOP();

	return 0;
}