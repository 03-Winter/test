#define _CRT_SECURE_NO_WARNINGS  1


#include<stdio.h>

//void print(int* ptr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(ptr + i));
//	}
//}
//
//
//void test(char* p)
//{
//	printf("%c ", *p);
//}
//int main()
//{
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	char ch = 'w';
//	char* p1 = &ch;
//
//	test(&ch);
//	test(p1);
//	return 0;
//}
//void test(int** pa)
//{
//	**pa = 20;
//}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int** ppa = &p;
//	//test(ppa);
//	  //test(&p);
//	int* ar[10] = { 0 };
//	test(ar);
//	printf("%d ", a);
//	return 0;
//}


//����ָ�룺ָ������ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//
//	int (*p)(int, int) = Add;
//	int ret = (*p)(3, 5);
//	int rt = p(3, 5);
//	int we = Add(3, 5);
//	printf("%d", ret);
//	printf("%d", rt);
//	printf("%d", we);
//
//	return 0;
//
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int mult(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	//(*(void(*)())0)();
//	//mat(int, void(*)(int))���俴��Ϊ������һ������Ϊint����һ������Ϊ����ָ��
//	void(* mat(int,void(*)(int)))(int);
//	typedef unsigned int uint;
//	typedef void(*my)(int);
//	my mat(int, void(*)(int));
//
//
//
//	//����ָ������
//	int (*p2)(int, int) = Sub;
//
//	int (*p1)(int, int) =  Add ;
//	int (*arr[2])(int, int) = { Add,Sub };
//	return 0;
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int mult(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
////дһ��������ġ��Ӽ��˳�������
//
//void menu()
//{
//	printf("******************************\n");
//	printf("******************************\n");
//	printf("********* 1.�ӷ�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("********* 2.�˷�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("******************************\n");
//	printf("******************************\n");
//
//}
//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		int x = 0, y = 0, ret = 0;
//		int (*p[5])(int, int) = { NULL,Add,Sub,mult,div };
//		printf("��ѡ���������������\n");
//		scanf("%d", &input);
//
//		/*switch (input)
//		{ 
//		case 1:
//			printf("��������������");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:
//			printf("��������������");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			printf("��������������");
//			scanf("%d %d", &x, &y);
//			ret = mult(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			printf("��������������>");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		default:
//			printf("������󣡣���\n");
//		}*/
//	} while (input);
//
//	return 0;
//
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int mult(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
////дһ��������ġ��Ӽ��˳�������
//
//void menu()
//{
//	printf("******************************\n");
//	printf("******************************\n");
//	printf("********* 1.�ӷ�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("********* 2.�˷�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("******************************\n");
//	printf("******************************\n");
//
//}
//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		int x = 0, y = 0, ret = 0;
//		int (*p[5])(int, int) = { NULL,Add,Sub,mult,div };
//		printf("��ѡ���������������\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("��������������");
//			scanf("%d %d", &x, &y);
//			ret = (*p[input])(x, y);
//			printf("ret=%d \n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����");
//			break;
//
//		}
//		else
//		{
//			printf("������󣡣���");
//		}
//	} while (input);
//	return 0;
//}

//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int mult(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//
//
//void menu()
//{
//	printf("******************************\n");
//	printf("******************************\n");
//	printf("********* 1.�ӷ�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("********* 2.�˷�  ************\n");
//	printf("********* 2.����  ************\n");
//	printf("******************************\n");
//	printf("******************************\n");
//
//}
//
////ʹ�ûص��������������������
//int cal(int (*p)(int, int))
//{
//	int x = 0, y = 0;
//	printf("��������������");
//	scanf("%d %d", &x, &y);
//	return p(x, y);
//}
//int main()
//{
//	int input = 0;
//	do {
//		menu();
//		 int ret = 0;
//		//int (*p[5])(int, int) = { NULL,Add,Sub,mult,div };
//		printf("��ѡ���������������\n");
//		scanf("%d", &input);
//
//		switch (input)
//		{ 
//		case 1:
//			
//			ret = cal(Add);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:
//			ret = cal(Sub);
//			printf("ret=%d\n", ret);
//			break;
//		case 3:
//			ret = cal(mult);
//			printf("ret=%d\n", ret);
//			break;
//		case 4:
//			ret = cal(div);
//			printf("ret=%d\n", ret);
//			break;
//		default:
//			printf("������󣡣���\n");
//		}
//	} while (input);
//
//	return 0;
//
//}