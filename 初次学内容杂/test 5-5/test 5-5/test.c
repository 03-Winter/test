#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<string.h>




//void reverse(char* p, int n)
//{
//	char *left = p;
//	char *right = p + n - 1;
//	while (left < right)
//	{
//		char tem = *left;
//		*left = *right;
//		*right = tem;
//		right--;
//		left++;
//	}
//
//
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	reverse(arr, sz);
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	for (int i = 0; i < line; i++)
//	{
//		for (int j = 0; j < line-i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 0; k <= i; k++) 
//		{
//			printf(" *");
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < line; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf(" ");
//
//		}
//		for (int k = 0; k <=line - i - 1; k++)
//		{
//			printf(" *");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int arr[100][100] = { 0 };
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (j == i)
//				arr[i][j] = 1;
//			if ( j >=1 && i >= 2)
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	char w = 'A';
//	for (int q = 'A'; q <= 'D'; q++) {
//		if (((q != 'A') + (q == 'C') + (q == 'D') + (q != 'D')) == 3)
//			printf("%c", q);
//	}
//	return 0;
//}

//
//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b<= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5;e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1)
//							)
//							if(a*b*c*d*e==120)
//							printf("%d %d %d %d %d\n", a, b, c, d, e);
//
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}