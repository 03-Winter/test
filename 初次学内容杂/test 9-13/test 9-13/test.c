#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("p");
//		return;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//		printf("%d", p[i]);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("p");
//		return;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//	for (int i = 0; i < 10; i++)
//		printf("%d", p[i]);
//	int* ptr = realloc(p, 20*sizeof(int));
//	if (ptr != NULL)
//		p = ptr;
//	free(p);
//	p = NULL;
//	return 0;
//}



//��������
//struct s
//{
//	int n;
//	int arr[0];
//
//};
//int main()
//{
//	struct s* p = (struct s*)malloc(sizeof(struct s) + 10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("p");
//		return 1;
//	}
//	p->n = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//
//	}
//	struct s* ptr = (struct s*)realloc(p, sizeof(struct s)+20*sizeof(int));
//	if (ptr != NULL)
//		p = ptr;
//	 
//	free(p);
//	p = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	int* arr;
//}s;
//
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S));
//	if (p == NULL)
//	{
//		perror("p");
//		return 1;
//	}
//	p->n = 10;
//	p->arr = (int*)malloc(10*sizeof(int));
//	if (p->arr == NULL)
//		return 1;
//	for (int i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	struct S* ptr = (struct S*)realloc(p->arr, 20 * sizeof(int));
//	if (ptr != NULL)
//		p->arr = ptr;
//	free(p->arr);
//	p->arr = NULL;
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	//���ļ�
//	FILE* p = fopen("D:\\����ѧϰ\\test 9-13\\test 9-13\\test.dat", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	/*fputc('b', p);
//	fputc('i', p);
//	fputc('t', p);*/
//
//	//�ر��ļ�
//	fclose(p);
//	p = NULL;
//	return 0;
//
//}


//int main()
//{
//	/*fputc('b', stdout);
//	fputc('i', stdout);
//	fputc('t', stdout);*/
//	int ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//	ret = fgetc(stdin);
//	printf("%c\n", ret);
//
//	return 0;
//}

//int main()
//{
//	//���ļ�
//	FILE* p = fopen("D:\\����ѧϰ\\test 9-13\\test 9-13\\test.dat", "r");
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
//	ret = fgetc(p);
//	printf("%c\n", ret);
//	ret = fgetc(p);
//	printf("%c\n", ret);
//
//	//�ر��ļ�
//	fclose(p);
//	p = NULL;
//	return 0;
//
//}

