#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;

//引用作为参数

//void swap_c(int* a, int* b)
//{
//	int tem = *a;
//	*a = *b;
//	*b = tem;
//}
//
//void swap_cpp(int& w, int& e)
//{
//	int tem=w;
//	w = e;
//	e = tem;
//}

//引用作为返回值
//可以提高效率
//int& add1(int a, int b)
//{
//	static int c = a + b;		//static是用来申明周期的，保证了出了作用域还在
//	return c;
//}
//
//
//
//int& add2(int a, int b)
//{
//	int c = a + b;
//	return c;
//}


//内联函数没有地址--inline

//auto可以自动生成类型，但是必须初始化
//auto不能作为函数参数
// auto也不能申明数组
//


//auto k可以简化代码，不用再输入
//std::map<std::string, std::string> dict;
//auto dict=ti;

//int main()
//{

	//int x = 0, y = 2,z=8;
	////swap_c(&x, &y);
	////swap_cpp(x, y);

	//int& ret = add1(x, y);
	//add1(x, z);       //当返回值是临时变量时，引用返回是不安全的
	//cout << "add(x,y)=" << ret << endl;

	//int arr[] = { 1,2,4,5,7 };//把数组每个数提高俩倍
	//C语言版
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	arr[i] = arr[i] * 2;
	//}
	//
	//for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	//	cout << arr[i] << endl;
	//c++
	//for (auto& e: arr)
	//{
	//	e = e * 2;
	//}
	//for (auto e : arr)
	//	cout << e <<" ";





//
//	return 0;
//}

//
//void fun(int n)
//{
//	cout << "asd";
//}
//
//void fun(int* v)
//{
//	cout << "fre";
//}
//
//int mian()
//{
//	fun(0);
//	fun(NULL);			//预处理后变成fun(0)
//	fun(nullptr);		//fun((void*)0)
//
//	//所以再c++中建议使用nullptr
//	return 0;
//
//}


class stu
{
	//如果 没用申明，默认为私有private
	// 
	// 相反，struct类型，不申明默认公有
	//申明类型
public:
	void dun()
	{
		cout << "tr";
	}

	//申明类型
private:
	char* _name;
	int _age;
	int* _stuid;
};

//c++结构体
class ListNode_cpp {
	int val;
	ListNode_cpp* _next;
	ListNode_cpp* _prev;

	//还可以定义成员函数
	ListNode_cpp* CreatNode(int val);
};

//c的结构体
struct ListNode_c {
	int val;
	struct ListNode_c* _next;
	struct ListNode_c* _prev;

};

//没有成员变量的类大小是一，为什么大小不是，零而是一     
//答：开一个字节不是为了存数据，而是表示占位，表示对象存在
int main()
{
	stu s1;
	stu s2;


	return 0;
}