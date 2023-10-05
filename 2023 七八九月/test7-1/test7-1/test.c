#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//struct stu {
//	char name[12];
//	int age;
//};
//int sort(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int sort_age(const void* q, const void* w)
//{
//	return (((struct stu*)q)->age - ((struct stu*)w)->age);
//}
//void test1()
//{
//	struct stu s[3] = { {"张三",18},{"刘华",43},{"小花",12} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), sort_age);
//	printf("%s", s);
//}
//void swap(char* a, char* b, int width)
//{
//	for (int i = 0; i < width; i++)
//	{
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//		a++;
//		b++;
//	}
//}
//void bulle(void* base, int sz, int width, int (*cmp)(const void* q, const void* w))
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width ,(char*)base + (j + 1) * width)>0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//
//
//int main()
//{
//	int srr[] = { 2, 3, 4, 4, 2, 8, 6, 31, 4, 7 };
//	//test1();
//	int sz = sizeof(srr) / sizeof(srr[0]);
//
//	bulle(srr, sz, sizeof(srr[0]), sort);
//	//test1();
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", srr[i]);
//	}
//	return  0;
//
//}



//查找七    方法一遍历
//方法二 
//int num(int arr[3][3], int a, int b, int k)
//{
//	int x = 0; int y = b - 1;
//	while (x < a && y >= 0)
//	{
//		if (arr[x][y] < k)
//			x++;
//		else if (arr[x][y] > k)
//			y--;
//		else
//			return 1;
//		
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9};
//
//	int k = 4;
//	int ret = num(arr, 3, 3, k);
//	if (ret)
//		printf("2");
//	else
//		printf("1");
//
//	/*for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//			if (arr[i][j] == 7)
//				printf("zhoadaol");
//	}*/
//	return 0;
//}


//&x &y
//传入参数
//带回值

//字符左旋

//方法一：整体迁移
//void fan(char *arr, int k)
//{
//	int n = strlen(arr);
//	for (int j = 0; j < k; j++)
//	{
//		char temp = *arr;
//		for (int i = 0; i < n-1; i++)
//		{
//			*(arr + i) = *(arr + i + 1);
//		}
//		*(arr + n-1) = temp;
//	}
//}
//
////方法二：字符翻转
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++; right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "ABCDEF";
//	int k = 2;
//	//fan(arr, k);
//	int n = strlen(arr);
//	reverse(arr, arr + k - 1);
//	reverse(arr+k, arr +n - 1);
//	reverse(arr, arr + n - 1);
//	printf("%s\n", arr);
//	return 0;
//}


//判断一个字符串是否是左旋得到的
//
//int pan(char* crr, char* brr)
//{
//	char* ret = strstr(crr, brr);
//	return ret != NULL;
//}
//int main()
//{
//	
//	char arr[] = "aabcd";
//	char brr[] = "bcdaa";
//	int len = strlen(arr);
//	strncat(arr, arr, len);
//	int ret=pan(arr, brr);
//	if (ret)
//		printf("YES");
//	else
//		printf("No");
//	return 0;
//
//}
