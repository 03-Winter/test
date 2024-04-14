#define _CRT_SECURE_NO_WARNINGS  1

#include <iostream>
using namespace std;

//typedef struct ListNOde_c {
//    int val;
//    struct ListNOde_c* next;
//    struct ListNOde_c* prev;
//}LN;
//
//LN* BuyList_c(int val)
//{
//    LN* node_c = (LN*)malloc(sizeof(LN));
//    node_c->val = 1;
//    node_c->next = NULL;
//    node_c->prev = NULL;
//
//    return node_c;
//}
//
//
//struct Node_cpp
//{
//    Node_cpp(int val=0)//构造函数
//        :val(val),
//        _next(nullptr)
//        ,_prev(nullptr)
//    {
//
//    }
//public:
//    int val;
//    Node_cpp* _next;
//    Node_cpp* _prev;
//};
//
//template<class T>
//void Swap(T& x1, T& x2)
//{
//    T tem = x1;
//    x1 = x2;
//    x2 = tem;
//}

//int main() {

    




    ////ccccc
    //int* p1 = (int*)malloc(sizeof(int));
    //int* p2 = (int*)malloc(sizeof(int)*10);
    //free(p1);
    //free(p2);


    ////cppcppcppcppcpppcpppcpp

    //int* p3 = new int(10);//初始化为10
    //int* p4 = new int[10];//申请10个空间的数组
    //delete p3;
    //delete[] p4;

    //c 
    //ListNOde_c* p1 = (ListNOde_c*)malloc(sizeof(ListNOde_c));
    //ListNOde_c* node1 = BuyList_c(1);
    //ListNOde_c* node1 = BuyList_c(2);
    //ListNOde_c* node1 = BuyList_c(2);
    //
    ////cpp
    //Node_cpp* node2 = new Node_cpp;//1.动态开辟空间   2.自动调用构造函数
    //Node_cpp* node3 = new Node_cpp(10);

    //delete node2;
    //delete node3;



    //int a = 2, b = 9;
    //Swap(a, b);

    //cout << a << b << endl;


    //char c = 's', d = 'w';
    //Swap(c, d);
    //cout << c << d << endl;



    //int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    //int year, month, day;
    //cin >> year >> month >> day;
    //int n = 0;
    //n += day;
    //month--;
    //while (month != 0)
    //{

    //    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
    //    {
    //        n += MonthDay[month] + 1;
    //    }
    //    else {
    //        n += MonthDay[month];

    //    }
    //    month--;
    //}
    //cout << n << endl;
//
//    return 0;
//
//}

typedef int DataType;

typedef struct Stack_c
{
    DataType* a;
    int top;
    int capecity;
}ST_c;

void Cinit(Stack_c* ps);
void Cdestroy(Stack_c* ps);
void Cpush(Stack_c* ps, DataType x);
void Cpop(Stack_c* ps, DataType x);


template<class T>
class Stack_cpp
{
public:
    Stack_cpp()
    {}
    ~Stack_cpp()
    {}
    void CppPush(T x)
    {}
private:
    T* a;
    int top;
    int capecity;
};
 
int main()
{

    //C语言版
    Stack_c c;
    Cinit(&c);
    Cpush(&c, 1);
    Cpush(&c, 2);
    Cpush(&c, 3);
    Cpush(&c, 4);
    Cdestroy(&c);

    //Cplusplus
    // 对C语言部分的优化
    //1.具备构造函数和析构函数
    //2.类和访问限定符
    //3.如果想要定义俩个栈，一个int，一个double，就可以使用模板
    Stack_cpp<int> cpp;

    cpp.CppPush(1);
    cpp.CppPush(2);
    cpp.CppPush(3);

    Stack_cpp<double> cppd;

    cppd.CppPush(5);
    cppd.CppPush(6);
    cppd.CppPush(7);




    return 0;
}
