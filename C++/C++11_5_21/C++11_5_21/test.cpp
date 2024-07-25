#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<string>
#include<algorithm>
#include<thread>
#include<mutex>
#include<atomic>
#include<vector>
#include<condition_variable>
using namespace std;
#include"C++11.h"

void test_lambder()
{
	int  a = 2, b = 3;
	auto add = [](int x, int y)->int {return x + y; };

	auto as = [a, b]()->int {return a + b; };
	add(a , b);

}

//atomic<int> x = 0;//方法一：使用原子++，避免线程冲突
//mutex m;
//
//void test_thread(size_t length)
//{
//	m.lock();//方法二：加锁，一个线程跑完，再跑另一个线程
//
//	for (size_t i = 0; i < length; i++)
//	{
//		++x;
//	}
//	
//	m.unlock();
//}
int test()
{
	//Goods f[] = { {"语文",87},{"数学",76},{"英语",123} };

	////sort(f,f+sizeof(f)/sizeof(f[0]),Compare());

	////lambder
	//sort(f, f + sizeof(f) / sizeof(f[0]), [](const Goods& g1, const Goods& g2)->bool {return g1._price < g2._price; });

	//for (auto& e : f)
	//{
	//	cout << e._name << " " << e._price;
	//}
	//cout<<endl;
	atomic<int> x = 0;
	auto add = [&x](int n) {
		for (size_t i = 0; i < n; i++)
		{
			++x;
		}
	};

	thread t(add,1000000);
	thread r(add,1000000);

	t.join();
	r.join();
	cout << x << endl;
	return 0;
}

//用俩个线程打印奇偶数
//void f()
//{
//	int n = 100;
//	mutex m1, m2;
//	condition_variable cv1, cv2;
//	thread t1([&]()
//		{
//			for (size_t i = 0; i < n; i += 2)
//			{
//				cout << this_thread::get_id << ":" << i << endl;
//				cv2.notify_one();
//				cv1.wait(unique_lock<mutex>(m1));
//			}
//		});
//		
//	thread t2([&]()
//		{
//			for (size_t i = 0; i < n; i += 2)
//			{
//				cv2.wait(unique_lock<mutex>(m2));
//
//				cout << this_thread::get_id << ":" << i << endl;
//				cv2.notify_one();
//			}
//		});
//
//	t1.join();
//	t2.join();
//}

int y()
{
	//atomic<int> x = 0;
	//int m, n;
	////对m个线程的x加n次
	//cin >> m >> n;
	//vector<thread> v;
	//for (size_t i = 0; i < m; ++i)
	//{
	//	v.push_back(thread([&x](int count) {
	//		for (size_t i = 0; i < count; i++)
	//		{
	//			++x;
	//		}
	//		}, n));
	//}

	//for (auto& e : v)
	//{
	//	cout << e.get_id() << "join" << endl;
	//	e.join();
	//}

	//cout << x << endl;
	return 0; 
}

int main()
{

	return 0; 
}