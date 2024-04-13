#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//初始化成员变量：必须要申明
// 1.引用成员变量
// 2.const的成员变量
// 3.自定义类型（没有默认的构造函数）
//
//class Se
//{
//public:
//	//Se(int a)
//	//	:_a(10)
//	//{
//
//	//}
//	//Se(int a=9)
//	//{
//
//	//}
//	Se()
//	{
//		n++;
//	}
//	Se(const Se& d)
//	{
//		++n;
//	}
//
//	static int GetN()//没有this指针，不能访问非静态成员
//	{ return n; }
//private:
//	int _a;
//	static int n;//申明 
//	//不是属于某个对象，
//	//而是属于类的所有对象，属于这个类
//
//};
//
//int Se::n = 0;

//class Fi
//{
//public:
//	Fi(int s, int abs, const int bs)
//		:_s(10), a(abs), b(bs)
//	{
//
//	}
//
//private:
//	Se _s;
//	int& a;
//	const int b;
//};

//int main()
//{
//	Se s1;
//	Se s2;
//	//突破类域的俩种方式
//	cout << s1.GetN() << endl;
//	cout << Se::GetN() << endl;
//	return 0;
//}

class Data
{
	//友元函数
	//friend void f(Data& d);
	friend ostream& operator<<(ostream& out, const Data& d);
	friend istream& operator>>(istream& in, Data& d);
		
public:
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//这个函数为什么不行：
	//根据传参可知，cout会传给this指针，而d1回传给out，顺序乱了
	// 所以我们使用友元函数
	// 
	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}


istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day ;
	return in;
}
//当外部函数想要使用 类成员变量，就可以使用友元函数
//void f(Data& d)
//{
//	d._year = 9;
//
//	cout << d._year << endl;
//
//}

int main()
{
	Data d1;
	Data d2;

	cin >> d1 >> d2;
	//当想要使用输入d1就要调用重载运算符
	cout << d1 << d2;
	return 0;
}
