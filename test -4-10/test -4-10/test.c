#define _CRT_SECURE_NO_WARNINGS  1

#include<assert.h>
#include <stdio.h>
#include <string.h>


//      ��������
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}


//    �ݹ鷨
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str != '\0')
//	{
//		//return 1 + my_strlen(str + 1);
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//
//
//
//int main()
//{
//	char arr[10] = "abcdef";
//	//int s = strlen(arr);
//	int len = my_strlen(arr);
//	//printf("%d\n",s);
//	printf("%d\n", len);
//
//	return 0;
//}

//�������һ�ĸ���
//int Number_of_1(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		if (n % 2 == 1)								//		ȱ��ֻ��������
//			count++;
//		n /= 2;
//	}
//	return count;
//}


//
//int Number_of_1(int n)
//{
//	int count = 0;
//	
//	for(int i=1;i<=32;i++)
//	{
//		if (n&1)
//			count++;
//		n=n >> i;			//����������ǰ��iλ
//	}
//	return count;
//}


//int Number_of_1(int n)
//{
//	int count = 0;
//	while(n)
//	{
//		n = n & (n - 1);
//			count++;
//		��nΪ10ʱ����λ��Ϊ00001010
//		n-1Ϊ00001001
//		n��n-1�����Ϊ00001000���¸�ֵΪn����ʱcount��һ
//		n-1Ϊ00000111�������00000000����ʱnΪ�㣬�˳�ѭ��
//	}
//	return count;
//}
//
//int main()
//{
//	int n =15;//0000000  00000000 00000000 00001010
//	int ret = Number_of_1(n);
//	printf("%d", ret);
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	//�ж�һ�����Ƿ�Ϊ2��n�η�
//	n = n & (n - 1);
//	if (n==0)
//		printf("Yes");
//	else printf("NO");
//		//����������ֻ��һλһ
//	return 0;
//}