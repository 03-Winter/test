#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<assert.h>
using namespace std;

#include<queue>
#include<stack>

//void test_stack1()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//
//	//stack没有迭代器
//	//stack<int>::iterator si = s.begin();
//
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		s.pop();
//	}
//	cout << endl;
//}


//void test_queue1()
//{
//	queue<int> q;
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}


#include"stack.h"
#include"queue.h"
#include<deque>

void test_deque1()
{
	deque<int> d;
	d.push_back(98);
	d.push_back(96);
	d.push_back(94);
	d.push_back(92);
	d.push_back(90);

	//deque<int>::iterator di = d.begin();
	//while (di != d.end())
	//{
	//	cout << *di << " ";
	//	++di;
	//}
	//cout << endl;

	for (auto e : d)
	{
		cout << e << endl;
	}

	//for(size_t i=0;i<d.size();++i)
	//{
	//	cout << d[i] << " ";
	//}
	//cout << endl;
}
//deque集合了list 和vector的优点
// 头尾的插入和删除效率比较高
//但是也存在缺点
//排序时间复杂度大
void test_deque2()
{
	deque<int> d;
	vector<int> v;
	int n = 100000;
	srand(time(0));
	while (--n)
	{
		int x = rand();
		d.push_back(x);
		v.push_back(x);
	}
	size_t begin1 = clock();
	sort(d.begin(),d.end());
	size_t end1 = clock();

	size_t begin2 = clock();
	sort(v.begin(),v.end());
	size_t end2 = clock();

	cout << end1 - begin1 << endl;//594
	cout << end2 - begin2 << endl;//289

	//排序时间长比vector大三倍
}




int main()
{
	//test_stack1();
	//test_queue1();

	//zjl::test_stack1();
	//zjl::test_queue1();
	//test_deque1();
	test_deque2();
	return 0;
}



