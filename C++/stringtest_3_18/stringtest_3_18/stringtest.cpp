#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#include"string.h"



//void teststring1() {
//	string s1("hello.jl");
	//s1.insert()

	//��ȡ�ַ������׵�ַ����C�ַ�������ʽ����
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
	////ȡ�Ӵ�substr,�����Σ�Ĭ�ϴ��׵�ַ��ʼ�����������󣬴Ӵ˲�����ʼȡ
	//size_t pos2 = s2.find(".");
	//if (pos2 != string::npos)	cout << s2.substr(pos2) << endl;

	//size_t pos3= s3.find(".");
	//if (pos3 != string::npos)	cout << s3.substr(pos3) << endl;



//}


//�����ַ���
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

//	//��Χfor���ɵ�����֧�ֵ�
//	for (auto e : w1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test_string1()
//{

//	//zjl Ϊ���ԣ�ֻ������
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

//	//c_str��������ȡһ��
//	cout << s1.c_str() << endl;

//}


int main()
{
	//teststring1();
	zjl::test_string3();
	return 0;
}