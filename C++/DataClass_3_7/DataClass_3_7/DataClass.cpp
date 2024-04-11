#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month) const 
	{
		static int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//转化为静态
		if (month==2 && (year % 4 == 0 && year % 100 == 0) || year % 400 == 0)
		{
			return 29;
		}
		return arr[month];
	}

	Data(int year = 0, int month = 3, int day = 23)
	{
		if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
		{
			_year=year;
			_month = month;
			_day = day;
		}
		else
			cout << "false" << endl;
	}
	//构造函数的拷贝，也叫拷贝函数
	Data(const Data& d)
	{
		//防止给自己赋值
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	//const 修饰函数，可以使非const和const函数调用
	void print()const//等价于void print(const Data& this)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Data& d) const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;

		return false;

	}
	////版本一
	bool operator<(const Data& d) const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;

	}
	//版本二
	//bool operator<(const Data& d)
	//{
	//	return !(*this >= d);
	//}

	//以下俩个实现复用
	//版本一
	//bool operator>=(const Data& d)
	//{
	//	return *this > d || *this == d;
	//}
	//版本二
	//bool operator>=(const Data& d)
	//{
	//	return !(*this < d);
	//}


	//版本一

	//bool operator<=(const Data& d)
	//{
	//	return *this < d || *this == d;
	//}
	//版本二
	//bool operator<=(const Data& d)
	//{
	//	return !(*this > d);
	//}

	////版本一
	bool operator!=(const Data& d) const
	{
		return !(*this == d);
	}
	////版本二

	bool operator==(const Data& d) const
	{
		return _year == d._year && _month == d._month && d._day == _day;
	}

	//Data operator+(int day)
	//{
	//	Data ret(*this);
	//	ret._day += day;
	//	while (ret._day > GetMonthDay(ret._year, ret._month))
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		ret._month++;
	//		if (ret._month == 13)
	//		{
	//			ret._year++;
	//			ret._month = 1;
	//		}

	//	}
	//	return ret;
	//}
	Data operator+(int day) const
	{
		Data ret(*this);
		ret += day;
		return ret;
	}

	Data& operator+=(int day) 
	{
		if (day < 0)
		{
			_day += -day;

		}
		else
			_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}

		}
		return *this;
	}

	Data& operator-=(int day)
	{
		if (day < 0)
		{
			_day -= -day;
		}
		else
		{
			_day -= day;
		}
		while (_day<=0)
		{
			_month--;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;

	}
	//实现日期减天数
	//Data operator-(int day)
	//{
	//	Data ret(*this);
	//	ret._day -= day;
	//	while (ret._day <= 0)
	//	{
	//		--ret._month;
	//		if (ret._month = 0)
	//		{
	//			--ret._year;
	//			ret._month = 12;
	//		}
	//		ret._day += GetMonthDay(ret._year, ret._month);
	//	}
	//	return ret;
	//}

	//复用节省空间
	Data operator-(int day)
	{
		Data ret(*this);
		ret -= day;
	
		return ret;
	}
	//++d1
	Data& operator++()
	{
		*this += 1;
		return *this;
	}

	//d1++
	Data operator++(int)
	{
		Data tem(*this);
		*this += 1;
		return tem;
	}
	Data& operator--()
	{
		*this -= 1;
		return *this;
	}

	//天数-天数得到的差
	int operator-(const Data& d)
	{
		Data max=*this;
		Data min=d;
		if (*this < d )
		{
			max = d;
			min = *this;
		}
		int n = 0;
		while (max != min)
		{
			min++;
			++n;
		}
		return n;
	}

	Data* operator&()
	{
		cout << "non-const" << endl;
		return this;
	}
	const Data* operator&()const 
	{
		cout << "const" << endl;
		return this;
	}



private:

	int _year;
	int _month;
	int _day;
};





int main()
{
	Data d1(2024,3,31);
	Data d2(2024,5,12);
	const Data d3(2024,7,12);
	cout << &d1 << endl;
	cout << &d2 << endl;
	cout << &d3 << endl;
	//Data d3=d2-=13;
	//d3.print();	
	// 
	//cout<<(d2-d1)<<endl;
	
	//cout <<"we" <<(d1)<< endl;
	return 0;
}