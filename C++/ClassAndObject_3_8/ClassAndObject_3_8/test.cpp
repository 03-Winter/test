#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

class Data
{
public:

	//���캯�����ڵ��ú���ʱ����ɳ�ʼ��������
	//Data(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	//���غ���
	// 
	// 
	// 
	//Ĭ�������޲������캯��	
	//1��������ó�Ա������������
	//2������Զ������ͳ�Ա�������������Ĺ��캯����ʼ��
	//һ���û��Զ��幹�캯��������������

	//
	/*Data()
	{
		_year = 1;
		_month = 2;
		_day = 3;
	}*/

	//plus++��ʹ��ȫȱʡ����
	Data(int year=2, int month=3, int day=12)
	{
		_year = year;
		_month = month;
		_day = day;
		//cout << "data" << this << endl;

	}
	//������������ɶ����������Դ����
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
	//����==�����
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

//Data::Data()				//����
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
	//a->print2();			//��������
	//a->show();			//����		ԭ��thisָ��ĳ�Ա��������Ϊ��
	d1 == d2;

	cout << (d1 == d2) << endl;

	cout << (d1 > d2) << endl;




	//d1.init(2024, 3, 8);
	//d1.print1();
	return 0;
}