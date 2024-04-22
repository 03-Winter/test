#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
#include<assert.h>

#include"stl_vector.h"

void test_vector2()
{
	zjl::vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		it = v.erase(it);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//	//cout << *it << " ";
	//	//++it;
	//}
	//cout << endl;
	//一般不用memxxx，因为他们是按字节处理
	//memset(a, 0, sizeof(int) * 10);//32bit
	//00000000 00000000 00000000 00000000
	//memset(a, 1, sizeof(int) * 10);//32bit
	//00000001 00000001 00000001 00000001  它的值很大
	//v.resize(4, 8);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector1()
{
	zjl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	zjl::vector<int>::iterator i = v.begin();
	while (i != v.end())
	{
		cout << *i << " ";
		++i;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test_vector3()
{
	zjl::vector<int> v1;
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);

	//实现vector的深拷贝
	zjl::vector<int> v2(v1);
	zjl::vector<int> v3 = v1;
	//v3 = v1;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	//zjl::test_vector1();
	//zjl::test_vector2();
	zjl::test_vector4();
	//test_vector3();


	return 0;
}
