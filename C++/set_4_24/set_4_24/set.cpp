#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
#include<set>


void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(6);
	s.insert(1);
	s.insert(9);

	set<int>::iterator si = s.begin();
	while (si != s.end())
	{
		cout << *si << " ";
		++si;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//set<int> copy(s);
	//for (auto e : copy)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	set<int>::iterator it = s.find(9);//O（logn）
	//set<int>::iterator it = find(s.begin(),s.end(),9);//O（n）
	if (it != s.end())
	{
		s.erase(it);
	}
	s.erase(1);
	s.erase(10);//当set里面没有时，就什么也不做
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	test_set1();
	return 0;
}