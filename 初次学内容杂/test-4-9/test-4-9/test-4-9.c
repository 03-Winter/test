#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include<string.h>

#include <assert.h>

//int main()
//{
//	//const int num = 10;
//	//int* const p = &num;
//
//	////const ����ָ�������ʱ��
//	////const �������*���ұߣ����ε���ָ�����p����ʾָ��������ܱ��ı�
//	////      ����ָ��ָ������ݿ��Ա��޸�
//	//*p = 20;    ok
//	//p = &n;     error
//
//
//
//	//const int num = 10;
//	//const int*  p = &num;
//
//	////const ����ָ�������ʱ��
//	////const �������*����ߣ����ε���ָ�����*p����ʾָ��ָ��Ĳ��ܱ��ı�
//	////      ����ָ��������Ա��޸�
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


//�Ż�һ
//void  my_strcpy(char* dest, char* scr)
//{
//	while (*dest++ = *scr++)
//	{
//		;
//	}
//}

//char  my_strcpy(char* dest, char* scr)
//{
//	assert(scr != NULL);        //���������
//	//assert(scr);     ��������һ
//	while (*dest++ = *scr++)
//	{
//		;
//	}
//}



char*  my_strcpy(char* dest, const char* scr)
{
	assert(scr != NULL);        //���������
	//assert(scr);     ��������һ

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
	//�Ż�һ       my_strcpy(brr, arr);
	 //my_strcpy(brr, arr);
	printf("%s\n", my_strcpy(brr, arr));  //��ʽ����
	//printf("%s\n", brr);

	return 0;
}


