#define _CRT_SECURE_NO_WARNINGS  1

#include<assert.h>
#include <stdio.h>
#include <string.h>


//      计数器法
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


//    递归法
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

//求二进制一的个数
//int Number_of_1(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		if (n % 2 == 1)								//		缺点只能求正数
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
//		n=n >> i;			//二进制数向前移i位
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
//		当n为10时，二位制为00001010
//		n-1为00001001
//		n与n-1相与变为00001000重新赋值为n，此时count加一
//		n-1为00000111，相与得00000000，此时n为零，退出循环
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
//	//判断一个数是否为2的n次方
//	n = n & (n - 1);
//	if (n==0)
//		printf("Yes");
//	else printf("NO");
//		//即二进制中只有一位一
//	return 0;
//}