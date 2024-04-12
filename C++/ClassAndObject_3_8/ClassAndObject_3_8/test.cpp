#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

class Data
{
public:

	//构造函数，在调用函数时，完成初始化的作用
	//Data(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	//重载函数
	// 
	// 
	// 
	//默认生成无参数构造函数	
	//1，针对内置成员变量不做处理
	//2，针对自定义类型成员变量，调用它的构造函数初始化
	//一旦用户自定义构造函数，将不会生成

	//
	/*Data()
	{
		_year = 1;
		_month = 2;
		_day = 3;
	}*/

	//plus++，使用全缺省函数
	Data(int year=2, int month=3, int day=12)
	{
		_year = year;
		_month = month;
		_day = day;
		//cout << "data" << this << endl;

	}
	//析构函数：完成对象里面的资源清理
	//~Data()
	//{
	//	cout << "clear" <<this<< endl;
	//}

	//void init(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	void print1()
	{
		cout << _year<<"-" << _month <<"-" << _day << endl;

	}
	//void print2()
	//{
	//	cout << "ad" << endl;
	//}
	//void show()
	//{
	//	cout << _year << endl;
	//}

	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//等于==运算符
	bool operator==(const Data& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator>(const Data& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if(_year==d._year && _month>d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		return false;
	}


private:
	int _year;
	int _month;
	int _day;
};

//Data::Data()				//定义
//{
//}
//
//Data::~Data()
//{
//}


int main()
{
	Data d1(2024,3,8);
	Data d2(2024,4,8);

	d1.print1();
	d2.print1();
	//a->print2();			//正常运行
	//a->show();			//崩溃		原因：this指向的成员变量不能为空
	d1 == d2;

	cout << (d1 == d2) << endl;

	cout << (d1 > d2) << endl;




	//d1.init(2024, 3, 8);
	//d1.print1();
	return 0;
}