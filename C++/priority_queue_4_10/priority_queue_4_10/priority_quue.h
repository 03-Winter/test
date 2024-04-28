#pragma once
#include<vector>

namespace zjl
{

	//仿函数
	//仿函数（Functor）是在C++编程中的一种概念，
	// 它是一种特殊类型的对象，设计成能够像普通函数那样被调用。
	//具体来说，仿函数是一个类或结构体，其核心特征在于它重载了调用运算符（operator()）

	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2) { return x1 < x2; }
	};

	template<class T>
	struct greater
	{
		bool  operator()(const T& x1, const T& x2) { return x1 > x2; }
	};



	template<class T, class Container = vector<int>,class Compare=greater<int>>
	class priority_queue
	{
	public:

		void Adjustup(int root)
		{
			int child = root;
			int parent = (child - 1) / 2;
			Compare com;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if (com(_con[parent] ,_con[child]) )
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			Adjustup(_con.size() - 1);
		}
		//void insert(const T& x);

		void Adjustdown(int root)
		{
			int parent = root;
			int child = parent * 2 + 1;
			Compare com;

			while (child < _con.size())
			{
				if( child+1<_con.size() && com(_con[child] , _con[child + 1]))
				{
					//parent += 1;
					++child;
				}
				if (com(_con[parent],_con[child]) )
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjustdown(0);
		}
		T& top()
		{
			return _con[0];
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};

	void test_priority_queue()
	{
		priority_queue<int> pq;

		pq.push(4);
		pq.push(2);
		pq.push(6);
		pq.push(9);
		pq.push(1);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}