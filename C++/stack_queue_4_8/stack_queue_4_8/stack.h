#pragma once
#include<vector>

namespace zjl
{
	template<class T ,class Container>
	class stack
	{
	public:
		void push(const T& x){
			_con.push_back(x);
		}
		void pop(){
			_con.pop_back();
		}
		size_t Size(){
			return _con.size();
		}
		bool empty(){
			return _con.empty();
		}
		T& top() {
			return _con.back();
		}
	private:
		Container _con;
	};

	void test_stack1()
	{
		stack<int, vector<int>> s;
		s.push(1);
		s.push(3);
		s.push(3);
		s.push(4);

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}