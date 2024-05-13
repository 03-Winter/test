#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<map>
#include<string>
using namespace std;

void test_map1()
{
	map<int,int> m;
	//m.insert()
	//他是通过关键字找的value值，所以不能有一样的关键字

	//pair是结构体，存的键值对，
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(4, 4));//pair构造函数，构造一个匿名对象啊
	m.insert(make_pair(5, 5));//函数模板构造一个pair对象

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout<< *it << " ";//里面有俩个值，会报错

		//cout << (*it).first << " " << (*it).second << endl;
		//输出方式一
		cout << it->first << " " << it->second << endl;
		//输出方式二

		++it;
	}
	cout << endl;

}

void test_map2()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("apple", "苹果"));
	dict.insert(make_pair("shine", "闪光"));
	dict.insert(make_pair("friend", "朋友"));

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;
}

void test_map3()
{
	string str[] = { "西瓜","葡萄", "哈密瓜"," 苹果",
		"香蕉", "哈密瓜"," 苹果", "香蕉","西瓜","葡萄" };
	//第一种方法
	//map<string, int> countmap;
	//for (auto& e : str)
	//{
	//	map<string, int>::iterator ret = countmap.find(e);
	//	if (ret != countmap.end())
	//		ret->second++;
	//	else
	//		countmap.insert(make_pair(e, 1));
	//}
	//for(auto e:countmap)
	//{
	//	cout << e.first << " " << e.second << endl;
	//}
	//第二种方法
	//map<string, int> countmap;
	//for (auto& e : str)
	//{
	//	countmap[e]++;
	//}
	//for(auto e:countmap)
	//{
	//	cout << e.first << " " << e.second << endl;
	//}
	//第三种方法
	map<string, int> countmap;
	for (auto& e : str)
	{
		pair< map<string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		if (ret.second == false)
			ret.first->second++;
	}
	for (auto e : countmap)
	{  
		cout << e.first << " " << e.second << endl;
	}

}

int main()
{
	//test_map1();
	//test_map2();
	test_map3();

	return 0;
}