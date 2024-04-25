#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<assert.h>
using namespace std;

#include"stl_list.h"
void test_list3()
{
	zjl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	zjl::print_list(lt);
}

struct Data
{
	int _year = 1;
	int _month = 4;
	int _day = 11;
};
void test_list2()
{
	//Data* p1 = new Data;
	//p2->_year;

	zjl::list<Data> lt;
	lt.push_back(Data());
	lt.push_back(Data());



	zjl::list<Data>::iterator li = lt.begin();
	while (li != lt.end())
	{
		//cout << li->_year << '-' << li->_month << '-' << li->_day << '-';
		cout << (*li)._year << '-' << (*li)._month << '-' << (*li)._day << '-';
		++li;
	}
	cout << endl;
}


void  test_list1()
{
	zjl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	zjl::list<int>::iterator li = lt.begin();
	while (li != lt.end())
	{
		cout << *li << " ";
		++li;
	}
	cout << endl;
}
int main()
{
	//zjl::test_list1();
	//zjl::test_list2();
	//zjl::test_list3();
	//zjl::test_list4();
	zjl::test_list5();

	return 0;
}