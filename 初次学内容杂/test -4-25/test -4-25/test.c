#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<math.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*pa + i));
//
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][5] = { {2,3,45,6,8},{4,5,26,7,8},{6,7,18,9,10 } };
//	int(*pa)[5] = &arr;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(*pa + i) + j);
//			printf("%d ", *(*(pa + i) + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	int* pen = arr + sz - 1;
//	for (int i = 0; i < sz; i++)
//
//	{
//		printf("%d ", *(p + i));
//	}
//	/*for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	return 0;
//}

//
//int main()
//{
//	int i = 0;
//	int num = 0;
//	//scanf("%d", &num);
//	for (i = 1; i <= 10000; i++)
//	{
//		num = i;
//		int n = 1;
//		while (num / 10)
//		{
//			n++;
//			num /= 10;
//		}
//		int tem = i;
//		int sum = 0;
//		while (tem )
//		{
//			sum += pow(tem % 10, n);
//			tem /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//
//struct stu
//{
//	int num; 
//	char name[10];
//	int age;
//};
//void fun(struct stu* p)
//{
//	printf("%s \n", (*p).name);
//	return;
//}
//
//
//int main()
//{
//	struct stu student[3] = { {12,"zhong",45},{23,"liu",23},{17,"zhao",18} };
//	fun(student + 1);
//	return 0;
//}


int main()
{

	return 0;
}