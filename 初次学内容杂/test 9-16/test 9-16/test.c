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
//	//读文件
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
//	//当读取不到字符，将返回EOF得值-1
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
//	//打印
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

	//sprinf是一个将格式化的数据转化成字符串
	sprintf(num, "%d %f %s", s.n, s.f, s.arr);
	printf("%s\n", num);
	//sscanf从字符串num的数据还原成结构体数据
	sscanf(num, "%d %f %s", &(tmp.n), &(tmp.f), tmp.arr);
	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
	return 0;
}