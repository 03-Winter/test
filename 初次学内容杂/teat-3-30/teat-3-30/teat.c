#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <string.h>
//
//计数器法
// 
//int my_strlen(char* str)
//{
//	int count = 0;
//	while(*str !='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
// 
// 指针减指针法（原理：指针相减为中间的元素个数）
// 
// 
// 
//int my_strlen(char* str)
//{
//	int* p = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - p;
//}
//

//递归法
//

//int my_strlen(char* str)
//{
//	while (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//int main()
//{
//	int len = my_strlen("abcadjhskfalufh");
//	printf("%d", len);
//	return 0;
//}


//struct x
//{
//	int a;
//	float b;
//	char c;
//
//};
//struct stu
//{
//	struct x as;
//	char name[20];
//	int id;
//	double high;
//};
//
//
//void print(struct stu s)
//{
//	printf("%d %f %c %s %d %lf\n", s.as.a, s.as.b, s.as.c, s.name, s.id, s.high);
//};
//
//void print1(struct stu* s)
//{
//	printf("%d %f %c %s %d %lf\n", s->as.a, s->as.b, s->as.c, s->name, s->id, s->high);
//}
//
//
//int main()
//{
//	struct stu s = { {2,3,'g'},"zhonglin",2023,1.74 };
//	//printf("%s %d %lf\n", s.name, s.id, s.high);
//	print(s);
//	print1(&s);
//	return 0; 
//}


//int main()
//{
//	int m,ret=1,sum=0;
//	scanf("%d", &m);
//	for (int i = 1; i <= m; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}




//#include<stdio.h>
//#include<stdlib.h>
//#define Maxsize 100
//
//typedef struct Snode
//{
//	int data[Maxsize];
//	int top;
//}Seqstack;
////栈空: top = -1
////栈满: top = Maxsize - 1;
////栈中总元素个数: top + 1
////初始化栈
//Seqstack* Init_Stack()
//{
//	Seqstack* s;
//	//思考：此处为什么要用malloc开辟一段新的内存空间?
//	//因为s是指向结构体的指针，但现在连结构体都没有，所以要malloc一个和结构体大小相同的空间，使s指向它
//	s = (Seqstack*)malloc(sizeof(Seqstack));
//	s->top = -1;
//	return s;
//}
//
////入栈
//void Push_Stack(Seqstack* s, int e)
//{
//	if (s->top == Maxsize - 1)
//	{
//		printf("FULL\n");
//	}
//	else
//	{
//		s->top++;
//		s->data[s->top] = e;
//		printf("PUSH!\n");
//	}
//}
//
////出栈
//int Pop_Stack(Seqstack* s)
//{
//	int x;
//	if (s->top == -1)
//	{
//		printf("EMPTY!\n");
//		return 0; //表示函数正常终止
//	}
//	else
//	{
//		x = s->data[s->top];
//		printf("%d\n", x);
//		s->top--;
//		return 1; //表示函数非正常终止
//	}
//}
//
////取栈顶元素
////此处注意取栈顶元素和出栈的区别
//void Top_Pop(Seqstack* s)
//{
//	if (s->top == -1)
//	{
//		printf("NULL\n");
//		return 1;
//	}
//	else
//	{
//		printf("%d\n", s->data[s->top]);
//	}
//}
//int main()
//{
//	Seqstack* s;
//	s = Init_Stack();
//	Push_Stack(s, 3);//令3入栈
//	Push_Stack(s, 4);//令4入栈
//	Top_Pop(s); // 取栈顶元素
//	Pop_Stack(s);//出栈
//	Pop_Stack(s);//出栈
//	Pop_Stack(s);//出栈
//	return 0;
//}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define MAX 20
//#define MAXSIZE 5
//typedef int Elemtype;
//typedef struct{
//	Elemtype data[MAX];
//	int top;
//}Stack;
//typedef struct {   
//	Elemtype data[MAXSIZE];
//	int front, rear;
//}Queue;
//void InitStack(Stack &S)
//
//{  S.top = -1;
//void InitQueue(Queue& Q) 
//{
//	Q.front = Q.rear = 0;
//	//入栈\nbool Push(Stack& S)
//	{
//		int a;
//		if (S.top == MAX - 1)
//		{
//			return false;
//		}
//		for (int i = 1; i < 4; i++)
//		{
//			scanf("%d", &a);
//				S.data[++S.top] = a;
//		}
//		return true;
//	}
//	bool Pop(Stack& S, Elemtype& e)
//	{
//		if (S.top == -1)
//		{
//			return false;
//		}
//		e = S.data[S.top--];
//		return true;
//	}
//	bool EnQueue(Queue& Q, Elemtype &e)
//	{
//		while ((Q.rear + 1) % MAXSIZE != Q.front)
//		{
//			Q.data[Q.rear] = e;
//			Q.rear = (Q.rear + 1) % MAXSIZE;
//			scanf("%d", &e);
//		}\n    return false;
//		bool DeQueue(Queue& Q, Elemtype& e)
//		{
//			if (Q.rear == Q.front)
//			


//int main()
//{
//	printf("hello world");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20
#define MAXSIZE 5
typedef int Elemtype;

typedef struct {
    Elemtype data[MAX];
    int top;
}Stack;

typedef struct {
    Elemtype data[MAXSIZE];
    int front, rear;
}Queue;

typedef  InitStack(Stack &S)
{
    S.top = -1;
}

//对队列初始化
typedef InitQueue(Queue& Q)
{
    Q.front = Q.rear = 0;
}

typedef Push(Stack& S)
{
    int a;
    if (S.top == MAX - 1)//判断栈是否满了
    {
        return 0;
    }
    for (int i = 1; i < 4; i++)
    {
        scanf("%d", &a);
        S.data[++S.top] = a;
    }
    return 1;
}

typedef Pop(Stack& S, Elemtype& e)
{
    if (S.top == -1)
    {
        return 0;
    }
    e = S.data[S.top--];
    return 1;
}

typedef EnQueue(Queue& Q, Elemtype& e)
{
    while ((Q.rear + 1) % MAXSIZE != Q.front)
    {
        Q.data[Q.rear] = e;
        Q.rear = (Q.rear + 1) % MAXSIZE;
        scanf("%d", &e);
    }
    return 0;
}

Status DeQueue(Queue &Q, Elemtype& e)
{
    if (Q.rear == Q.front)
    {
        return 0;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return 1;
}


int main()
{
    Elemtype a;
    Elemtype e;
    int  ret;
     Stack S;
     Queue Q;
    InitQueue(Q);
    InitStack(S);
    Push(S);
    scanf("%d", &e);
    for (int i = S.top; i > -1; i--)
    {
        Pop(S, a);
        printf("%2d", a);
    }
    printf("\n");
    ret = EnQueue(Q, e);
    if (ret) {
        return 1;
    }
    else {
        printf("0\n");
    }
    while (Q.rear != Q.front)
    {
        DeQueue(Q, a);
        printf("%2d", a);
    }
    return 0;

}
