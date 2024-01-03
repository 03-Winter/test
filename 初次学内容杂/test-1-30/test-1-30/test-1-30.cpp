#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>


// void print(int n)
//{
//	if (n > 10)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

#include <string.h>


//int my_strlen(char* str)
//{
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;     //方法二
//	}
//	return count;
//}

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);       //方法一
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "hingjunlin";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//
//	for (i = 1; i <= n; i++)           ///求阶乘方法一
//	{
//
//		ret = ret * i;
//	}
//	printf("%d", ret);
//	return 0;
//}


//int Fac(int a)
//{
//	if (a > 1)
//		return a * Fac(a - 1);                     ////方法二
//
//	else
//		return a;
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", Fac(n));
//	return 0;
//}




//int count = 0;
//int Fib(int n)
//{
//	if (n == 3)
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);             ///计算斐波拉数列----递归
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d", Fib(a));
//	printf("count =%d\n", count);
//
//	return 0;
//}



//int Fib(int n)
//{
//	int b = 1; int c = 1; int d = 1;             ///逆向思维求斐波拉数列
//	while (n > 2)
//	{
//		d = b + c;
//		b = c;
//		c = d;
//		n -= 1;
//	}
//	return d;
//}
//
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d", Fib(a));
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 1;j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i,j,i * j);            //计算九九乘法表
//		}
//		printf("\n");
//	}
//	return 0;
//}




// 运算  1/1-1/2+1/3-1/4......1/99-1/100

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	for (i = 1; i <= 100;i++)
//	{
//		if (i % 2 == 0)
//			sum -= 1.0 / i;              ////方法一
//		else
//			sum += 1.0 / i;
//	}
//	printf("%lf", sum);
//	return 0;
//}




//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * (1.0 / i);   qiu          //方法一
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}



//求10数中的最大值
//
//int main()
//{
//	int arr[10] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
//	int i = 0;
//	int max =arr[ 0];                      最好用数组赋值，防止出错
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}
//	printf("%d", max);
//	return 0;
//}

//
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}




//void reverse_string(char* arr)
//{
//	int left = 0;
//	int right = my_strlen(arr) - 1;
//	while (left < right)
//	{
//
//		//方法一
//		/*char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;*/
//
//		//方法二
//		char tmp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = tmp;
//
//
//		right--;
//		left++;
//	}
//
//}


//void reverse_string(char* arr)
//{
//	char tmp = *arr;
//	int len = my_strlen(arr) - 1;
//	*(arr) = *(arr + len);
//	*(arr + len) = '\0';
//	if (my_strlen(arr + 1) >= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	*(arr + len) = tmp;
//}
//
//
//
//int main()
//
//{
//	//printf("hh");
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}



//计算位数和
// 
// 
// 
// 
//int Digitsum(int n)
//{
//	if (n > 9)
//	{
//		return Digitsum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//
//
//int main()
//{
//	int num = 1729;
//	int sum = Digitsum(num);
//	printf("%d", sum);
//	return 0;
//}



//计算 n的k次方


//
//double Pow(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1.0;
//	}
//	else if (k > 0)
//	{
//		return n*Pow(n,k-1);
//	}
//	else
//	{
//		return 1.0/ Pow(n, -k);
//	}
//}
//int main()
//{
//	int n=0;
//	int k=0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%lf", ret );
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("&arr[%d] =%p\n", i, &arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}

//int main() 
//{
//	int arr[3][4]= { 1,2,3,4,5,6,7,6,8,9,0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//			printf("&arrr[%d][%d]=%p\n", &arr[i][j]);
//		printf("\n");
//	}
//	return 0;
//}

int main()
{
	FILE* fp = fopen("/mnt/hgfs/share/","r");
	if (fp == NULL)
	{
		perror("fopen error");
		return 1;
	}
	printf("fopen file success!");
	return 0;
}