#define _CRT_SECURE_NO_WARNINGS  1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��������Ҳ��Ͱ����
// 123 45 12 9 88 43
//��һ�Σ�12 123 43 45 88 9
//�ڶ��Σ�9 12 123 43 45 88
//�����Σ�9 12 43 45 88 123
// ԭ�����ηֱ�ȡ���Ǹ�λ��ʮλ����λ����������
//



//��������
// 
// ԭ��ͳ��ÿ�����ִ�Ĵ���
// 
//Ϊ�˱���ռ���˷ѣ������þ���ӳ�䣺��num-min
// 
//
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int j = 0; j < n; ++j)
	{
		if (min > a[j])	min = a[j];
		if (max < a[j])	max = a[j];
	}
	
	int rang = max -min + 1;
	int* count = (int*)malloc(sizeof(int) * rang);
	memset(count, 0, sizeof(int)*rang);

	for (int j = 0; j < rang; ++j)
	{
		count[a[j] - min]++;
	}

	int index = 0;
	for (int j = 0; j < rang; ++j)
	{
		while (count[j]--)
		{
			a[index++] = min + j;
		}
	}
}

int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(a) / sizeof(a[0]);
	CountSort(a, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}


	return 0;
}





