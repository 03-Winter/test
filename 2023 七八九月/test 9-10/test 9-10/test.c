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

//��̬�ڴ濪�ٳ����Ĵ���

//   1.��NULLָ��Ľ����ò���


//int main()
//{
//	int* p = (int*)malloc(10000);
//
//	//û�ж�malloc�ķ���ֵ���ж�
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	return 0;
//}

//  2.�Զ�̬���ٵ�Խ�����

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
//		//Խ�����
//	}
//	return 0;
//}


//  3��ʹ��free�ͷŷǶ�̬���ٵĿռ�
//
//int main()
//{
//	int arr[] = { 0 };
//	int* p = arr;//ʹ��free�Ƿ�����
//	free(p);
//	p = NULL;
//	return 0;
//}

//  4.ʹ��free�ͷŶ�̬�ڴ��һ����

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

//  5,��ͬһ�鶯̬���ٵĿռ����ͷ�

//  6����̬���ٵĿռ������ͷ� �ڴ�й¶����




//��������
//������str����GetMemory������ʱ����ֵ���ݣ�����Get Memory�������β�p��str��һ����ʱ������
//��Get memory�����ڲ���̬����ռ�ĵ�ַ�������p�У�����Ӱ���ⲿ��str�����Ե�Get memory�����Ż�֮��
//str��Ȼ��NULL������strcpy��ʧ�ܡ�
//��getmemory��������֮ǰ���β�p���٣�ʹ�ö�̬���ٵ�100���ֽڴ����ڴ�й©
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


//�ⷨһ��
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

//�ⷨ����

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


//��������


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