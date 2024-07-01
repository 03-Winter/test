#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;
#include<time.h>

//void test_set()
//{
//	unordered_set<int> us;
//	us.insert(3);
//	us.insert(6);
//	us.insert(4);
//	us.insert(1);
//	us.insert(38);
//
//	unordered_set<int>::iterator uit = us.begin();
//	while (uit != us.end())
//	{
//		cout << *uit << " ";
//		++uit;
//	}
//	cout << endl;
//
//
//}
//
//void test_op()
//{
//	unordered_set<int> us;
//	set <int> s;
//	const int n = 100000;
//	vector<int> v;
//
//	srand(time(0));
//	for (size_t i = 0; i < n; ++i)
//	{
//		v.push_back(rand());
//	}
//
//	size_t begin1 = clock();
//	for (auto& e : v)
//	{
//		us.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "un_set:  " << end1 - begin1 << endl;
//
//	size_t begin2 = clock();
//	for (auto& e : v)
//	{
//		s.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "set:  " << end2 - begin2 << endl;
//
//}
#include"HashTable.h"

int main()
{

	//test_set();
	//test_op();
	//testHash();
	OPEN_HASH::testHash2();

	return 0;
}