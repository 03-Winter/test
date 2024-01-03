#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include<string.h>

#include <assert.h>

//int main()
//{
//	//const int num = 10;
//	//int* const p = &num;
//
//	////const 修饰指针变量的时候
//	////const 如果放在*的右边，修饰的是指针变量p，表示指针变量不能被改变
//	////      但是指针指向的内容可以被修改
//	//*p = 20;    ok
//	//p = &n;     error
//
//
//
//	//const int num = 10;
//	//const int*  p = &num;
//
//	////const 修饰指针变量的时候
//	////const 如果放在*的左边，修饰的是指针变量*p，表示指针指向的不能被改变
//	////      但是指针变量可以被修改
//	//*p = 20;     error
//	//p = 9;       ok
//	//printf("%d\n", *p);
//	return 0;
//}







//int main()
//{
//	int i;
//	scanf("%d", &i);
//	return 0; 
//}

//void  my_strcpy(char* dest, char* scr)
//{
//	int count = 0;
//	while (*scr != '\0')
//	{
//		*dest = *scr;
//		dest++;
//		scr++;
//	}
//	*dest = *scr;
//}


//优化一
//void  my_strcpy(char* dest, char* scr)
//{
//	while (*dest++ = *scr++)
//	{
//		;
//	}
//}

//char  my_strcpy(char* dest, char* scr)
//{
//	assert(scr != NULL);        //报错的理解二
//	//assert(scr);     报错的理解一
//	while (*dest++ = *scr++)
//	{
//		;
//	}
//}



char*  my_strcpy(char* dest, const char* scr)
{
	assert(scr != NULL);        //报错的理解二
	//assert(scr);     报错的理解一

	char* ret = dest;
	while (*dest++ = *scr++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr[] = "abcdef";
	char brr[] = "**********";
	//优化一       my_strcpy(brr, arr);
	 //my_strcpy(brr, arr);
	printf("%s\n", my_strcpy(brr, arr));  //链式访问
	//printf("%s\n", brr);

	return 0;
}


