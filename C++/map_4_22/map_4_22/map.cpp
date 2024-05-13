#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<map>
#include<string>
using namespace std;

void test_map1()
{
	map<int,int> m;
	//m.insert()
	//����ͨ���ؼ����ҵ�valueֵ�����Բ�����һ���Ĺؼ���

	//pair�ǽṹ�壬��ļ�ֵ�ԣ�
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(4, 4));//pair���캯��������һ����������
	m.insert(make_pair(5, 5));//����ģ�幹��һ��pair����

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout<< *it << " ";//����������ֵ���ᱨ��

		//cout << (*it).first << " " << (*it).second << endl;
		//�����ʽһ
		cout << it->first << " " << it->second << endl;
		//�����ʽ��

		++it;
	}
	cout << endl;

}

void test_map2()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("apple", "ƻ��"));
	dict.insert(make_pair("shine", "����"));
	dict.insert(make_pair("friend", "����"));

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
	string str[] = { "����","����", "���ܹ�"," ƻ��",
		"�㽶", "���ܹ�"," ƻ��", "�㽶","����","����" };
	//��һ�ַ���
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
	//�ڶ��ַ���
	//map<string, int> countmap;
	//for (auto& e : str)
	//{
	//	countmap[e]++;
	//}
	//for(auto e:countmap)
	//{
	//	cout << e.first << " " << e.second << endl;
	//}
	//�����ַ���
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