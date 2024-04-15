#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#include"string.h"



//void teststring1() {
//	string s1("hello.jl");
	//s1.insert()

	//获取字符数组首地址，用C字符串的形式遍历
	//const char* str = s1.c_str();
	//while (*str)
	//{
	//	cout << *str << " ";
	//	++str;
	//}
	//cout << endl;

	//cout << s1.c_str() << endl;


	//string s2("book.txt");
	//string s3("mate.c");

	//size_t pos1 = s1.find(".");
	//if (pos1 != string::npos)
	//	cout << s1.substr(pos1) << endl;
	////取子串substr,不传参，默认从首地址开始读，传参数后，从此参数开始取
	//size_t pos2 = s2.find(".");
	//if (pos2 != string::npos)	cout << s2.substr(pos2) << endl;

	//size_t pos3= s3.find(".");
	//if (pos3 != string::npos)	cout << s3.substr(pos3) << endl;



//}


//分离字符串
//void split_str()
//{
//
//	string url("https://leetcode.cn/problems/");
//
//	size_t pos1 = url.find(":");
//	if (pos1 != string::npos)
//	{
//		cout << url.substr(0, pos1) << endl;
//	}
//	size_t pos2 = url.find("/", pos1 + 3);
//	if (pos2 != string::npos) {
//		cout << url.substr(pos1 + 3, pos2 - pos1 - 3);
//	}
//}



//void test_string2()
//{
//	string w1("hello");
//	string w2 = w1;

//	w1.push_back('s');
//	w1.push_back('k');
//	w1.push_back('i');
//	w1.push_back('n');

//	w1.append("start");

//	w1.insert(2, 'g');

//	//string::interator it = w1.begin();

//	//while (it != w1.end())
//	//{
//	//	cout << *it;
//	//	++it;

//	//}
//	//cout << endl;

//	//范围for是由迭代器支持的
//	for (auto e : w1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test_string1()
//{

//	//zjl 为常性，只读类型
//	string s1("hello");
//	string s2 = s1;
//	for (size_t i=0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	for (size_t i=0; i < s2.size(); ++i)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;

//	//c_str函数：获取一个
//	cout << s1.c_str() << endl;

//}


int main()
{
	//teststring1();
	zjl::test_string3();
	return 0;
}