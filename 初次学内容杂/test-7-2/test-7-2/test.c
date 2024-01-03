#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <string.h>

//void my_strcat(char* dest, char* sour)
//{
//	while (*dest != '\0')
//		dest++;
//	while(*dest++  = *sour++ )
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[23] = "hello ";
//	char arr2[12] = "world";
//	//my_strcat(arr1, arr2);
//	strncat(arr1, arr2, 3);
//	printf("%s", arr1);
//
//	return 0;
//}
//int my_strcmp(char* dest, char* sour)
//{
//	while (*dest == *sour)
//	{
//		if (*dest == '\0')
//		{
//			return 0;
//		}
//		dest++; sour++;
//	}
//	if (*dest > *sour)
//		return 1;
//	else
//		return -1;
//}


//优化代码
//int you(char* dest, char* sour)
//{
//	int ret = 0;
//	while ((ret = *(unsigned char*)dest - *(unsigned char*)sour) == 0 && *dest)
//	{
//		dest++;
//		sour++;
//	}
//	return ((-ret < 0) - (ret < 0));
//}


//strncat函数的原理
// 
// 
//char* fu(char* front,const char* back, int count)
//{
//	char *start = front;
//	while (*front++)
//		;
//	front--;
//	while (count--)
//	{
//		if ((*front++ = *back++) == 0)
//			return start;
//		
//	}
//	*front = '\0';
//	return start;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "aabcfd";
//	//int ret = my_strcmp(arr1, arr2);
//	//int ret = you(arr1, arr2);
//	char *ret = fu(arr1,arr1, 6);
//	printf("%s", ret);
//	return 0;
//}
#include<assert.h>
//char* cmp(const char* dst, const char* scr)
//{
//	assert(dst && scr);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* p = dst;
//	while (*p)
//	{
//		s1 = p;
//		s2 = scr;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++; s2++;
//		}
//		if (*s2 == '\0')
//			return p;
//		p++;
//
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "def";
//	//int ret = my_strcmp(arr1, arr2);
//	//int ret = you(arr1, arr2);
//	//char* ret = fu(arr1, arr1, 6);
//	char* ret = cmp(arr1, arr2);
//	printf("%s", ret);
//	return 0;
//}

//分隔符strtok的使用

//int main()
//{
//
//	char arr[] = "a;42@dn$ns";
//	char* p = "@$";
//	char temp[30] = { 0 };
//	strcpy(temp, arr);
//	char *ret = NULL;
//	for (ret = strtok(temp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//
//	}
//	return 0;
//}

#include<ctype.h>

//将大写转化成小写
//int main()
//{
//	char arr[20] = { 0 };
//	scanf("%s", &arr);
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (isupper(arr[i]))
//			arr[i] = tolower(arr[i]);
//		printf("%c ", arr[i]);
//		i++;
//	}
//	return 0;
//}

//使用内存函数复制
//使用调试观察内存

//内存函数的实现
//void* my_memcpy(void* dest, const void* scr, size_t num)
//{
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)scr;
//		dest = (char*)dest + 1;
//		scr = (char*)scr + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8 };
//	int arr1[12] = { 0 };
//	//16表示一个字符四个字节，复制的个数等于字节数乘以复制个数
//	//4*个数
//	my_memcpy(arr1, arr,16);
//	return 0;
//}

