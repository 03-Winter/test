#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<thread>
using namespace std;
#include"SmartPtr.h"

int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}

void f1()
{
	int* p = new int;
	SmartPtr<int> s(p);		//是一种利用对象生命周期来控制程序资源
	//采用智能指针可以很好避免内存泄露问题
	cout << div() << endl;
}


int x()
{
	//try
	//{
	//	f1();
	//}
	//catch (exception& e)
	//{
	//	cout << e.what() << endl;
	//}

	return 0;
}

int main()
{
	zjl::share_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n = 10;

	std::thread t1([&]()
		{
			for (size_t i = 0; i < n; i++)
			{
				zjl::share_ptr<int> sp1(sp);
			}
		});
	std::thread t2([&]()
		{
			for (size_t i = 0; i < n; i++)
			{
				zjl::share_ptr<int> sp2(sp);
			}
		});

	t1.join();
	t2.join();

	return 0;
}

