#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>

//int main()
//{
//	FILE* p = fopen("test.dat", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ret = fgetc(p);
//	printf("%c\n", ret);
//	ret = fgetc(p);
//	printf("%c\n", ret);
//
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	//����ȡ�����ַ���������EOF��ֵ-1
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	fclose(p);
//	p = NULL;
//
//	return 0;
//		}


//int main()
//{
//	char arr[] = "xxxxxxxx";
//	FILE* p = fopen("test.dat", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//fputs("ght", p);
//	//fputs("qwrst", p);
//	fgets(arr, 3, p);
//	printf("%s\n", arr);
//	fgets(arr, 5, p);
//	printf("%s\n", arr);
//
//
//	fclose(p);
//	p = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float f;
//	char arr[100];
//
//};

//int main()
//{
//	struct S s = { 10,5.5f,"abcdef" };
//	FILE* p = fopen("test.dat", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(p, "%d %f %s", s.n,s.f,s.arr);
//
//
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	struct S s = { 0 };
//	FILE* p = fopen("test.dat", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//fprintf(p, "%d %f %s", s.n, s.f, s.arr);
//	fscanf(p, "%d %f %s", &s.n, &s.f, s.arr);
//
//
//	//��ӡ
//	fprintf(stdout,"%d %f %s", s.n, s.f, s.arr);
//	//printf("%d %f %s",s.n, s.f, s.arr);
//	fclose(p);
//	p = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float f;
//	char arr[100];
//
//};
//	
//
//int main()
//{
//	struct S s = { 10,5.5f,"abcdef" };
//	FILE* p = fopen("test.dat", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(&s, sizeof(struct S), 1, p);
//	p = NULL;
//	return 0;
//}
// 
// 
struct S
{
	int n;
	float f;
	char arr[100];

};

int main()
{
	struct S s = { 10,7.6,"hello" };
	struct S tmp = { 0 };
	char num[100] = { 0 };

	//sprinf��һ������ʽ��������ת�����ַ���
	sprintf(num, "%d %f %s", s.n, s.f, s.arr);
	printf("%s\n", num);
	//sscanf���ַ���num�����ݻ�ԭ�ɽṹ������
	sscanf(num, "%d %f %s", &(tmp.n), &(tmp.f), tmp.arr);
	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
	return 0;
}