#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
using namespace std;
#include<vector>

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> ve(v);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int> vew;
	vew.push_back(10);
	vew.push_back(20);
	vew.push_back(30);
	vew.push_back(40);
	v = vew;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}


void test_vector2()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//三种遍历
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator i = v.begin();
	while (i != v.end())
	{
		cout << *i<<" ";
		++i;

	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void print_vector(const vector<int>& v1)
{
	vector<int>::const_iterator i = v1.begin();
	while (i != v1.end())
	{
		cout << *i << " ";
		++i;

	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//正向迭代器
	vector<int>::iterator i = v.begin();
	while (i != v.end())
	{
		cout << *i << " ";
		++i;

	}
	cout << endl;
	print_vector(v);

	//反向迭代器
	vector<int>::reverse_iterator ri = v.rbegin();
	while (ri != v.rend())
	{
		cout << *ri << " ";
		++ri;

	}
 	cout << endl;

}


void test_vector4()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.insert(v.begin(), 0);
	v.insert(v.begin(), -1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//当你试图用 erase() 函数删除 end() 返回的迭代器所指向的位置时，
	//实际上是在请求删除一个不存在的元素。
	//v.erase(v.end());
	v.erase(std::prev(v.end()));

	
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector5()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(15);
	v.push_back(25);
	v.push_back(55);

	vector<int>::iterator pos = find(v.begin(), v.end(), 15);
	if (pos != v.end())
		v.erase(pos);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator i = v.begin();

	//报错：迭代器失效
	//原因：puhs_back,resize,insert，reserve等增容会导致迭代器失效
	/*v.push_back(7);
	v.push_back(8);*/

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
}


void test_vector7()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator i = v.begin();
	//要求删除里面所有的偶数
	while (i != v.end())
	{
		if (*i % 2 == 0)
		{
			//v.erase(i);		//vs检查报错，删除it后，指针指向的位置不对

			//解决方法：
			i = v.erase(i);
		}
		else
			++i;
	}
	cout << endl;


	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	test_vector7();
	return 0;
}