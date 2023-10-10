#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
#define N 200
//int num[N], prim[N];
//int pn = 0;
//int dp[N];


//void table()
//{
//    memset(num, -1, sizeof(num));
//    for (int i = 2; i <= N; i++)
//    {
//        if (num[i]) prim[pn++] = i;
//        for (int j = 0; j < pn && i * prim[j] <= N; j++)
//        {
//            num[i * prim[j]] = 0;
//            if (num[i])
//                dp[i * prim[j]] = 1;
//            if (i % prim[j] == 0)
//                break;
//        }
//    }
//}
//
//
//
//int  main()
//{
//    //printf(num);
//    table();
//    //      for(int i=0;i<pn;i++)
//    //     {
//    //         for(int j=0;j<i;j++)
//    //         {
//    //             dp[prim[i]*prim[j]]=1;
//    //         }
//    //     }
//    for (int i = 1; i <= N; i++)
//    {
//        dp[i] += dp[i - 1];
//        //printf("%d ", dp[i]);
//    }
//
//         int t;
//         scanf("%d",&t);
//         while(t--)
//         {
//             int l,r;
//             scanf("%d %d",&l,&r);
//             printf("%d %d",dp[r-1],dp[l-1]);
//         }
//    return 0;
//
//}

//动态内存开辟常见的错误

//   1.对NULL指针的解引用操作


//int main()
//{
//	int* p = (int*)malloc(10000);
//
//	//没有对malloc的返回值做判断
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	return 0;
//}

//  2.对动态开辟的越界访问

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return;
//
//	}
//	for (int i = 0; i < 40; i++)
//	{
//		*(p + i) = i;
//		//越界访问
//	}
//	return 0;
//}


//  3。使用free释放非动态开辟的空间
//
//int main()
//{
//	int arr[] = { 0 };
//	int* p = arr;//使用free非法访问
//	free(p);
//	p = NULL;
//	return 0;
//}

//  4.使用free释放动态内存的一部分

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("error");
//		return;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		*p++ = i;
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//  5,对同一块动态开辟的空间多次释放

//  6。动态开辟的空间忘记释放 内存泄露严重




//错误例题
//解析：str传给GetMemory函数的时候是值传递，所以Get Memory函数的形参p是str的一份临时拷贝，
//在Get memory函数内部动态申请空间的地址，存放在p中，不会影响外部的str，所以当Get memory函数放回之后
//str依然是NULL，所以strcpy会失败。
//当getmemory函数返回之前，形参p销毁，使得动态开辟的100个字节存在内存泄漏
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//
//	strcpy(str, "hello world!");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//解法一：
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//
//	strcpy(str, "hello world!");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//解法二：

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//
//void Test()
//{
//	char* str = NULL;
//	str = GetMemory(str);
//
//	strcpy(str, "hello world!");
//	printf(str);
// free(str);
// str =NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//柔性数组


struct s
{
	int n;
	int arr[0];
};

int main()
{
	struct s* pc = (int*)malloc(sizeof(struct s) + 10 * sizeof(int));
	pc->n = 10;
	for (int i = 0; i < 10; i++)
	{
		pc->arr[i] = i;
	}

	struct s* ptr = (int*)realloc(pc, sizeof(struct s) + 20 * sizeof(int));
	if (ptr != NULL)
	{
		pc = ptr;
	}
	free(pc);
	pc = NULL;
	return 0;
}