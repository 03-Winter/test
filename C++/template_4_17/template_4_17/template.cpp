#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//非类型模板
//注意：浮点数，类对象，字符串不允许作为非类型模板参数
//一般是整形：long/char/int/short
//template<class T,int N>
//class Aray
//{
//public:
//
//private:
//	T _a[N];
//};

//template<class T>
//bool isequal(T& x, T& y)
//{
//	return x == y;
//}
//
////模板的特化（就是 针对某种类型特殊化处理）
//
//template<>
//bool isequal<char*>(char*& x, char*& y)
//{
//	return strcmp(x, y) == 0;
//}
//
template<class T1, class T2>
class Data
{
public:
	//Date() {
	//	cout << "原模版" << endl;
	//}
private:
	T1 _a;
	T2 _b;
};
//全特化和偏特化
template<>
class Data<int, char>
{
public: 
	Data() { cout << "全特化" << endl; }
private:

};

template<class T2>
class Data<int,T2>
{
public: 
	Data() { cout << "偏特化" << endl; }
private:

};

template<class T1,class T2>
class Data<T1*,T2*>//里面的模板参数不能和类型一致
{
public: 
	Data() { cout << "偏特化" << endl; }
private:

};

template<class T1,class T2>
class Data<T1&,T2&>//里面的模板参数不能和类型一致
{
public: 
	Data() { cout << "偏特化" << endl; }
private:

};



int main()
{
	Data<int, char> a1;
	Data<int, int> a2;
	Data<int, double> a3;
	//Data<char, char> a4;
	Data<int*, char*> a5;
	Data<int&, char&> a6;
	//int a = 3, b = 3;
	//cout << isequal(a, b) << endl;

	//const char* c = "hello";
	//const char* d = "windows";
	//cout << isequal(c, d);
	//Aray<int, 10> a1;
	//Aray<int, 1000> a2;
	return 0;
}