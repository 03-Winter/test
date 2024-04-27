#pragma once
#include<list>
namespace zjl
{
	template<class T,class Container>
	class queue
	{
	public:
		void push(const T& x) {
			_con.push_back(x);
		}
		void pop() {
			_con.pop_front();
		}
		size_t Size(){
			return _con.size();
		}
		bool empty() {
			return _con.empty();
		}
		T& front() {
			return _con.front();
		}
		T& back() {
			return _con.back();
		}
	private:
		Container _con;
	};

	void test_queue1() 
	{
		queue<int, list<int>> q;
		q.push(12);
		q.push(13);
		q.push(14);
		q.push(15);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}