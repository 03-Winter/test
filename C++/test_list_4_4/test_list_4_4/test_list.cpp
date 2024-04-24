#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
#include<list>
#include<vector>
void print_list(const list<int>& l)
{
	list<int>::const_iterator li = l.begin();
	while (li != l.end())
	{
		cout << *li << " ";
		++li;
	}
	cout << endl;

}

void test_list1()
{
	list<int> l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	l.push_front(1);
	l.push_front(-1);

	l.pop_back();
	l.pop_back();

	l.pop_front();

	list<int>::iterator li = l.begin();
	while (li != l.end())
	{
		cout << *li << " ";
		++li;
	}
	cout << endl;

	print_list(l);

	list<int>::reverse_iterator rli = l.rbegin();
	while (rli != l.rend())
	{
		cout << *rli << " ";
		++rli;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

//拷贝复制
void test_list2()
{
	list<int> l1;
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(3);
	l1.push_back(3);


	list<int> l2(l1);
	list<int> l3 = l1;
	for (auto e : l2)
	{
		cout << e << " ";
	}
	cout << endl;


	for (auto e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list3()
{
	list<int> l1;
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(9);

	print_list(l1);

	//在某个位置插入一个值
	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);
	if(pos != l1.end())
	{
		l1.insert(pos, 4);
		l1.erase(pos);
	}

	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	v.push_back(9);

	//vector使用迭代器会失效  失效版
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//if (pos != v.end())
	//{
	//	v.insert(pos, 4);//因为insert可能会增容
	//	v.erase(pos);
	//}
	
	//改正版
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		pos=v.insert(pos, 4);//因为insert可能会增容
		++pos;
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list4()
{
	list<int> l1;
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(9);

	print_list(l1);
	l1.sort();
		
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

	l1.reverse();

	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list5()
{
	list<int> l1;
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(9);

	print_list(l1);
	//list中也会出现迭代器失效，这个erase删除后，位置报错
	//list<int>::iterator l = l1.begin();
	//while (l !=  l1.end())
	//{
	//	if (*l % 2 == 0)
	//	{
	//		l1.erase(l);
	//	}
	//	else
	//	{
	//		++l;
	//	}
	//}
	list<int>::iterator l = l1.begin();
	while (l !=  l1.end())
	{
		if (*l % 2 == 0)
		{
			l=l1.erase(l);
		}
		else
		{
			++l;
		}
	}
	print_list(l1);

}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	test_list5();
	//test_vector();
	return 0;
}